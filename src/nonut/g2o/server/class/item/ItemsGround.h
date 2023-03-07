#ifndef NONUT_G2O_SERVER_CLASS_ITEMS_GROUND
#define NONUT_G2O_SERVER_CLASS_ITEMS_GROUND
#ifndef NONUT_G2O_SERVER_CLASS_ITEMS_GROUND_H
#define NONUT_G2O_SERVER_CLASS_ITEMS_GROUND_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"
#include "ItemGround.h"

// TODO: Static
namespace nonut::g2o
{
	/// @brief This class represents item ground manager.
	class ItemsGround : public Class
	{
	public:
		ItemsGround(SQObject object);

		// Methods
		/// @brief This method will retrieve the item ground object by its unique id.
		/// @param itemGroundId the unique item ground id.
		/// @returns Returns ItemGround the item ground object or null if the object cannot be found.
		Function<ItemGround, Int> id;
		/// @brief This method will create the item ground.
		/// @param itemId the item id.
		/// @param itemAmount the item amount.
		/// @param x the x position on the world.
		/// @param y the y position on the world.
		/// @param z the z position on the world.
		/// @param world the world path.
		/// @param virtualWorld the virtual world id.
		/// @returns ItemGround the item ground object.
		Function<ItemGround, Int, Int, Float, Float, Float, String, Int> spawn;
		/// @brief This method will destroy the item ground by it's unique id.
		/// @param int itemGroundId the item ground unique id. description
		Function<void, Int> destroy;
	};
}

#endif // NONUT_G2O_SERVER_CLASS_ITEMS_GROUND_H

#endif // NONUT_G2O_SERVER_CLASS_ITEMS_GROUND
