

project(snake-game)

file(GLOB src "*.cpp")

#add sdl3
add_subdirectory(SDL)

add_executable(snake ${src})
add_target_include_directoties(snake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SDL/include/SDL3)
add_target_include_directoties(snake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SDL/include/)
