#include "character.h"

character::character(int winwidth, int winheight):
winwidth(winwidth), winheight(winheight)
{
    width = texture.width/static_cast<float>(maxframes);
    height = texture.height;

    
    
    speed = 10.f;
}

Vector2 character::getscreenpos(){
    return Vector2{
        static_cast<float>(winwidth)/2.0f - scale*0.5f*width,
        static_cast<float>(winheight)/2.0f - scale*0.5f*height
    };
}


void character::tick(float dt){

    if(!getalive()){return;}

    if(IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)){velocity.x -= 1.0;}
    if(IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)){velocity.x += 1.0;}
    if(IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)){velocity.y -= 1.0;}
    if(IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)){velocity.y += 1.0;}

    basecharacter::tick(dt);

    float rotation{};

    Vector2 origin{};
    Vector2 offset{};
    if(right_left>0.f){
        origin = {0.f,weapon.height*scale};
        offset = {80.f,110.f};
        weaponcollisionrec={
            getscreenpos().x+offset.x,
            getscreenpos().y+offset.y-weapon.height*scale,
            weapon.width*scale,
            weapon.height*scale
        };

        rotation = IsKeyDown(KEY_SPACE) ? 30.f : 0.f;

    }else{
        origin = {weapon.width*scale,weapon.height*scale};
        offset = {48.f,110.f};
        weaponcollisionrec={
            getscreenpos().x+offset.x-weapon.width*scale,
            getscreenpos().y+offset.y-weapon.height*scale,
            weapon.width*scale,
            weapon.height*scale
        };

        rotation = IsKeyDown(KEY_SPACE) ? -30.f : 0.f;
    }

    Rectangle source{0.f,0.f,static_cast<float>(weapon.width)*right_left,static_cast<float>(weapon.height)};
    Rectangle dist{getscreenpos().x + offset.x,getscreenpos().y + offset.y ,weapon.width*scale, weapon.height*scale};
    DrawTexturePro(weapon,source,dist,origin,rotation, WHITE);

 
}


void character::takedamage(float damage){
    health-=damage;
    if(health<=0.f){
        setalive(false);
    }
}