#include "../Demo/Demo.h"
Demo::Demo::Demo()
{
	_g_ctlr = std::make_shared<Graphics::Controllers::GraphicsController>();
	_a_ctlr = std::make_shared<Audio::Controllers::AudioController>();
	_w_ctlr = std::make_shared<PhysicsCollision::Controllers::WorldController>();
	_i_ctlr = std::make_shared<Input::Controllers::InputController>();
}

void Demo::Demo::setup()
{
	//Maak Scherm
	_g_ctlr->create_window("Demo", 720, 1280);

	//Voeg Muziek toe
	_a_ctlr->add_music("level1", Utility::Helpers::get_base_path() + "/assets/audio/billy.wav");
	//Speel Muziek af
	_a_ctlr->play_audio("level1");

	//Maak Plaatje
	_plaatje = std::make_shared<Graphics::Models::Sprite>(640, 360, 1, 50, 50, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/idle/player_idle_000.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, true);
	//Voeg Plaatje toe aan scherm
	_g_ctlr->add_texture(_plaatje);

	//Maak Shape
	_shape = std::make_shared<PhysicsCollision::Models::Shape>(640, 360, 50, 50, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
	//Maak world
	_w_ctlr->setup_world(1280, 720);
	//Voeg shape toe aan world
	_w_ctlr->load_shape(_shape);

	std::thread t = std::thread(&Demo::run, this);

	_i_ctlr->subscribe(this->shared_from_this());
	_i_ctlr->poll_events();
}

void Demo::Demo::run() {
	while (true) {
		sleep_for(2ms);
		_w_ctlr->simulate();
		_plaatje->set_x(_shape->get_x());
		_plaatje->set_y(_shape->get_y());
		_g_ctlr->update_window();
	}
}

void Demo::Demo::update(const Input::Enums::EventEnum& object)
{
	switch (object) {
	case Input::Enums::EventEnum::KEY_PRESS_LEFT:
		_shape->move_x(-1);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		_shape->move_x(1);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_UP:
		_shape->move_y();
		break;
	}
}

