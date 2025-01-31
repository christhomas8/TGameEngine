#include "../include/engine.h"
#include "../include/display.h"
#include "../include/logger.h"
#include "../include/templates.h"

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

    sf::Font font;
    bool fontLoaded = font.loadFromFile("../fonts/ball.ttf");
    sf::Text text;
    if (fontLoaded){
        text.setFont(font);
    }        
    text.setString("Hello World");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Red);
    text.setPosition({120.f,100.f});

    Shapes cube;
    std::vector<std::vector<float>> unitCube = {
        //{0,0,0},
        //{1,0,0},
        //{1,1,0},
        //{0,1,0},
        //{0,0,1},
        //{1,0,1},
        //{0,1,1},
        //{1,1,1}

        { 1, -1, -5},
        { 1, -1, -3},
        { 1,  1, -5},
        { 1,  1, -3},
        {-1, -1, -5},
        {-1, -1, -3},
        {-1,  1, -5},
        {-1,  1, -3}
    };

    int numberOfPoints = sizeof(unitCube) / sizeof(unitCube[0]);
    console(std::to_string(numberOfPoints));

    for(int i = 0; i < 8; ++i){
        float x_proj = unitCube[i][0] / -unitCube[i][2];
        float y_proj = unitCube[i][1] / -unitCube[i][2];
        printf("Projected corner %d: x:%f, y:%f\n", i, x_proj, y_proj);
    }
    //cube.PrintPoints(unitCube);

    while (running){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                running = false;
            }
            else if (event.type == sf::Event::Resized) {
                glViewport(0, 0,event.size.width, event.size.height);
                console("Screen size: " + std::to_string(event.size.width)+ "," +std::to_string(event.size.height));
            }        
            else if (event.type == sf::Event::JoystickButtonPressed){

            } 
            else if (event.type == sf::Event::JoystickButtonReleased){

            }   
            else if (event.type == sf::Event::JoystickMoved){
                
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        window.clear(sf::Color::Yellow);
        window.pushGLStates();
        window.draw(text);
        window.popGLStates();
        
        window.display();

    }
}
