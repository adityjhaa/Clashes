#include "prop.h"

prop::prop(Vector2 pos, Texture2D tex): worldpos(pos),texture(tex){
    /////
}

void prop::render(Vector2 knightpos){
    Vector2 screenpos{Vector2Subtract(worldpos,knightpos)};
    DrawTextureEx(texture,screenpos,0.0,scale,WHITE);
}

Rectangle prop::getcollisionrec(Vector2 knightpos){
    Vector2 screenpos{Vector2Subtract(worldpos,knightpos)};
    return Rectangle{
        screenpos.x,screenpos.y,
        scale*texture.width,scale*texture.height
    };
}
