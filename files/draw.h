#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "def.h"
#include "win.h"
#include "texture.h"

void drawRect(float x, float y, float w, float h, float r, float g, float b);

void drawRect(float x, float y, float w, float h);

void drawImage(float x, float y, sf::Texture texture);

void drawImage(float x, float y, float w, float h, sf::Texture texture);

extern sf::Sprite sprite;

#endif // DRAW_H_INCLUDED
