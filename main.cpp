#include "raylib.h"
#include "raymath.h"

const int width=768, height=768;

int main(){

    InitWindow(width,height,"CLASH!!");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap.png");
    // float mapx{}, mapy{};

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 mappos{0.0,0.0};
        DrawTextureEx(map,mappos,0.0,8.0,WHITE);
        

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}