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


    prop props[]{
        prop{Vector2{1200.f,600.f},LoadTexture("nature_tileset/Rock.png"),{}},
        prop{Vector2{2000.f,1200.f},LoadTexture("nature_tileset/Log.png"),{}},
        prop{Vector2{4900.f,4600.f},LoadTexture("nature_tileset/Bush.png"),{25.f}},
        prop{Vector2{1000.f,5100.f},LoadTexture("nature_tileset/Rock.png"),{}},
        prop{Vector2{4800.f,1600.f},LoadTexture("nature_tileset/Log.png"),{}},
        prop{Vector2{2500.f,3400.f},LoadTexture("nature_tileset/Bush.png"),{25.f}},
    };

    enemy goblin1{Vector2{1700.f,1800.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")};

    enemy slime1{Vector2{1200.f,3000.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")};

    enemy goblin2{Vector2{5700.f,900.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")};

    enemy slime2{Vector2{4200.f,5000.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")};

    enemy goblin3{Vector2{700.f,4900.f},
        LoadTexture("characters/goblin_idle_spritesheet.png"),
        LoadTexture("characters/goblin_run_spritesheet.png")};

    enemy slime3{Vector2{3200.f,4000.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")};


    enemy * enemies[]={
        &goblin1,&slime1,&goblin2,&slime2,&goblin3,&slime3
    };

    for(auto enemy : enemies){
        enemy->settarget(&knight);
    }

    bool startplay{false};
    while(!startplay){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText("CLASSIC",215,200,80,GREEN);
        DrawText("CLASH",255,280,80,GREEN);
        
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

            for(auto enemy: enemies){
                enemy->tick(GetFrameTime());
            
                if(IsKeyPressed(KEY_SPACE)){
                    if(CheckCollisionRecs(enemy->getcollisionrec(),knight.getweaponcollisionrec())){
                        enemy->setalive(false);
                    }
                }
            }

            bool win{true};
            for(auto enemy: enemies){
                win = win and !enemy->getalive();
            }

            if(win){
                DrawText("YOU WIN!",200,150,80,BLACK);
            }
        }else{
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("GAME OVER!",150,350,80,RED);
        }

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}