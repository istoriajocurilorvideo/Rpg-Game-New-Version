#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include "def.h"

#define MAX_NR_TEXTURES 2048

#define MAX_NR_TILESETS 5

struct texture{
    sf::Texture textureInfo;
    char name[MAX_NAME_SIZE];
};

struct image{
    texture texture[MAX_NR_TEXTURES];
    int length = 0;
};

struct tilesetForm{
    sf::Texture texture[MAX_NR_TEXTURES];
    int tileWidth, tileHeight;
    int length=0;
};

struct tileset{
    tilesetForm tilesets[MAX_NR_TILESETS];
    int length=0;
};

void loadImageFromImageFile(char* filename, image& gImages);

void loadImageFromInfFile(char* filename, image& gImages);

void loadTileset(char *filename, int w, int h, tileset& gTilesets);

//char *getImage(char *name);

#endif // TEXTURE_H_INCLUDED
