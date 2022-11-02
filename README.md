# Squirrel module template

## Table of contents

- [Usage requirements](#usage-requirements)
- [Installing module](#installing-module)
- [Loading module](#loading-module)
- [Build requirements](#build-requirements)
- [Build instructions](#build-instructions)
- [CMake options](#cmake-options)

## Usage requirements

This package is essential only for **Windows** platform, and it is installed by default by g2o installer. \
In order to use the module, the user have to install: \
[Microsoft Visual C++ 2015-2022 Redistributable (x86)](https://aka.ms/vs/17/release/vc_redist.x86.exe)

## Installing module

**_NOTE:_** Client modules aren't downloaded by default by g2o server.  
You have to put them manually into: `Game/Multiplayer/Modules` directory.

In order to install the module you can either [download the prebuilt binary](../../releases) from releases, or [build the module yourself](#build-instructions).  
Be sure to install the module with matching CPU architecture for your server app.

## Loading module

To load the module, you have to put `<module>` tag into .xml server configuration.  
Below you can find more info about this tag **attributes**.

```xml
<!--The path to the module relative to .xml file-->
<!--Client-side module must be placed in the exact game path from which it is loaded on the server, e.g: -->
<!--Loading module on s-side: server/MyServerName/sqmodule.dll-->
<!--Will cause the module to be searched in: game/Multiplayer/Modules/MyServerName/sqmodule.dll-->
<!--[required]--> src="path/to/the/module"

<!--[required]--> type="client"|"server"

<!--By default module will be loaded without checksum validation-->
<!--useful when you want to load only specific version of the module-->
<!--[optional]--> md5="1a79a4d60de6718e8e5b326e338ae533"

<!--By default every module is required, you can override this by setting required to false-->
<!--Useful for creating optional modules-->
<!--[optional]--> required=true|false
```

Example of loading client module:
```xml
<module src="sqmodule.x86.dll" type="client" />
```

Example of loading server module:
```xml
<module src="sqmodule.x86.dll" type="server" />
```

## Build requirements

**_NOTE:_**  Some of the requirements like _IDE_ or _compiler_ are just recommendation

In order to compile the module, you have to meet some \
essential requirements,
depending on the target platform.

### Windows

- Visual Studio, 2015+ (recommended [2019 Community Edition](https://visualstudio.microsoft.com/pl/thank-you-downloading-visual-studio/?sku=Community&rel=16))
    
    Visual Studio Components
    * Windows SDK
    * one of the following toolsets, pick one: v140, v141, v142 (recommended v142)
    * (Optional) CMake Tools for Visual Studio
- [CMake 3.17+](https://cmake.org/download/)

### Linux

- g++ compiler
- [CMake 3.17+](https://cmake.org/download/)

## Build instructions

### Windows

#### Visual Studio with CMake tools

- open a local folder using Visual Studio
- build the project

#### Visual Studio without CMake tools

- open command line in repo-directory
- type ``mkdir build``
- type ``cd build``
- type ``cmake ..``
- open visual studio .sln and compile the project
- alternatively if you want to build from command line instead, \
    type ``cmake --build .``

### Linux

- open terminal in repo-directory
- type ``mkdir build``
- type ``cd build``
- type ``cmake ..``
- type ``cmake --build .``

## CMake options

This project has some configurable options.  

### Cache options

Cache options are stored inside **CMakeCache.txt** inside generated CMake build folder.  
You can set these options, by either manually editing the file, or by using cmake-gui.

- **GAME_PATH** this cache option allows you to setup the destination  
    where module will be installed. If it's set to some value, it will  
    generate an installation step. by default it's set to ``""`` (disabled).

- **SERVER_PATH** this cache option allows you to setup the destination  
    where module will be installed. If it's set to some value, it will  
    generate an installation step. by default it's set to ``""`` (disabled).

- **INSTALL_AFTER_BUILD** this cache option allows you to run  
    cmake install step after a successfull build. By default it's disabled.
