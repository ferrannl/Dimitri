#include "AdvertisementButton.h"
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem::v1;

Game::Models::Buttons::AdvertisementButton::AdvertisementButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height) : Game::Models::Button(x, y, z, height, width, state, scene_height)
{
	images = {};
	ad = {};
	ad.http_download_images(Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement.zip" }, Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement" });

	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement" };
	for (const auto& entry : fs::directory_iterator(path))
	{
		images.push_back(entry.path().string());
	}
	_width = width;
	_height = height;
	initialize_textures();
}

void Game::Models::Buttons::AdvertisementButton::initialize_textures()
{
	//int random_int = rand() % 100;
	int random = rand();
	int random_int = rand() % images.size();
	std::string _image_path = images[random_int];
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, _height, _width, 0, _image_path, Graphics::Enums::FlipEnum::NONE, true));
	get_texture()->set_visible(true);
}

void Game::Models::Buttons::AdvertisementButton::interact()
{
	system(std::string("start " + _url).c_str());
}