# Simple toolchain file for compiling under windows
# Usage: cmake .. -DCMAKE_TOOLCHAIN_FILE=windows-x86.cmake

# specify the target system properties
set(CMAKE_SYSTEM_NAME Windows)

if (CMAKE_GENERATOR MATCHES "Visual Studio*")
	set(CMAKE_GENERATOR_PLATFORM Win32 CACHE INTERNAL "")
endif()

# specify shared library suffix
set(SHARED_LIBRARY_SUFFIX "x86")
