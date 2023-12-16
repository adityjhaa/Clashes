#include "character.h"
#include "prop.h"


const int width=768, height=768;

int main(){

    InitWindow(width,height,"CLASH!!");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 mappos{0.0,0.0};

    const float scale = 8.f;

    character knight{width,height};


    prop props[2]{
        prop{Vector2{1200.f,600.f},LoadTexture("nature_tileset/Rock.png")},
        prop{Vector2{2000.f,1200.f},LoadTexture("nature_tileset/Log.png")}
    };
    
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        
        BeginDrawing();
        ClearBackground(WHITE);

        mappos = Vector2Scale(knight.getworldpos(),-1.f);

        DrawTextureEx(map,mappos,0.0,scale,WHITE);

        for(auto p : props){
            p.render(knight.getworldpos());
        }

        knight.tick(GetFrameTime());

        if(knight.getworldpos().x < 0.f or
            knight.getworldpos().y < 0.f or
            knight.getworldpos().x + width > map.width*scale or
            knight.getworldpos().y + height > map.height*scale)
            {
            
            knight.undo();
        }

        for(auto p:props){
            if(CheckCollisionRecs(knight.getcollisionrec(),p.getcollisionrec(knight.getworldpos()))){
                knight.undo();
            }
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}