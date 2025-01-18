#ifndef ENGINE_H
#define ENGINE_H

#include "globals.h"

class Engine {
    private:
        bool isRunning;
        float rotation;

    private:
        void processInput(const sf::Event& event);

    public:
        Engine();
        ~Engine();

        void run();
};

#endif