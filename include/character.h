#pragma once

#include "basecharacter.h"


class character : public basecharacter{
    int winwidth{},winheight{};

    Texture2D weapon{LoadTexture("characters/weapon_sword.png")};
    Rectangle weaponcollisionrec{};
    float health{100.f};

public:
    character(int winwidth,int winheight);
    
    virtual void tick(float dt) override;

    virtual Vector2 getscreenpos() override;

    Rectangle getweaponcollisionrec(){return weaponcollisionrec;}

    float gethealth()const {return health;}
    void takedamage(float damage);
};