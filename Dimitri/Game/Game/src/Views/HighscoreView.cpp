#include "HighscoreView.h"

namespace Game {
	Views::HighscoreView::HighscoreView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		_record_times = {};
		init_textures();
	}


	void Views::HighscoreView::init_textures()
	{
		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height = _graphics_controller.get()->get_window().get()->get_height();
		std::string bg_path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/records.png" };
		Graphics::Models::Color color = { 255, 255, 255 };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/TravelingTypewriter.ttf" };

		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 0, window_height, window_width, 0, bg_path, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }));

		int place_margin = 0;

		//show all record times
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Plaats", color, window_width / 4 + 100, (window_height - 170), 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Tijden", color, window_width / 4 + 300, (window_height - 170), 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }));
		for (int i = 1; i <= 10; i++) {
			std::string place = std::to_string(i);
			_textures.push_back(std::make_shared<Graphics::Models::Text>(place, color, window_width / 4 + 100, (window_height - 225) - place_margin, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }));
			place_margin = place_margin + 48;
		}
		place_margin = 0;
		for (int i = 0; i < _record_times.size(); i++) {
			uint32_t record = _record_times[i];
			std::string time = std::to_string(record);
			_textures.push_back(std::make_shared<Graphics::Models::Text>(time, color, window_width / 4 + 300, (window_height - 225) - place_margin, 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }));
			place_margin = place_margin + 48;
		}

	}

	bool Views::HighscoreView::is_visible() const
	{
		return true;
	}
	void Views::HighscoreView::add_record(uint32_t record)
	{
		_record_times.push_back(record);
		init_textures();
	}
}



