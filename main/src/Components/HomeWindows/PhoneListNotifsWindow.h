#ifndef BUTTERBOTCTRL_FIRMWARE_PHONELISTNOTIFSWINDOW_H
#define BUTTERBOTCTRL_FIRMWARE_PHONELISTNOTIFSWINDOW_H

#include "Components/HomeWindow.h"
#include "Themes.hpp"

class PhoneListNotifsWindow : public HomeWindow {
public:
	/**
	 * Window for the phone notification-reading flow. Phase-driven: a single window
	 * instance is updated via onData() as the device advances through the phases
	 * (count → ask → read → done). The backing data carries no message content or
	 * category, only counts, so only icon + count + sentence are shown.
	 * @param parent parent LVGL object
	 * @param params current notification flow state
	 */
	PhoneListNotifsWindow(lv_obj_t* parent, const PhoneListNotifsData* params);

	void onData(const BBData* data) override;

private:
	static constexpr const char* TITLE = "Ilmoitukset";
	static constexpr const char* NoNotifsSentence = "Ei yhtikäs mitään uutta";
	static constexpr const char* CountSentence = "Ladataan someahdistusta";
	static constexpr const char* ReadingSentence = "Luetaan...";
	static constexpr const char* DoneSentence = "Kaikki luettu";

	void buildUI(const PhoneListNotifsData& data);

	/* Adds an icon + numeric value row to the inner content */
	void addIconNumberRow(Asset icon, uint8_t number);

	/* Adds a wrapped, centered sentence label to the inner content */
	void addSentence(const char* sentence);

	/* Adds a standalone icon to the inner content */
	void addIcon(Asset icon);
};

#endif //BUTTERBOTCTRL_FIRMWARE_PHONELISTNOTIFSWINDOW_H
