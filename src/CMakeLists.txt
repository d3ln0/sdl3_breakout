add_executable(${PROJECT_NAME})

add_subdirectory(sdl)
target_sources(${PROJECT_NAME} PRIVATE entity.c paddle.c PUBLIC entity.h paddle.h)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)