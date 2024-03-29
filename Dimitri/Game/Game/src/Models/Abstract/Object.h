#pragma once
#include <vector>
#include <memory>
#include <string>
#include <src\Models\Texture.h>
#include <map>
#include <src\Helpers\BasePathHelper.h>
#include <src/Models/Sprite.h>
#include <src\Models\Shape.h>
#include "../../Enums/StateEnum.h"
#include "../../Enums/AnimateEnum.h"
#include "../../Enums/DirectionEnum.h"
#include <mutex> 

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
		* \class Object
		* \brief Class contains the data for an entity in a level
		*/
		class Object {
		protected:
			/**
			* \brief The X coordinate of the Object
			*/
			float _x;

			/**
			* \brief The Y coordinate of the Object
			*/
			float _y;

			/**
			* \brief The Z coordinate of the Object
			*/
			float _z;

			/**
			* \brief The height of the Object
			*/
			float _height;

			/**
			* \brief The width of the Object
			*/
			float _width;

			/**
			* \brief The direction the Object is faced
			*/
			Enums::DirectionEnum _direction;

			/**
			* \brief The rotating cener of the Object
			*/
			Graphics::Models::Center _center;

			/**
			* \brief The state of the Object
			*/
			Enums::StateEnum _state;

			/**
			* \brief The animationstate of the Object
			*/
			Enums::AnimateEnum _animatestate;

			/**
			* \brief The Textures of the Object saved by animation state
			*/
			std::map<Enums::AnimateEnum, std::shared_ptr<Graphics::Models::Texture>> _textures;

			/**
			* \brief Shape of the Object
			*/
			std::shared_ptr<PhysicsCollision::Models::Shape> _shape;

			/**
			* \brief Angle of the Object
			*/
			float _angle;

			/**
			* \brief Initializes Textures
			*/
			virtual void initialize_textures() = 0;

			/**
			* \brief used for locking textures
			*/
			std::mutex _mtx;
		public:
			Object(float x, float y, float z, float height, float width, Enums::DirectionEnum state, const Graphics::Models::Center& center);

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
			float get_x() const;

			/**
			* \brief Sets X coordinate
			*/
			void set_x(float value);

			/**
			* \brief Returns Y coordinate
			*/
			float get_y() const;

			/**
			* \brief Sets Y coordinate
			*/
			void set_y(float value);

			/**
			* \brief Returns Z coordinate
			*/
			float get_z() const;

			/**
			* \brief Sets Z coordinate
			*/
			void set_z(float value);

			/**
			* \brief Sets state of the Object
			*/
			void set_state(Enums::StateEnum state);

			/**
			* \brief Sets direction of the Object
			*/
			void set_direction(Enums::DirectionEnum value);

			/**
			* \brief Sets animationstate of the Object
			*/
			void set_animationstate(Enums::AnimateEnum state);

			/**
			* \brief Toggles visibility of texture
			*/
			void toggle_visibility();

			/**
			* \brief Returns Shape of the Object
			*/
			const std::shared_ptr<PhysicsCollision::Models::Shape> get_shape() const;

			/**
			* \brief Creates the shape for the Object
			*/
			void create_shape(float x, float y, float height, float width, bool is_dynamic, bool is_interactable, PhysicsCollision::Enums::ShapeEnum type);

			/**
			* \brief Adds Texture
			*/
			void add_texture(Enums::AnimateEnum state, const std::shared_ptr<Graphics::Models::Texture> texture);

			/**
			* \brief Returns height of the Object
			*/
			float get_height() const;

			/**
			* \brief Returns width of the Object
			*/
			float get_width() const;

			/**
			* \brief Updates X and Y coordinates using the Shape
			*/
			void update();

			/**
			* \brief Clear textures
			*/
			void clear_textures();
		};
	}
}