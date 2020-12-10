#include "HomeController.h"
#include "../Mediators/CommandMediator.h"

namespace Game {
	Controllers::HomeController::HomeController(int sceneheight, int scenewidth, std::shared_ptr<Controllers::AudioController> audio_controller) :
		Mediators::BaseComponent("HomeController"), _scene_height{ sceneheight }, _scene_width{ scenewidth }, _audio_controller{ audio_controller }
	{
		_audio_controller->add_music("homescreen1", "/assets/audio/homescreen.wav");
		_audio_controller->play_audio("homescreen1");
		load_buttons();
	}

	void Controllers::HomeController::load_buttons()
	{
		Graphics::Models::Color color = { 255, 255, 255 };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		std::vector<std::pair<std::string, Enums::ButtonEnum>> button_map{ { "Play", Enums::ButtonEnum::START },{ "Help", Enums::ButtonEnum::HELP },{ "Credits", Enums::ButtonEnum::CREDITS }, { "Exit", Enums::ButtonEnum::EXIT } };
		std::vector<std::shared_ptr<Graphics::Models::Texture>> t;
		int i = 0;
		float w = 150;
		float h = 50;
		for (auto b : button_map) {
			float w_text = b.first.length() * 15;
			t = {
				std::make_shared<Graphics::Models::Sprite>(_scene_width / 2 - (w / 2), _scene_height / 4 * 3 - (120 + 70 * i), 2, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
				std::make_shared<Graphics::Models::Text>(b.first, color, _scene_width / 2 - (w_text / 2), _scene_height / 4 * 3 - (120 + 70 * i), 3, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
			};
			add_button(Models::Button{ _scene_width / 2 - (w / 2), _scene_height / 4.0f * 3 - (120 + 70 * i), h, w, t, b.second });
			i++;
		}
	}

	void Controllers::HomeController::update(const Events::InputEvent& object)
	{
		Mediators::CommandMediator::instance()->notify(*this, object);
	}

	std::vector<std::shared_ptr<Graphics::Models::Texture>> Controllers::HomeController::get_textures() const
	{
		std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
		for (auto& b : get_buttons()) {
			for (auto& t : b->get_textures()) {
				button_textures.push_back(t);
			}
		}
		return button_textures;
	}
}
