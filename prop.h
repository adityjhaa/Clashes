#include "raylib.h"
#include "raymath.h"

class prop{

    Vector2 worldpos{};
    Texture2D texture{};
    float scale{8.f};

public:
    
    prop(Vector2 pos, Texture2D tex);

    void render(Vector2 knightpos);

    Rectangle getcollisionrec(Vector2 knightpos);
};