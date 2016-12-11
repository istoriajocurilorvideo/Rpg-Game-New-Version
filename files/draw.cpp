#include "draw.h"
#include "texture.h"

sf::RectangleShape rectangle;

sf::Sprite sprite;

void drawRect(int x, int y, int w, int h, int r, int g, int b){
    rectangle.setFillColor(sf::Color(r, g, b));
    rectangle.setPosition(x, y);
    rectangle.setSize(sf::Vector2f(w,  h));
    window.draw(rectangle);
}

void drawRect(int x, int y, int w, int h){
    drawRect(x, y, w, h, 255, 255, 255);
}

void drawImage(int x, int y, int id){
    sprite.setPosition(x, y);
    sprite.setTexture(images.ent[id].texture);
    window.draw(sprite);
}
