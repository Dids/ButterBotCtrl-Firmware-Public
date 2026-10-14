#ifndef BUTTERBOTCTRL_FIRMWARE_SCENARIOMAPPING_H
#define BUTTERBOTCTRL_FIRMWARE_SCENARIOMAPPING_H

#include <utility>
#include <BBData.h>

struct Action {
	BB::Action::Scenario scenario;
	ScenarioData data;
};

// Declaration order defines the display order in the action list
constexpr std::pair<const char*, Action> ScenarioNameMap[] = {
	{ "Fakta", { BB::Action::Scenario::Fact, {} } },
	{ "Vitsi", { BB::Action::Scenario::Joke, {} } },
	{ "Ojenna voita", { BB::Action::Scenario::PassTheButter, {} } },
	{ "Sinä ojennat voin", { BB::Action::Scenario::YouPassButter, {} } },
	{ "LED päälle", { BB::Action::Scenario::LEDTurnOn, {} } },
	{ "LED pois", { BB::Action::Scenario::LEDTurnOff, {} } },
	{ "LED-strobo", { BB::Action::Scenario::LEDStrobe, {} } },
	{ "LED hengittää", { BB::Action::Scenario::LEDBreathe, {} } },
	{ "LED nopeammin", { BB::Action::Scenario::LEDFaster, {} } },
	{ "LED hitaammin", { BB::Action::Scenario::LEDSlower, {} } },
	{ "Ilmastomoduuli", { BB::Action::Scenario::TempHumModule, {} } },
	{ "Asteikko: Celsius", { BB::Action::Scenario::TempHumScaleCelsius, {} } },
	{ "Asteikko: Fahrenheit", { BB::Action::Scenario::TempHumScaleFahrenheit, {} } },
	{ "Asteikko: Kelvin", { BB::Action::Scenario::TempHumScaleKelvin, {} } },
	{ "Nopanheitto", { BB::Action::Scenario::DiceRoll, DiceScenarioData{ DiceScenarioData::DiceType::None } } },
	{ "Heitä D4", { BB::Action::Scenario::DiceRoll, DiceScenarioData{ DiceScenarioData::DiceType::D4 } } },
	{ "Heitä D6", { BB::Action::Scenario::DiceRoll, DiceScenarioData{ DiceScenarioData::DiceType::D6 } } },
	{ "Heitä D8", { BB::Action::Scenario::DiceRoll, DiceScenarioData{ DiceScenarioData::DiceType::D8 } } },
	{ "Heitä D10", { BB::Action::Scenario::DiceRoll, DiceScenarioData{ DiceScenarioData::DiceType::D10 } } },
	{ "Heitä D12", { BB::Action::Scenario::DiceRoll, DiceScenarioData{ DiceScenarioData::DiceType::D12 } } },
	{ "Heitä D20", { BB::Action::Scenario::DiceRoll, DiceScenarioData{ DiceScenarioData::DiceType::D20 } } },
	{ "Heitä D100", { BB::Action::Scenario::DiceRoll, DiceScenarioData{ DiceScenarioData::DiceType::D100 } } },
	{ "Kaasumoduuli", { BB::Action::Scenario::GasModule, {} } },
	{ "Tunkeilijavahti PÄÄLLE", { BB::Action::Scenario::IntruderDetectionOn, {} } },
	{ "Tunkeilijavahti POIS", { BB::Action::Scenario::IntruderDetectionOff, {} } },
	{ "Taikapallo", { BB::Action::Scenario::EightBall, {} } },
	{ "Kellonaika", { BB::Action::Scenario::CurrentTime, {} } },
	{ "Mikä tämä on?", { BB::Action::Scenario::WhatsThis, {} } },
	{ "Sammuta", { BB::Action::Scenario::Shutdown, {} } },
	{ "IR-opetus", { BB::Action::Scenario::IR_train, {} } },
	{ "IR-lista", { BB::Action::Scenario::IR_list, {} } },
	{ "IR-unohdus", { BB::Action::Scenario::IR_forget, {} } },
	{ "IR: unohda kaikki", { BB::Action::Scenario::IR_forgetAll, {} } },
	{ "Puhelin: ilmoitukset", { BB::Action::Scenario::PhoneListNotifs, {} } },
	{ "Puhelin: mikä soi?", { BB::Action::Scenario::PhoneWhatsPlaying, {} } },
	{ "Puhelin: seuraava", { BB::Action::Scenario::PhoneNextSong, {} } },
	{ "Puhelin: edellinen", { BB::Action::Scenario::PhonePrevSong, {} } },
	{ "Puhelin: soita", { BB::Action::Scenario::PhonePlayMusic, {} } },
	{ "Puhelin: pysäytä", { BB::Action::Scenario::PhoneStopMusic, {} } },
	{ "Eteenpäin", { BB::Action::Scenario::VoiceControl, VoiceScenarioData{ VoiceScenarioData::Direction::Forward } } },
	{ "Taaksepäin", { BB::Action::Scenario::VoiceControl, VoiceScenarioData{ VoiceScenarioData::Direction::Backward } } },
	{ "Käänny vasemmalle", { BB::Action::Scenario::VoiceControl, VoiceScenarioData{ VoiceScenarioData::Direction::Left } } },
	{ "Käänny oikealle", { BB::Action::Scenario::VoiceControl, VoiceScenarioData{ VoiceScenarioData::Direction::Right } } },
	{ "Käänny ympäri", { BB::Action::Scenario::VoiceControl, VoiceScenarioData{ VoiceScenarioData::Direction::Rotate } } },
	{ "Kuka tämä on?", { BB::Action::Scenario::FaceDetect, FaceScenarioData{ FaceScenarioData::Phase::Detect } } },
	{ "Muista nämä kasvot", { BB::Action::Scenario::FaceDetect, FaceScenarioData{ FaceScenarioData::Phase::Remember } } },
	{ "Unohda omistaja", { BB::Action::Scenario::FaceDetectForget, FaceScenarioData{ FaceScenarioData::Phase::Forget } } },
	{ "Tanssi", { BB::Action::Scenario::Dance, {} } },
};

#endif //BUTTERBOTCTRL_FIRMWARE_SCENARIOMAPPING_H
