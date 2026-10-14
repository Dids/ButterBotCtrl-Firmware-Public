#ifndef BUTTERBOTCTRL_FIRMWARE_CANTMOVEWINDOW_H
#define BUTTERBOTCTRL_FIRMWARE_CANTMOVEWINDOW_H

#include "Components/HomeWindow.h"

class CantMoveWindow : public HomeWindow {
public:
	CantMoveWindow(lv_obj_t* parent, const CantMoveData* params);

private:
	static constexpr const char* TITLE = "Ei voi liikkua";
	static constexpr const char* SentenceCharging = "En voi liikkua. Lataan";
	static constexpr const char* SentenceUnstable = "En voi liikkua. Horjun";

	void buildUI(CantMoveData data);
};

#endif //BUTTERBOTCTRL_FIRMWARE_CANTMOVEWINDOW_H
