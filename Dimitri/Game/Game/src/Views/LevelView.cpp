#include "LevelView.h"
using namespace Game;

Views::LevelView::LevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : Views::IView(graphics_controller)
{
	is_open = false;
}

void Views::LevelView::init_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures)
{
	_textures = textures;
}
