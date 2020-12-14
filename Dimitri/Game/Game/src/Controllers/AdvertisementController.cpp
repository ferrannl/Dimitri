#include "AdvertisementController.h"
#include <experimental/filesystem>
#include <src/Advertisement/Advertisement.h>
#include <iostream>
#include <src/Models/Sprite.h>
#include <src/Helpers/BasePathHelper.h>
namespace fs = std::experimental::filesystem::v1;
using namespace Game;

Game::Controllers::AdvertisementController::AdvertisementController(int sceneheight, int scenewidth) :
	_scene_height{ sceneheight }, _scene_width{ scenewidth }
{
	load_advertisements();
}

void Game::Controllers::AdvertisementController::load_advertisements()
{
	float w = _scene_width / 3.0f;
	float h = _scene_height / 3.0f;

	Utility::Advertisement::advertisement ad{};
	ad.http_download_images(Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement.zip" }, Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement" });
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/advertisement" };
	for (auto& entry : fs::directory_iterator(path))
	{
		_advertisements.push_back(std::make_shared<Graphics::Models::Sprite>(20, 20, 1, h, w, 0, entry.path().string(), Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }, true));
	}
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::AdvertisementController::get_textures() const
{
	return _advertisements;
}