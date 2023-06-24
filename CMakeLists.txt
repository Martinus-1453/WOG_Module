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
)

file(GLOB CLIENT_SRC
	"src/wog/client/ClientSqMain.cpp"
	"src/wog/client/32bitSurface.cpp"
	"src/wog/client/Browser.cpp"
	"src/wog/client/View.cpp"
	"src/wog/client/HUD.cpp"
	"src/wog/client/Sprint.cpp"
	"src/wog/client/Player.cpp"
	"src/wog/client/Chat.cpp"
	"src/wog/client/Virt.cpp"
)

file(GLOB SERVER_SRC
	"src/wog/server/ServerSqMain.cpp"

	"src/wog/server/Chat.cpp"
	"src/wog/server/Login.cpp"
	"src/wog/server/db/Database.cpp"
)

add_library(wog-module-client SHARED ${SHARED_SRC})
add_library(wog-module-server SHARED ${SHARED_SRC})

target_sources(wog-module-client PRIVATE ${CLIENT_SRC})
target_sources(wog-module-server PRIVATE ${SERVER_SRC})


target_precompile_headers(wog-module-client
    PRIVATE
		<zGothicAPI.h>
		"src/api/module_api.h"
		"src/api/squirrel_api.h"
)
target_compile_definitions(wog-module-client
    PRIVATE
        SCRAT_EXPORT
)
target_include_directories(wog-module-client
	INTERFACE
		"include/"
	PRIVATE
		"src/api/"
		"src/wog/client"
		"src/wog/shared"
)

target_precompile_headers(wog-module-server
	PRIVATE
		"src/api/module_api.h"
		"src/api/squirrel_api.h"
)
target_compile_definitions(wog-module-server
    PRIVATE
        SCRAT_EXPORT
)
target_include_directories(wog-module-server
	INTERFACE
		"include/"
	PRIVATE
		"src/api/"
		"src/wog/server"
		"src/wog/shared"
)

add_subdirectory(dependencies)