#include "character.h"

character::character(){
    
}

Vector2 character::getworldpos(){return worldpos;}

void character::setpos(int width, int height){
    pos = {(float)width/2.0f - 2.f*(float)texture.width/3.0f,
            (float)height/2.0f - 4.f*(float)texture.height};
}

void character::tick(float dt){
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
    
    Rectangle source{frame * (float)texture.width/6.f,0.f,right_left*(float)texture.width/6.f, (float)texture.height};
    Rectangle dest{pos.x,pos.y,8.f*(float)texture.width/6.f, 8.f*(float)texture.height};
    DrawTexturePro(texture,source,dest,Vector2{},0.0,WHITE);

}