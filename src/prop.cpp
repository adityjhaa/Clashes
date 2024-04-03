#include "../include/prop.h"

prop::prop(Vector2 pos, Texture2D tex, float padding): worldpos(pos),texture(tex),padding(padding){
    /////
}

void prop::render(Vector2 knightpos){
    Vector2 screenpos{Vector2Subtract(worldpos,knightpos)};
    DrawTextureEx(texture,screenpos,0.0,scale,WHITE);
}

Rectangle prop::getcollisionrec(Vector2 knightpos){
    Vector2 screenpos{Vector2Subtract(worldpos,knightpos)};
    return Rectangle{
        screenpos.x+padding,screenpos.y+padding,
        scale*texture.width-2*padding,scale*texture.height-2*padding
    };
}
