#pragma once

#include "raylib.h"
#include "raymath.h"

class basecharacter{


protected:
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 pos{};
    Vector2 worldpos{};

    Vector2 lastframe{};

    float right_left{1.f};     // right - 1.0, left - -1.0

    float runningtime{};
    int frame{};
    int maxframes{6};
    float updatetime{1.f/12.f};
    float speed{8.f};
    float width{};
    float height{};

    int winwidth{},winheight{};

    float scale{8.f};

public:

    basecharacter();

    Vector2 getworldpos();

    Rectangle getcollisionrec();

    void undo();

};