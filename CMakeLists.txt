cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(wog-module VERSION 0.1)

# exporting compile time variables into WogConfig.h
include_directories(${CMAKE_CURRENT_BINARY_DIR})
string(TIMESTAMP COMPILE_TIME "%Y-%m-%d %H:%M:%S")
configure_file(WogConfig.h.in WogConfig.h)

file(GLOB SHARED_SRC
	"src/api/squirrel_api.h"
	"src/api/module_api.h"
	"src/api/module_api.cpp"

	"src/nonut/core/Array.cpp"
	"src/nonut/core/Class.cpp"
	"src/nonut/core/StaticClass.cpp"
	"src/nonut/core/Constant.cpp"

	"src/nonut/g2o/shared/class/mds/Mds.cpp"
	"src/nonut/g2o/shared/class/math/Vec3.cpp"
	"src/nonut/g2o/shared/class/math/Vec4.cpp"
	"src/nonut/g2o/shared/class/math/Mat3.cpp"
	"src/nonut/g2o/shared/class/math/Mat4.cpp"

	"src/nonut/g2o/shared/CustomTypes.cpp"

	"src/nonut/g2o/shared/function/SharedFunctions.cpp"

	"src/nonut/g2o/shared/constant/SharedConstants.cpp"

	"src/pch/pch.h"
)

file(GLOB CLIENT_SRC
	"src/nonut/g2o/client/Virt.cpp"
	#discord classes

	#game classes
	"src/nonut/g2o/client/class/game/Camera.cpp"
	"src/nonut/g2o/client/class/game/Sound.cpp"
	"src/nonut/g2o/client/class/game/Sound3d.cpp"
	"src/nonut/g2o/client/class/game/Timestep.cpp"
	"src/nonut/g2o/client/class/game/Vob.cpp"
	"src/nonut/g2o/client/class/game/World.cpp"
	"src/nonut/g2o/client/class/game/Way.cpp"
	"src/nonut/g2o/client/class/game/TraceRayReport.cpp"
	#general classes
	"src/nonut/g2o/client/class/general/zlist.cpp"
	#math classes
	"src/nonut/g2o/client/class/math/BBox3d.cpp"
	#network classes
	"src/nonut/g2o/client/class/network/Packet.cpp"
	#ui classes
	"src/nonut/g2o/client/class/ui/Draw.cpp"
	"src/nonut/g2o/client/class/ui/Draw3d.cpp"
	"src/nonut/g2o/client/class/ui/ItemRenderer.cpp"
	"src/nonut/g2o/client/class/ui/Line.cpp"
	"src/nonut/g2o/client/class/ui/Line3d.cpp"
	"src/nonut/g2o/client/class/ui/Texture.cpp"
	#waypoint classes
	"src/nonut/g2o/client/class/waypoint/Way.cpp"

	"src/nonut/g2o/client/function/ClientFunctions.cpp"
	"src/nonut/g2o/client/event/ClientEventHandlers.cpp"
	"src/nonut/g2o/client/constant/ClientConstants.cpp"

	"src/wog/client/ClientSqMain.cpp"
	"src/wog/client/HUD.cpp"
	"src/wog/client/Sprint.cpp"
	"src/wog/client/Player.cpp"
	"src/wog/client/Chat.cpp"
)

file(GLOB SERVER_SRC
	
	"src/nonut/g2o/server/class/item/ItemGround.cpp"
	"src/nonut/g2o/server/class/item/ItemsGround.cpp"
	"src/nonut/g2o/server/class/network/Packet.cpp"
	"src/nonut/g2o/server/class/waypoint/Way.cpp"

	"src/nonut/g2o/server/constant/ServerConstants.cpp"

	"src/nonut/g2o/server/event/ServerEventHandlers.cpp"
	"src/nonut/g2o/server/function/ServerFunctions.cpp"

	"src/wog/server/ServerSqMain.cpp"

	"src/wog/server/Chat.cpp"
	"src/wog/server/Login.cpp"
	"src/wog/server/db/Database.cpp"
)

add_library(wog-module-client SHARED ${SHARED_SRC})
add_library(wog-module-server SHARED ${SHARED_SRC})

target_sources(wog-module-client PRIVATE ${CLIENT_SRC})
target_sources(wog-module-server PRIVATE ${SERVER_SRC})


target_precompile_headers(wog-module-client PRIVATE "src/pch/pch.h")
target_include_directories(wog-module-client
	INTERFACE
		"include/"
	PRIVATE
		"src/api/"
		"src/pch/"
		"src/nonut/core/"
		"src/nonut/g2o/client"
		"src/nonut/g2o/shared"
		"src/wog/client"
		"src/wog/shared"
)

target_precompile_headers(wog-module-server PRIVATE "src/pch/pch.h")
target_include_directories(wog-module-server
	INTERFACE
		"include/"
	PRIVATE
		"src/api/"
		"src/pch/"
		"src/nonut/core/"
		"src/nonut/g2o/server"
		"src/nonut/g2o/shared"
		"src/wog/server"
		"src/wog/shared"
)

add_subdirectory(dependencies)