cmake_minimum_required(VERSION 3.29)
project(Fractals)

set(CMAKE_OSX_ARCHITECTURES "x86_64")

set(CMAKE_CXX_STANDARD 23)


add_executable(${PROJECT_NAME}
        main.cpp
)

include_directories(/usr/local/include)
find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
set(IMGUI_DIR "/Users/anakrasnuk/CLionProjects/untitled12/imgui-sfml-master")

add_executable(MyExecutable main.cpp)
target_link_libraries(MyExecutable PRIVATE sfml-graphics sfml-window sfml-system imgui)