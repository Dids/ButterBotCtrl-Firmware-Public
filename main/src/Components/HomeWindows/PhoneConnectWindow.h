#ifndef BUTTERBOTCTRL_FIRMWARE_PHONECONNECTWINDOW_H
#define BUTTERBOTCTRL_FIRMWARE_PHONECONNECTWINDOW_H

#include "Components/HomeWindow.h"

class PhoneConnectWindow : public HomeWindow {
public:
	/**
	 * Window shown when the phone connection state changes.
	 * @param parent parent LVGL object
	 * @param params data carrying the connected flag
	 */
	PhoneConnectWindow(lv_obj_t* parent, const PhoneConnData* params);

	void onData(const BBData* data) override;

private:
	static constexpr const char* TITLE = "Puhelin";
	static constexpr const char* ConnectedSentence = "Puhelinyhteys muodostettu";
	static constexpr const char* DisconnectedSentence = "Puhelin? Mikä se?";

	void buildUI(PhoneConnData data);
};

#endif //BUTTERBOTCTRL_FIRMWARE_PHONECONNECTWINDOW_H
