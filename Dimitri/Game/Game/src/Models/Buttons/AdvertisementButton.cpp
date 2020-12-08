#include "AdvertisementButton.h"
#include "../../Mediators/CommandMediator.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem::v1;

namespace Game {
	namespace Models {
		Buttons::AdvertisementButton::AdvertisementButton(int x, int y, int z, int height, int width, Enums::DirectionEnum state, int scene_height, std::shared_ptr<Game::Controllers::WindowController> window_controller, Graphics::Models::Center center) :
			Button(x, y, z, height, width, state, scene_height, center, "AdvertisementButton", Game::Enums::ButtonEnum::ADVERTISEMENT) 
		{
			images = {};
			ad = {};
			_window_controller = window_controller;
			ad.http_download_images(Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement.zip" }, Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement" });

			std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement" };
			for (const auto& entry : fs::directory_iterator(path))
			{
				images.push_back(entry.path().string());
			}
			_height = height;
			_width = width;
			initialize_textures();
		}

		void Buttons::AdvertisementButton::initialize_textures()
		{
			_animatestate = Enums::AnimateEnum::IDLE1;

			if (get_all_textures().size() > 0)
			{
				get_texture()->set_visible(false);
				_window_controller->get_graphics_controller()->remove_texture(get_texture());
				clear_textures();
			}

			srand((unsigned int)time(NULL));
			int random_int = rand();
			int image_size = images.size();
			int randNum = (random_int % image_size);
			std::string _image_path = images[randNum];
			add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, _image_path, Graphics::Enums::FlipEnum::NONE, true, _center));
			get_texture()->set_visible(true);
		}
		
		void Buttons::AdvertisementButton::interact(Controllers::LevelController* ctrl)
		{
		}
	}
}
