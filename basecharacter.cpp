#include "basecharacter.h"

basecharacter::basecharacter(){


 
}

Vector2 basecharacter::getworldpos(){return worldpos;}

void basecharacter::undo(){
    worldpos=lastframe;
}

Rectangle basecharacter::getcollisionrec(){
    int padding{30};
    return Rectangle{
        pos.x+padding,pos.y+padding,
        scale*width - 2*padding,scale*height - 2*padding
    };
}