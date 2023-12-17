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
        getscreenpos().x+padding,getscreenpos().y+padding,
        scale*width - 2*padding,scale*height - 2*padding
    };
}

void basecharacter::tick(float dt){

    lastframe = worldpos;
    
    runningtime += dt;
    if(runningtime>=updatetime){
        runningtime=0.f;
        frame++;
        frame = frame%maxframes;
    }

    if(Vector2Length(velocity)!=0.0){
        
        worldpos = Vector2Add(worldpos,Vector2Scale(Vector2Normalize(velocity),speed));
        
        velocity.x < 0.f ? right_left=-1.f : right_left=1.f;

        texture = run;
    }else{
        texture = idle;
    }
    velocity = {};
    
    
    
    Rectangle source{frame * width,0.f,right_left*width, height};
    Rectangle dest{getscreenpos().x,getscreenpos().y,scale*width, scale*height};
    DrawTexturePro(texture,source,dest,Vector2{},0.0,WHITE);

}