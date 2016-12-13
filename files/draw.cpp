#include "draw.h"
#include "texture.h"

sf::RectangleShape rectangle;

sf::Sprite sprite;

void drawRect(float x, float y, float w, float h, float r, float g, float b){
    rectangle.setFillColor(sf::Color(r, g, b));
    rectangle.setPosition(x, y);
    rectangle.setSize(sf::Vector2f(w,  h));
    window.draw(rectangle);
}

void drawRect(float x, float y, float w, float h){
    drawRect(x, y, w, h, 255, 255, 255);
}

void drawImage(float x, float y, int id){
    sprite.setPosition(x, y);
    sprite.setTexture(gImages.texture[id].textureInfo);
    window.draw(sprite);
}

void drawImage(float x, float y, float w, float h, int id){
    sprite.setPosition(x, y);
    sprite.setTexture(gImages.texture[id].textureInfo);
    float wSp = sprite.getGlobalBounds().width;
    float hSp = sprite.getGlobalBounds().height;
    sprite.scale(sf::Vector2f((float)(w/wSp),(float)(h/hSp)));
    window.draw(sprite);
}
