#include "texture.h"

images gImages;

tilesets gTilesets;

void loadImageFromImageFile(char* filename){
    sf::Image image;

    gImages.length++;
    char str[MAX_IMAGE_DIR_LENGTH], *aux;

    strcpy(str, filename);
    aux = strrchr(str, '\\');
    if(aux) strcpy(aux, aux+1);
    aux = strtok(aux, ".");
    strcpy(gImages.texture[gImages.length].name, aux);

    image.loadFromFile(string(filename));
    image.createMaskFromColor(sf::Color(255, 0 ,220));
    gImages.texture[gImages.length].textureInfo.loadFromImage(image);
}

void loadImageFromInfFile(char* filename){
    ifstream file(filename);
    char imageDir[MAX_IMAGE_DIR_LENGTH];
    char str[MAX_IMAGE_DIR_LENGTH];
    char *aux;
    sf::Image image;

    while(file.get(imageDir, 256)) {
        file.get();

        gImages.length++;

        strcpy(str, imageDir);
        aux = strrchr(str, '\\');
        if(aux) strcpy(aux, aux+1);
        aux = strtok(aux, ".");
        strcpy(gImages.texture[gImages.length].name, aux);

        image.loadFromFile(string(imageDir));
        image.createMaskFromColor(sf::Color(255, 0 ,220));
        gImages.texture[gImages.length].textureInfo.loadFromImage(image);
    }
}

void loadTileset(char *filename, int w, int h){
    sf::Image image;
    int i, j, imgH, imgW;

    image.loadFromFile(string(filename));
    image.createMaskFromColor(sf::Color(255, 0 ,220));
    gTilesets.length++;
    gTilesets.tileset[gTilesets.length].tileWidth = w;
    gTilesets.tileset[gTilesets.length].tileHeight = h;
    gTilesets.tileset[gTilesets.length].texWidth = image.getSize().x;
    gTilesets.tileset[gTilesets.length].texHeight = image.getSize().y;
    imgW = image.getSize().x/w;
    imgH = image.getSize().y/h;
    gTilesets.tileset[gTilesets.length].length = imgH * imgW;

    for(i=0; i<=imgH-1; i++)
        for(j=0; j<=imgW-1; j++)
            gTilesets.tileset[gTilesets.length].texture[i*imgW+j].loadFromImage(image, sf::IntRect(j*w, i*h, w, h));
}
