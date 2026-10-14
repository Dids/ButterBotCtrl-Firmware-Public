#ifndef BUTTERBOTCTRL_FIRMWARE_PICKUPWINDOW_H
#define BUTTERBOTCTRL_FIRMWARE_PICKUPWINDOW_H

#include "Components/HomeWindow.h"

class PickUpWindow : public HomeWindow {
public:
	/**
	 * Window that shows BB PickUp action
	 * @param parent parent LVGL object
	 * @param params data for PickUp action
	 */
	PickUpWindow(lv_obj_t* parent, const PickUpData* params);

private:
	lv_obj_t* img;
	lv_obj_t* sentenceLabel;

	static constexpr const char* TITLE = "Nostettu";
	static constexpr const char* Sentence = "Irti, kuolevainen";

	void buildUI(PickUpData data);
};

#endif //BUTTERBOTCTRL_FIRMWARE_PICKUPWINDOW_H
