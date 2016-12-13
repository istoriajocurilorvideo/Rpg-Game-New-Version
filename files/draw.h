#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "def.h"
#include "win.h"

void drawRect(float x, float y, float w, float h, float r, float g, float b);

void drawRect(float x, float y, float w, float h);

void drawImage(float x, float y, int id);

void drawImage(float x, float y, float w, float h, int id);

#endif // DRAW_H_INCLUDED
