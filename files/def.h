#ifndef DEF_HPP_INCLUDED
#define DEF_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <windows.h>
#include <math.h>
#include <time.h>

#define null 0

using namespace std;

int randNumber(int a1, int a2);

struct entity{
    sf::Sprite sprite;
    int sp1, sp2, sp3, sp4;
};

struct mapEntity{
    sf::Sprite sprite;
    int entityId;
};

struct texture{
    sf::Texture texture;
    char name[25];
};

struct imgMapComp{
    int length = 0;
    mapEntity ent[1024];
};

struct imgEntComp{
    int length = 0;
    texture ent[256];
};
#endif
