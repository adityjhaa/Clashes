#include "raylib.h"
#include "raymath.h"

class prop{

    Texture2D texture{};
    Vector2 worldpos{};
    float scale{8.f};

public:
    prop();
};