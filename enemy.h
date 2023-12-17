#pragma once

#include "basecharacter.h"
#include "character.h"

class enemy : public basecharacter{

    character* target;
    float damagepersec {10.f};

public:

    enemy(Vector2 position, Texture2D idle_tex, Texture2D run_tex);

    void settarget(character* targ);
    
    virtual void tick(float dt) override;

    virtual Vector2 getscreenpos() override;

};