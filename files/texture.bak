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
