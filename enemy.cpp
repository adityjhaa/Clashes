#include "enemy.h"

enemy::enemy(Vector2 position, Texture2D idle_tex, Texture2D run_tex){

    worldpos=position;
    texture=idle=idle_tex;
    run=run_tex;
    width = texture.width/static_cast<float>(maxframes);
    height = texture.height;
}


 
void enemy::tick(float dt){
    lastframe=worldpos;

    runningtime += dt;
    if(runningtime>=updatetime){
        runningtime=0.f;
        frame++;
        frame = frame%maxframes;
    }

    
    Rectangle source{frame * width,0.f,right_left*width, height};
    Rectangle dest{pos.x,pos.y,scale*width, scale*height};
    DrawTexturePro(texture,source,dest,Vector2{},0.0,WHITE);
}
