#include "AdvertisementButton.h"

Game::Models::Buttons::AdvertisementButton::AdvertisementButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, std::string url, std::string image_path) : Game::Models::Button(x, y, z, height, width, state, scene_height)
{
	_url = url;
	_image_path = image_path;
	_width = width;
	_height = height;
	initialize_textures();
}

void Game::Models::Buttons::AdvertisementButton::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, _height, _width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/"+_image_path+".png" }, Graphics::Enums::FlipEnum::NONE, true));
	get_texture()->set_visible(true);
}

void Game::Models::Buttons::AdvertisementButton::interact()
{
	system(std::string("start " + _url).c_str());
}