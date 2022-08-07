cmake_minimum_required(VERSION 3.23)

project(space LANGUAGES CXX)

set(SOURCES
      src/main.cpp
      src/Game.cpp
      src/Aircraft.cpp
      src/Entity.cpp
      src/SceneNode.cpp
      src/World.cpp
      src/SpriteNode.cpp
      src/Player.cpp
    )


## If you want to link SFML statically
option(SFML_STATIC_LIBRARIES "Compile with static SFML" NO)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(game ${SOURCES})
target_link_libraries(game sfml-window sfml-system sfml-graphics sfml-audio)

if (WIN32 AND NOT SFML_STATIC_LIBRARIES)
    add_custom_command(TARGET game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:game> $<TARGET_FILE_DIR:game> COMMAND_EXPAND_LISTS)
endif()

add_custom_command(TARGET game POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_directory "${CMAKE_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:game>/assets")