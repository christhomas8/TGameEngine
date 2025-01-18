cmake_minimum_required(VERSION 3.22)

project(TGameEngine)

#find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)
find_package(SFML 2.5 REQUIRED COMPONENTS graphics audio window)
find_package(OpenGL REQUIRED)

include_directories(include lib)
file(GLOB SOURCES
    include/*.h
    src/*.cpp
    lib/*.h
)

add_executable(T_Game_Engine ${SOURCES})
#target_link_libraries(T_Game_Engine sfml-graphics sfml-window)

target_link_libraries(T_Game_Engine PRIVATE sfml-graphics sfml-audio sfml-window sfml-system OpenGL::GL) 


#g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

#mkdir build
#cd build
#cmake ..
#make
#./executable
