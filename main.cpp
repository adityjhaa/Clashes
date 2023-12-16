#include "character.h"
#include "prop.h"


const int width=768, height=768;

int main(){

    InitWindow(width,height,"CLASH!!");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 mappos{0.0,0.0};

    const float scale = 8.f;

    character knight{width,height};

    
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        
        BeginDrawing();
        ClearBackground(WHITE);

        mappos = Vector2Scale(knight.getworldpos(),-1.f);

        DrawTextureEx(map,mappos,0.0,scale,WHITE);
        knight.tick(GetFrameTime());

        if(knight.getworldpos().x < 0.f or
            knight.getworldpos().y < 0.f or
            knight.getworldpos().x + width > map.width*scale or
            knight.getworldpos().y + height > map.height*scale)
            {
            
            knight.undo();
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}