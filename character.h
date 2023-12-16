#include "raylib.h"
#include "raymath.h"
class character{
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 pos{};
    Vector2 worldpos{};

    float right_left{1.f};     // right - 1.0, left - -1.0

    float runningtime{};
    int frame{};
    const int maxframes{6};
    const float updatetime{1.f/12.f};
    const float speed{8.f};
public:
    character();
    Vector2 getworldpos();
    void setpos(int width, int height);
    void tick(float dt);
};