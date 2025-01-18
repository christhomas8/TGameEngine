#include "../include/engine.h"
#include "../include/display.h"
#include "../include/logger.h"

Engine::Engine() : isRunning(true), rotation(0.f) {}
Engine::~Engine() {}

void Engine::run(){
    Logger logger;
    logger.logToFile(logger.logLevel(logger.Info), "Starting engine");

    DisplayWindow display;
    display.createWindow();
    sf::RenderWindow& window = display.getWindowInstance();

    window.setActive(true);

    sf::Clock clock;
    while (window.isOpen()){
        sf::Event event;

        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            /*if (event.key.code == sf::Keyboard::K){
                std::cout << "K" << std::endl;
            }
            if (event.key.code == sf::Keyboard::L){
                std::cout << "L" << std::endl;
            }*/
        }

        display.update();

        sf::Time time = clock.getElapsedTime();        
    }

    logger.logToFile(logger.logLevel(logger.Info),"Ending engine");
    std::cout << "Seconds ran: " << clock.getElapsedTime().asSeconds() << std::endl;
}