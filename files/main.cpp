#include "def.h"
#include "win.h"
#include "draw.h"
#include "texture.h"
#include "map.h"

int main()
{
    string json_example = "{\"array\": \
                            [\"item1\", \
                            \"item2\"], \
                            \"not an array\": \
                            \"asdf\" \
                         }";
 Json::Value root;
 Json::Reader reader;
 bool parsedSuccess = reader.parse(json_example,
                                   root,
                                   false);

 if(not parsedSuccess)
 {
   cout<<"Failed to parse JSON"<<endl
       <<reader.getFormatedErrorMessages()
       <<endl;
   return 1;
 }

 const Json::Value array = root["array"];

 for(unsigned int index=0; index<array.size();
     ++index)
 {
   cout<<"Element "
       <<index
       <<" in array: "
       <<array[index].asString()
       <<endl;
 }

 const Json::Value notAnArray =
               root["not an array"];

 if(not notAnArray.isNull())
 {
   cout<<"Not an array: "
       <<notAnArray.asString()
       <<endl;
 }

 cout<<"Json Example pretty print: "
     <<endl<<root.toStyledString()
     <<endl;
    initWindow(640, 480, "Hello Kitty");
    loadImageFromImageFile("res\\images\\brick.bmp");
    loadImageFromImageFile("res\\images\\grass.bmp");
    loadImageFromImageFile("res\\images\\rock.bmp");
    loadImageFromImageFile("res\\images\\red.bmp");
    loadImageFromInfFile("images.inf");
    loadMap("res\\maps\\map1.inf");
    loadTileset("res\\tree.bmp", 32, 32);
    runGameLoop ();
    return 0;
}
void loop(){
    int lx = 0,ly = 0;
    for(int i=0; i<gTilesets.tileset[1].length; i++){
        drawImage((lx++)*32, 32 * ly, 32, 32, gTilesets.tileset[1].texture[i]);

        if(lx % 8 == 0){
            lx = 0;
            ly++;
        }
    }
    //system("cls");
   // cout<<window.getSize().x<<" "<<window.getSize().y;
}
