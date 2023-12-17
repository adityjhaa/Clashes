#include "enemy.h"

enemy::enemy(Vector2 position, Texture2D idle_tex, Texture2D run_tex){

    worldpos=position;
    texture=idle=idle_tex;
    run=run_tex;
    width = texture.width/static_cast<float>(maxframes);
    height = texture.height;
    speed = 7.f;
}


 
void enemy::tick(float dt){

    if(!getalive()){return;}

    velocity = Vector2Subtract(target->getscreenpos(),getscreenpos());
    if(Vector2Length(velocity) < radius){velocity={};}
    basecharacter::tick(dt);

    if(CheckCollisionRecs(target->getcollisionrec(),getcollisionrec())){
        target->takedamage(damagepersec*dt);
    }

}

Vector2 enemy::getscreenpos(){
    return {Vector2Subtract(worldpos,target->getworldpos())};
}

void enemy::settarget(character* targ){
    target=targ;
}
