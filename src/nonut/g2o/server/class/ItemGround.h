#ifndef NONUT_G2O_SERVER_CLASS_ITEM_GROUND_H
#define NONUT_G2O_SERVER_CLASS_ITEM_GROUND_H
#include <string>

#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
    /// @brief This class represents item on the ground.
    class ItemGround : public Class
    {
    public:
        ItemGround(void);
        // Properties

        /// @brief Represents the unique id of the item ground.
        Property<Int> id;
        /// @brief Represents the item instance of the item ground.
        Property<String> instance;
        /// @brief Represents the item amount of item ground.
        Property<Int> amount;
        /// @brief Represents the item ground world (.ZEN file path).
        Property<String> world;
        /// @brief Represents the virtual world of item ground.
        Property<Int> virtualWorld;

        // Methods
        /// @brief This method will get the item ground position on the world.
        /// @returns the item ground position on the world.
        Function<Position3d> getPosition;
    };
}

#endif // NONUT_G2O_SERVER_CLASS_ITEM_GROUND_H
