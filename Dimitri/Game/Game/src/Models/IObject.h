#pragma once
#include <vector>
#include <memory>
#include <string>
#include <src\Models\Texture.h>
#include <map>
#include <src\Helpers\BasePathHelper.h>
#include <src/Models/Sprite.h>
#include <src\Models\Shape.h>
#include "../Enums/StateEnum.cpp"

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the Models
	*/
	namespace Models {
		/**
		*	Interface for all  objects used in game
		*/
		class IObject {
		protected:
			/**
			*	Position object
			*/
			int _x;
			int _y;
			int _z;

			/**
			*	Size of object
			*/
			int _height;
			int _width;

			/**
			*	Object state ex: Walking, Climbing, Crouching, Jumping, Standing still. You could also specify a certain walking texture and change it every frame.
			*/
			Game::Enums::StateEnum _state;

			/**
			*	Textures saved by state for easy access
			*/
			std::map<Game::Enums::StateEnum, std::shared_ptr<Graphics::Models::Texture>> _textures;

			/**
			*	Shape of object
			*/
			std::shared_ptr<PhysicsCollision::Models::Shape> _shape;

			/**
			*	Initializes textures specific to object
			*/
			virtual void initialize_textures() = 0;

		public:
			IObject(int x, int y, int z, int height, int width);

			/**
			*	Returns texture based on state
			*/
			std::shared_ptr<Graphics::Models::Texture> get_texture();

			/**
			*	Returns all textures
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_all_textures();

			/**
			*	Returns x
			*/
			int get_x() const;

			/**
			*	Sets x
			*/
			void set_x(const int& value);

			/**
			*	Returns y
			*/
			int get_y() const;

			/**
			*	Sets x
			*/
			void set_y(const int& value);

			/**
			*	Returns z
			*/
			int get_z() const;

			/**
			*	Sets x
			*/
			void set_z(const int& value);

			/**
			*	Sets state
			*/
			void set_state(const Game::Enums::StateEnum& state);

			/**
			*	Returns shape
			*/
			std::shared_ptr<PhysicsCollision::Models::Shape> get_shape() const;

			/**
			*	Sets shape
			*/
			void set_shape(std::shared_ptr<PhysicsCollision::Models::Shape> shape);

			/**
			*	Adds texture
			*/
			void add_texture(const Game::Enums::StateEnum& state, std::shared_ptr<Graphics::Models::Texture> texture);

			/**
			*	Returns height
			*/
			int get_height() const;

			/**
			*	Returns width
			*/
			int get_width() const;

			/**
			*	Updates x/y values using shape
			*/
			void update();
		};
	}
}