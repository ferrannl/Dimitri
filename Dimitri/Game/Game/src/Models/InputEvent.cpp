#include "InputEvent.h"

Game::Models::InputEvent::InputEvent(Input::Enums::EventEnum event_enum, std::tuple<int, int> mouse_pos) : event_enum{ event_enum }, mouse_pos{ mouse_pos }
{
}