#include "HomeController.h"
#include "../Mediators/CommandMediator.h"
#include <experimental/filesystem>
#include <src/Advertisement/Advertisement.h>
#include <iostream>
namespace fs = std::experimental::filesystem::v1;

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
				std::make_shared<Graphics::Models::Sprite>(_scene_width / 2 - (w / 2), _scene_height / 4 * 3 - (150 + 75 * i), 2, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
				std::make_shared<Graphics::Models::Text>(b.first, color, _scene_width / 2 - (w_text / 2), _scene_height / 4 * 3 - (150 + 75 * i), 3, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
			};
			add_button(Models::Button{ _scene_width / 2 - (w / 2), _scene_height / 4.0f * 3 - (150 + 75 * i), h, w, t, b.second });
			i++;
		}

		// advertisement
		std::vector<std::string> images{};
		Utility::Advertisement::advertisement ad{};
		ad.http_download_images(Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement.zip" }, Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement" });

		path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement" };
		for (auto& entry : fs::directory_iterator(path))
		{
			images.push_back(entry.path().string());
		}
		w = _scene_width / 2.0f;
		h = 200;

		srand((unsigned int)time(NULL));
		int random_int = rand();
		int image_size = images.size();
		int randNum = (random_int % image_size);
		std::string _image_path = images[randNum];
		t = {
				std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, _image_path, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }, true),
		};

		add_button(Models::Button{ w - (_scene_width / 4), _scene_height / 4.0f * 3 - (150 + 75 * i), 200, w, t, Enums::ButtonEnum::ADVERTISEMENT });
		//_buttons.push_back(std::make_shared<Models::Buttons::AdvertisementButton>((_scene_width / 2) - (_scene_width / 4), 20, 1, 200, _scene_width / 2, Game::Enums::DirectionEnum::NONE, _scene_height, level_manager->get_window_controller(), Graphics::Models::Center{ 0,0 }));
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
