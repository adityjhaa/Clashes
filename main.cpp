#include "character.h"
#include "prop.h"
#include "enemy.h"
#include <string>

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

    enemy goblin{Vector2{},LoadTexture("characters/goblin_idle_spritesheet.png"),LoadTexture("characters/goblin_run_spritesheet.png")};
    goblin.settarget(&knight);

    bool startplay{false};

    while(!startplay){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("WELCOME!",200,200,80,GREEN);
        DrawText("<SPACE> to PLAY",220,600,40,RED);
        if(IsKeyPressed(KEY_SPACE)){startplay=true;}
        EndDrawing();
    }
    

    SetTargetFPS(60);
    while(!WindowShouldClose()){
        if(knight.getalive()){
            BeginDrawing();
            ClearBackground(WHITE);


            mappos = Vector2Scale(knight.getworldpos(),-1.f);

            DrawTextureEx(map,mappos,0.0,scale,WHITE);

            std::string heal = "HEALTH : ";
            heal.append(std::to_string(knight.gethealth()),0,5);    

            DrawText(heal.c_str(),500,20,35,BLACK);

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

            goblin.tick(GetFrameTime());

            if(IsKeyPressed(KEY_SPACE)){
                if(CheckCollisionRecs(goblin.getcollisionrec(),knight.getweaponcollisionrec())){
                    goblin.setalive(false);
                }
            }
        }else{
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("GAME OVER!",180,350,80,RED);
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}