#include "raylib.h"
#include "raymath.h"

class prop{

    Vector2 worldpos{};
    Texture2D texture{};
    float scale{8.f};
    float padding{};

public:
    
    prop(Vector2 pos, Texture2D tex, float padding);

    void render(Vector2 knightpos);

    Rectangle getcollisionrec(Vector2 knightpos);
};