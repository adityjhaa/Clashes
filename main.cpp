#include "character.h"

const int width=768, height=768;

int main(){

    InitWindow(width,height,"CLASH!!");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 mappos{0.0,0.0};


    character knight;
    knight.setpos(width,height);

    
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        
        BeginDrawing();
        ClearBackground(WHITE);

        mappos = Vector2Scale(knight.getworldpos(),-1.f);

        DrawTextureEx(map,mappos,0.0,8.0,WHITE);
        knight.tick(GetFrameTime());

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}