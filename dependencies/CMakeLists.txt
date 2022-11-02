add_subdirectory(squirrel)
add_subdirectory(sqrat)

target_link_libraries(squirrel-template PUBLIC Squirrel)
target_link_libraries(squirrel-template PUBLIC SqRat)