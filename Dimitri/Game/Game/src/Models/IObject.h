#pragma once
#include <vector>
#include <memory>
#include <string>
#include <src\Models\Texture.h>
#include <map>
#include <src\Helpers\BasePathHelper.h>
#include <src/Models/Sprite.h>
#include <src\Models\Shape.h>
#include "../Enums/StateEnum.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Models {
		/**
		* \class IObject
		* \brief Class contains the data for an entity in a level
		*/
		class IObject {
		protected:
			/**
			* \brief The X coordinate of the IObject
			*/
			int _x;

			/**
			* \brief The Y coordinate of the IObject
			*/
			int _y;

			/**
			* \brief The Z coordinate of the IObject
			*/
			int _z;

			/**
			* \brief The height of the IObject
			*/
			int _height;

			/**
			* \brief The width of the IObject
			*/
			int _width;

			/**
			* \brief The state of the IObject
			*/
			Game::Enums::StateEnum _state;

			/**
			* \brief The Textures of the IObject saved by state
			*/
			std::map<Game::Enums::StateEnum, std::shared_ptr<Graphics::Models::Texture>> _textures;

			/**
			* \brief Shape of the IObject
			*/
			std::shared_ptr<PhysicsCollision::Models::Shape> _shape;

			/**
			* \brief Initializes Textures
			*/
			virtual void initialize_textures() = 0;
		public:
			IObject(const int x, const int y, const int z, const int height, const int width, const Game::Enums::StateEnum state);

			/**
			* \brief Returns the Texture based on state
			*/
			std::shared_ptr<Graphics::Models::Texture> get_texture();

			/**
			* \brief Returns all Textures
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_all_textures();

			/**
			* \brief Returns X coordinate
			*/
			int get_x() const;

			/**
			* \brief Sets X coordinate
			*/
			void set_x(int value);

			/**
			* \brief Returns Y coordinate
			*/
			int get_y() const;

			/**
			* \brief Sets Y coordinate
			*/
			void set_y(int value);

			/**
			* \brief Returns Z coordinate
			*/
			int get_z() const;

			/**
			* \brief Sets Z coordinate
			*/
			void set_z(int value);

			/**
			* \brief Sets state of the IObject
			*/
			void set_state(const Game::Enums::StateEnum& state);

			/**
			* \brief Returns Shape of the IObject
			*/
			std::shared_ptr<PhysicsCollision::Models::Shape> get_shape() const;

			/**
			* \brief Creates the shape for the IObject
			*/
			void create_shape(const int x, const int y, const int height, const int width, const bool is_dynamic, const bool is_interactable, const PhysicsCollision::Enums::ShapeEnum type);

			/**
			* \brief Sets shape of the IObject
			*/
			void set_shape(std::shared_ptr<PhysicsCollision::Models::Shape> shape);

			/**
			* \brief Adds Texture
			*/
			void add_texture(const Game::Enums::StateEnum& state, std::shared_ptr<Graphics::Models::Texture> texture);

			/**
			* \brief Returns height of the IObject
			*/
			int get_height() const;

			/**
			* \brief Returns width of the IObject
			*/
			int get_width() const;

			/**
			* \brief Updates X and Y coordinates using the Shape
			*/
			void update();
		};
	}
}