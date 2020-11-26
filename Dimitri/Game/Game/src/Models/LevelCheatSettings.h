#pragma once
namespace Game {
	namespace Models {
		class LevelCheatSettings {
		private:
			const int _normal_amount_of_jumps = 2;
			int _amount_of_jumps;
			bool _invincible;
		public:
			LevelCheatSettings();

			int get_amount_of_jumps() const;
			bool get_invincible() const;

			void set_amount_of_jumps();
			void set_invincible();
		};
	}
}