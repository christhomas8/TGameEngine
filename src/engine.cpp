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
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) { 
                console("Left");
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) { 
                console("Right");
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) { 
                console("Up");
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) { 
                console("Down");
            }
        }

        display.update();

        sf::Time time = clock.getElapsedTime();        
    }

    logger.logToFile(logger.logLevel(logger.Info),"Ending engine");
    std::cout << "Seconds ran: " << clock.getElapsedTime().asSeconds() << std::endl;
}

void Engine::runOpenGL(){

    sf::RenderWindow window(sf::VideoMode({800,600}),"OpenGL", sf::Style::Default, sf::ContextSettings(32));
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
                console(std::to_string(event.size.width)+ "," +std::to_string(event.size.height));
            }            
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        sf::Font font;
        bool fontLoaded = font.loadFromFile("../fonts/ball.ttf");
        
        sf::Text text;
        if (fontLoaded){
            text.setFont(font);
        }        
        text.setString("Hello");
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Red);
        text.setPosition({100.f,100.f});

        window.clear(sf::Color::Yellow);
        window.pushGLStates();
        window.draw(text);
        window.popGLStates();
        
        window.display();
    }
}
