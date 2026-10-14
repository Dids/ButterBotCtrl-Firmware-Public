#ifndef BUTTERBOTCTRL_FIRMWARE_LEDBREATHEWINDOW_H
#define BUTTERBOTCTRL_FIRMWARE_LEDBREATHEWINDOW_H

#include <LV_Interface/LVGIF.h>
#include "Components/HomeWindow.h"

class LEDBreatheWindow : public HomeWindow {
public:
	/**
	 * Window that shows BB LEDBreathe action
	 * @param parent parent LVGL object
	 * @param params data for LEDBreathe action
	 */
	LEDBreatheWindow(lv_obj_t* parent, const LEDBreatheData* params);

	void onDismiss() override;

private:
	static constexpr const char* TITLE = "LED hengittää";
	static constexpr const char* Sentence = "Rauhaprotokolla käynnissä";

	LVGIF* gif = nullptr;

	void buildUI(LEDBreatheData data);
};


#endif //BUTTERBOTCTRL_FIRMWARE_LEDBREATHEWINDOW_H
