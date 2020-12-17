#include "InputEvent.h"

Game::Events::InputEvent::InputEvent(Input::Enums::EventEnum event_enum, const std::tuple<int, int>& mouse_pos) : event_enum{ event_enum }, mouse_pos{ mouse_pos }
{
}