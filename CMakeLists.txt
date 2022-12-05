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

	"src/nonut/g2o/shared/class/Mds.cpp"

	"src/nonut/g2o/shared/CustomTypes.cpp"

	"src/nonut/g2o/shared/function/SharedFunctions.cpp"

	"src/nonut/g2o/shared/constant/SharedConstants.cpp"

	"src/pch/pch.h"
)

file(GLOB CLIENT_SRC
	"src/nonut/g2o/client/Virt.cpp"

	"src/nonut/g2o/client/class/Camera.cpp"
	"src/nonut/g2o/client/class/Draw.cpp"
	"src/nonut/g2o/client/class/Draw3d.cpp"
	"src/nonut/g2o/client/class/ItemRenderer.cpp"
	"src/nonut/g2o/client/class/Line.cpp"
	"src/nonut/g2o/client/class/Line3d.cpp"
	"src/nonut/g2o/client/class/Texture.cpp"
	"src/nonut/g2o/client/class/Sound.cpp"
	"src/nonut/g2o/client/class/Sound3d.cpp"
	"src/nonut/g2o/client/class/Timestep.cpp"
	"src/nonut/g2o/client/class/World.cpp"
	"src/nonut/g2o/client/class/Way.cpp"
	"src/nonut/g2o/client/class/Packet.cpp"

	"src/nonut/g2o/client/function/ClientFunctions.cpp"

	"src/nonut/g2o/client/event/ClientEventHandlers.cpp"

	"src/nonut/g2o/client/constant/ClientConstants.cpp"

	"src/wog/client/ClientSqMain.cpp"
	"src/wog/client/HUD.cpp"
	"src/wog/client/Sprint.cpp"
)

file(GLOB SERVER_SRC
	
	"src/nonut/g2o/server/class/ItemGround.cpp"
	"src/nonut/g2o/server/class/ItemsGround.cpp"
	"src/nonut/g2o/server/class/Packet.cpp"
	"src/nonut/g2o/server/class/Way.cpp"

	"src/nonut/g2o/server/constant/ServerConstants.cpp"

	"src/nonut/g2o/server/event/ServerEventHandlers.cpp"
	"src/nonut/g2o/server/function/ServerFunctions.cpp"

	"src/wog/server/ServerSqMain.cpp"
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