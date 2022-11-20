add_subdirectory(squirrel)
add_subdirectory(sqrat)

target_link_libraries(wog-module-client PUBLIC Squirrel)
target_link_libraries(wog-module-client PUBLIC SqRat)
target_link_libraries(wog-module-server PUBLIC Squirrel)
target_link_libraries(wog-module-server PUBLIC SqRat)