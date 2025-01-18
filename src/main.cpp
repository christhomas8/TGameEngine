#include "../include/engine.h"

int main(int argc, char const *argv[]){
    Engine engine;
    //engine.run();

    /////////////////////////////////////////////
    sf::Window window(sf::VideoMode({800,600}),"OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    window.setActive(true);

    bool running = true;

    while (running){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                running = false;
            }
            else if (event.type == sf::Event::Resized) {
                glViewport(0, 0,event.size.width, event.size.height);
                console(std::to_string(event.size.width));
            }
            
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        window.display();
    }
    ///////////////////////////////////////////////

    return 0;
}