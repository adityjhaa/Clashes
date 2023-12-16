#include "character.h"

character::character(int winwidth, int winheight){
    width = texture.width/(float)maxframes;
    height = texture.height;

    pos = {static_cast<float>(winwidth)/2.0f - scale*0.5f*width,
            static_cast<float>(winheight)/2.0f - scale*0.5f*height};
}

Vector2 character::getworldpos(){return worldpos;}


void character::tick(float dt){

    lastframe = worldpos;

    Vector2 direction{};
    if(IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)){direction.x -= 1.0;}
    if(IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)){direction.x += 1.0;}
    if(IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)){direction.y -= 1.0;}
    if(IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)){direction.y += 1.0;}
    
    if(Vector2Length(direction)!=0.0){
        
        worldpos = Vector2Add(worldpos,Vector2Scale(Vector2Normalize(direction),speed));
        
        direction.x < 0.f ? right_left=-1.f : right_left=1.f;

        texture = run;
    }else{
        texture = idle;
    }

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

void character::undo(){
    worldpos=lastframe;
}