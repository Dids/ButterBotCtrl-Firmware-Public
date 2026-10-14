#ifndef BUTTERBOTCTRL_FIRMWARE_LEDSLOWERWINDOW_H
#define BUTTERBOTCTRL_FIRMWARE_LEDSLOWERWINDOW_H

#include <LV_Interface/LVGIF.h>
#include "Components/HomeWindow.h"

class LEDSlowerWindow : public HomeWindow {
public:
	/**
	 * Window that shows BB LEDSlower action
	 * @param parent parent LVGL object
	 * @param params data for LEDSlower action
	 */
	LEDSlowerWindow(lv_obj_t* parent, const LEDSlowerData* params);

	void onDismiss() override;

private:
	static constexpr const char* TITLE = "LED hitaammin";
	static constexpr const char* Sentence = "Rauhallisesti, veli";

	LVGIF* gif = nullptr;

	void buildUI(LEDSlowerData data);
};


#endif //BUTTERBOTCTRL_FIRMWARE_LEDSLOWERWINDOW_H