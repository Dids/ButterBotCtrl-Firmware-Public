#ifndef BUTTERBOTCTRL_FIRMWARE_LEDTURNONWINDOW_H
#define BUTTERBOTCTRL_FIRMWARE_LEDTURNONWINDOW_H

#include "Components/HomeWindow.h"

class LEDTurnOnWindow : public HomeWindow {
public:
	/**
	 * Window that shows BB LEDTurnOn action
	 * @param parent parent LVGL object
	 * @param params data for LEDTurnOn action
	 */
	LEDTurnOnWindow(lv_obj_t* parent, const LEDTurnOnData* params);

private:
	static constexpr const char* TITLE = "LED päälle";
	static constexpr const char* Sentence = "Päällä. Pelkää loistettani";

	void buildUI(LEDTurnOnData data);
};


#endif //BUTTERBOTCTRL_FIRMWARE_LEDTURNONWINDOW_H
