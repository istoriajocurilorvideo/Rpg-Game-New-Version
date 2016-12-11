#include "texture.h"

imgMapComp tilesets[5];

imgEntComp images;

void loadImageFromImageFile(char* filename){
    sf::Image image;

    images.length++;
    char str[strlen(filename)], *aux;

    strcpy(str, filename);
    aux = strrchr(str, '\\');
    if(aux) strcpy(aux, aux+1);
    aux = strtok(aux, ".");
    strcpy(images.ent[images.length].name, aux);

    image.loadFromFile(string(filename));
    image.createMaskFromColor(sf::Color(255, 0 ,220));
    images.ent[images.length].texture.loadFromImage(image);

}
/*
void loadImageFromInfFile(char* filename){
    ifstream file(filename);
    char imageFile[256];
    sf::Image image;

    while(file.get(imageFile, 256)) {
        file.get();
        image.loadFromFile(string(imageFile));
        image.createMaskFromColor(sf::Color(255, 0 ,220));
        images.ent.texture[++images.length].loadFromImage(image);
    }
}
*/
