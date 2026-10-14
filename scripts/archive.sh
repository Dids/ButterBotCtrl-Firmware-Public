#!/bin/bash

# .sz binary format
#
#  [ 4 bytes ]   file count (little-endian uint32)
#    [ N bytes ]   filename\0  (null-terminated string)
#    [ 4 bytes ]   file size   (little-endian uint32)
#    ... repeated for each file ...
#  [ 1 byte  ]   \0           (terminates directory)
#  [ ? bytes ]   raw file data (file 1 bytes, file 2 bytes, ...)

set -e

compress=true
for arg in "$@"; do
  if [[ $arg == "--nocompress" ]]; then
    compress=false
  fi
done

for arch in spiffs_archives/*; do
  archiveName=$(basename $arch)

  data="spiffs_image/$archiveName.sz"
  rm -f $data

  # Same order as a glibc en_US glob (punctuation ignored, case-folded), so the output
  # matches archives built on Linux byte for byte. Works with macOS bash 3.2.
  files=()
  while IFS= read -r file; do
    files+=("$file")
  done < <(find "$arch" -type f | awk '{k=tolower($0); gsub(/[^0-9a-z]/,"",k); print k "\t" $0}' | LC_ALL=C sort -t "$(printf '\t')" -k1,1 -k2,2 | cut -f2)

  count=${#files[@]}

  printf "0: %.8x" $count | sed -E 's/0: (..)(..)(..)(..)/0: \4\3\2\1/' | xxd -r -g0 >> $data

  printf "Writing to file archive: $archiveName.sz\n"
  for file in "${files[@]}"; do
    if [[ -d $file ]]; then continue; fi

    name=$(sed 's/spiffs_archives\/[a-zA-Z0-9_-]*//' <<< $file)
    size=$(wc -c < "$file" | tr -d ' ')

    printf "Writing file: $name\n"

    printf "%s\0" $name >> $data
    printf "0: %.8x" $size | sed -E 's/0: (..)(..)(..)(..)/0: \4\3\2\1/' | xxd -r -g0 >> $data
  done
  printf "Done writing file archive: $archiveName.sz\n"

  printf "\0" >> $data

  for file in "${files[@]}"; do
    if [[ -d "$file" ]]; then continue; fi

    cat $file >> $data
  done

  if [[ $compress == true ]]; then
    heatshrink -e -w 14 -l 7 "$data" "$data.hs"
    rm "$data"
  fi
done