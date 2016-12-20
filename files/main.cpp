#include "def.h"
#include "win.h"
#include "draw.h"
#include "texture.h"
#include "map.h"

tileset gTilesets;

image gImages;

int main()
{
    initWindow(640, 480, "Hello Kitty");
    loadImageFromInfFile("images.inf", gImages);
    loadMap("res\\maps\\map1.inf");
    loadTileset("res\\tree.bmp", 32, 32, gTilesets);
    runGameLoop ();
    return 0;
}
void loop(){
    int lx = 0,ly = 0;
    for(int i=0; i<gTilesets.tilesets[1].length; i++){
        drawImage((lx++)*32, 32 * ly, 32, 32, gTilesets.tilesets[1].texture[i]);

        if(lx % 8 == 0){
            lx = 0;
            ly++;
        }
    }
    //system("cls");
   // cout<<window.getSize().x<<" "<<window.getSize().y;
}
