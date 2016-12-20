#include "texture.h"

void loadImageFromImageFile(char* filename, image& gImages){
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

void loadImageFromInfFile(char* filename, image& gImages){
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

void loadTileset(char *filename, int w, int h, tileset& gTilesets){
    sf::Image image;
    int i, j, imgH, imgW;

    image.loadFromFile(string(filename));
    image.createMaskFromColor(sf::Color(255, 0 ,220));
    gTilesets.length++;
    gTilesets.tilesets[gTilesets.length].tileWidth = w;
    gTilesets.tilesets[gTilesets.length].tileHeight = h;
    imgW = image.getSize().x/w;
    imgH = image.getSize().y/h;
    gTilesets.tilesets[gTilesets.length].length = imgH * imgW;
    for(i=0; i<=imgH-1; i++)
        for(j=0; j<=imgW-1 ;j++)
            gTilesets.tilesets[gTilesets.length].texture[i*imgW+j].loadFromImage(image, sf::IntRect(j*w, i*h, w, h));
}
