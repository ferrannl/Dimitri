#include "AdvertisementView.h"

namespace Game {
	Views::AdvertisementView::AdvertisementView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) :
		View(graphics_controller) {}

	void Views::AdvertisementView::open()
	{
		if (!_textures.empty()) {
			for (auto& t : _textures) {
				t->set_visible(false);
			}
			srand((unsigned int)time(NULL));
			int random_int = rand();
			int image_size = _textures.size();
			int randNum = (random_int % image_size);
			_textures[randNum]->set_visible(true);
		}
		View::open();
	}

	bool Views::AdvertisementView::is_visible() const
	{
		return true;
	}

}

