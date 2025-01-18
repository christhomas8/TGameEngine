#include "../include/display.h"

DisplayWindow::DisplayWindow(){
    t_PixelBuffer = new sf::Uint8[WINDOW_WIDTH*WINDOW_HEIGHT*4];
    t_Buffer.create(WINDOW_WIDTH, WINDOW_HEIGHT);
    t_Buffer.setRepeated(false);
    t_DrawBuffer.setTexture(t_Buffer);
}

DisplayWindow::~DisplayWindow(){
    delete [] t_PixelBuffer;
}

void DisplayWindow::createWindow() {
    t_Window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "T Game Engine");
}

void DisplayWindow::update(){
    t_Window.clear(sf::Color::Green);
    t_Window.draw(t_DrawBuffer);
    t_Window.display();
}

void DisplayWindow::swapBuffers(sf::Uint8* pixelBuffer){
    std::copy_n(pixelBuffer, 4*WINDOW_HEIGHT*WINDOW_WIDTH,t_PixelBuffer);
    t_Buffer.update(t_Buffer);
    std::fill(pixelBuffer, pixelBuffer + 4*WINDOW_WIDTH*WINDOW_HEIGHT, 0);
}

sf::RenderWindow& DisplayWindow::getWindowInstance() {
    return t_Window;
}