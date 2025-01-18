#ifndef DISPLAY_H
#define DISPLAY_H

#include "globals.h"

class DisplayWindow{
    private:
        sf::RenderWindow t_Window;
        sf::Texture t_Buffer;
        sf::Sprite t_DrawBuffer;
        sf::Uint8* t_PixelBuffer;
    
    public:
        const static int WINDOW_WIDTH = 800;
        const static int WINDOW_HEIGHT = 600;

    public:
        DisplayWindow();
        ~DisplayWindow();

        void update();
        void createWindow();
        void swapBuffers(sf::Uint8* pixelBuffer);

        sf::RenderWindow& getWindowInstance();
};

#endif