function(add_sdl name)
	add_subdirectory(SDL${name})
	target_include_directories(snake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SDL${name}/include/SDL3${name})
	target_include_directories(snake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/SDL${name}/include/)
	target_link_directories(snake PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/SDL${name}/src)

endfunction()

project(snake-game)

file(GLOB src "*.cpp")

add_executable(snake ${src})

#add sdl libraries
add_sdl()
add_sdl(_image)
add_sdl(_mixer)
target_link_libraries(snake PRIVATE SDL3 SDL3_image SDL3_mixer)
