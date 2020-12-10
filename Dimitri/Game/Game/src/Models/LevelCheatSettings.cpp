#include "LevelCheatSettings.h"
#include <climits>

Game::Models::LevelCheatSettings::LevelCheatSettings()
{
	_amount_of_jumps = _normal_amount_of_jumps;
	_invincible = false;
}

int Game::Models::LevelCheatSettings::get_amount_of_jumps() const
{
	return _amount_of_jumps;
}

bool Game::Models::LevelCheatSettings::get_invincible() const
{
	return _invincible;
}

void Game::Models::LevelCheatSettings::set_amount_of_jumps()
{
	if (_amount_of_jumps == _normal_amount_of_jumps) {
		_amount_of_jumps = INT_MAX;
	}
	else {
		_amount_of_jumps = _normal_amount_of_jumps;
	}
}

void Game::Models::LevelCheatSettings::set_invincible()
{
	if (_invincible) {
		_invincible = false;
	}
	else {
		_invincible = true;
	}
}
