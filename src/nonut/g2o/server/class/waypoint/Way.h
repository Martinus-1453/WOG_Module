#ifndef NONUT_G2O_SERVER_CLASS_WAY
#define NONUT_G2O_SERVER_CLASS_WAY
#include <string>

#include "Array.h"
#include "Class.h"
#include "CustomTypes.h"

namespace nonut::g2o
{
    /// @brief This class represents Way constructed from waypoints.
    class Way : public Class
    {
    public:
        /// @brief This class represents Way constructed from waypoints.
        /// @param world the name of the world from config.xml
        /// @param startWp the name of the start waypoint
        /// @param endWp the name of the end waypoint
        Way(String world, String startWp, String endWp);

        // Properties
        /// @brief Represents the start waypoint for Way.
        Property<String> start;
        /// @brief Represents the start waypoint for Way.
        Property<String> end;

        // Methods
        /// @brief This method will get the all waypoints between startWp & endWp.
        /// @returns the array containing the names of all of the Way waypoints.
        // TODO: htf array should be used?
        Function<Array> getWaypoints;
        /// @brief This method will get the number of waypoints between start waypoint & end waypoint.
        /// @returns int the number of waypoints.
        // TODO: htf array should be used?
        Function<Int> getCountWaypoints;
    };
}

#endif // NONUT_G2O_SERVER_CLASS_WAY
