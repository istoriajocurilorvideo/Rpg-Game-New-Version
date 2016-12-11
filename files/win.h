#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "def.h"

void initWindow(int width, int height, char *title);

void runGameLoop();

void loop();

void setSleep(int a);

int getWinWidth();

int getWinHeight();


extern sf::RenderWindow window;

extern sf::Event event;
#endif // WINDOW_HPP_INCLUDED
