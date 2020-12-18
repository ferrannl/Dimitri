#include "TryAgainCommand.h"

Game::Commands::TryAgainCommand::TryAgainCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller)
{
}

void Game::Commands::TryAgainCommand::execute(int param)
{
	param = _main_controller->get_settings()->get_current_level();
	auto l_mgr = _main_controller->get_level_manager();
	auto w_ctrl = _main_controller->get_window_controller();
	auto l_ctrl = _main_controller->get_level_controller();
	auto i_ctrl = _main_controller->get_input_controller();
	auto a_ctrl = _main_controller->get_audio_controller();
	auto h_ctrl = _main_controller->get_home_controller();
	auto save_game_ctrl = _main_controller->get_save_game_controller();
	auto cheats_ctrl = _main_controller->get_cheats_controller();
	
	w_ctrl->clear_views();

	if (l_ctrl->get_level()) {
		l_ctrl->stop();
		l_ctrl->clear_level();
	}

	auto level_ctrl = std::make_shared<Game::Controllers::LevelController>(w_ctrl, a_ctrl);
	i_ctrl->unsubscribe(_main_controller->get_level_controller());
	_main_controller->set_level_controller(level_ctrl);
	_main_controller->get_level_manager()->set_level_controller(level_ctrl);

	if (param <= 0) {
		level_ctrl->setup_level("tutorial");
	}
	else {
		level_ctrl->setup_level("level" + std::to_string(param));
	}
	level_ctrl->load_buttons();
	w_ctrl->set_textures(level_ctrl->get_textures(Enums::LevelStateEnum::ACTIVE), Enums::ViewEnum::LEVEL);
	w_ctrl->add_textures(level_ctrl->get_level()->get_player()->get_extra_textures(), Enums::ViewEnum::HUD);
	w_ctrl->add_textures(level_ctrl->get_textures(Enums::LevelStateEnum::PAUSED), Enums::ViewEnum::PAUSE_LEVEL);
	w_ctrl->add_textures(level_ctrl->get_textures(Enums::LevelStateEnum::GAME_OVER), Enums::ViewEnum::GAME_OVER_LEVEL);
	w_ctrl->add_textures(level_ctrl->get_textures(Enums::LevelStateEnum::WIN), Enums::ViewEnum::WIN_LEVEL);
	level_ctrl->update_cheats(cheats_ctrl->get_cheat_settings());
	a_ctrl->pause_audio("homescreen1");
	l_mgr->load_level();
}
