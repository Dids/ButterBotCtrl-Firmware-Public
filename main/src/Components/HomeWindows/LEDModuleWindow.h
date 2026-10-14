#ifndef BUTTERBOTCTRL_FIRMWARE_LEDMODULEWINDOW_H
#define BUTTERBOTCTRL_FIRMWARE_LEDMODULEWINDOW_H

#include "Components/HomeWindow.h"

class LEDModuleWindow : public HomeWindow {
public:
	/**
	 * Window that shows BB LEDModule action
	 * @param parent parent LVGL object
	 * @param params data for LEDModule action
	 */
	LEDModuleWindow(lv_obj_t* parent, const LEDModuleData* params);

private:
	static constexpr const char* TITLE = "LED-moduuli";
	static constexpr const char* Sentence = "Valovoimat saatu!";

	void buildUI(LEDModuleData data);
};


#endif //BUTTERBOTCTRL_FIRMWARE_LEDMODULEWINDOW_H