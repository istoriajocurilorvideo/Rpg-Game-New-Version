#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include "def.h"

#define MAX_NR_TEXTURES 1024

#define MAX_NR_TILESETS 5

struct texture{
    sf::Texture textureInfo;
    char name[MAX_NAME_SIZE];
};

struct images{
    texture texture[MAX_NR_TEXTURES];
    int length = 0;
};

struct textures{
    sf::Texture textureInfo[MAX_NR_TEXTURES];
    int length = 0;
};

struct tilesets{
    textures texture[MAX_NR_TILESETS];
    int length = 0;
};

void loadImageFromImageFile(char* filename);

void loadImageFromInfFile(char* filename);

//char *getImage(char *name);

extern images gImages;

extern tilesets gTilesets;

#endif // TEXTURE_H_INCLUDED
