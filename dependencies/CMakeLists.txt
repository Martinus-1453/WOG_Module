add_subdirectory(squirrel)
add_subdirectory(sqrat)
add_subdirectory(sqlite3)
add_subdirectory(sqlite3_orm)

target_link_libraries(wog-module-client PUBLIC Squirrel)
target_link_libraries(wog-module-client PUBLIC SqRat)

target_link_libraries(wog-module-server PUBLIC Squirrel)
target_link_libraries(wog-module-server PUBLIC SqRat)
target_link_libraries(wog-module-server PUBLIC sqlite3)
target_link_libraries(wog-module-server PUBLIC sqlite3_orm)