#include "def.h"
#include "win.h"
#include "draw.h"
#include "texture.h"

int main()
{
    initWindow(640, 480, "Hello Kitty");
    loadImageFromImageFile("res\\images\\brick.bmp");
    loadImageFromImageFile("res\\images\\grass.bmp");
    loadImageFromImageFile("res\\images\\rock.bmp");
    loadImageFromImageFile("res\\images\\red.bmp");
    loadImageFromInfFile("images.inf");
    for(int i=1; i<=gImages.length; i++) cout<<i<<". "<<gImages.texture[i].name<<endl;
    runGameLoop ();
    return 0;
}

void loop(){

}
