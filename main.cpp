#include "raylib.h"
#include "raymath.h"

const int width=768, height=768;

int main(){

    InitWindow(width,height,"CLASH!!");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 mappos{0.0,0.0};

    float speed = 10.0;

    Texture2D knight_idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D knight_run = LoadTexture("characters/knight_run_spritesheet.png");
    
    Texture2D knight = knight_idle;

    Vector2 knightpos{(float)width/2.0f - 2.f*(float)knight.width/3.0f,
                    (float)height/2.0f - 4.f*(float)knight.height};
    // right - 1.0, left - -1.0
    float right_left{1.f};

    float runningtime{};
    int frame{};
    const int maxframes{6};
    const float updatetime{1.f/12.f};
    
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if(IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)){direction.x -= 1.0;}
        if(IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)){direction.x += 1.0;}
        if(IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)){direction.y -= 1.0;}
        if(IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)){direction.y += 1.0;}
        
        if(Vector2Length(direction)!=0.0){
            
            mappos = Vector2Subtract(mappos,Vector2Scale(Vector2Normalize(direction),speed));
            
            direction.x < 0.f ? right_left=-1.f : right_left=1.f;

            knight = knight_run;
        }else{
            knight = knight_idle;
        }

        DrawTextureEx(map,mappos,0.0,8.0,WHITE);

        runningtime += GetFrameTime();
        if(runningtime>=updatetime){
            runningtime=0.f;
            frame++;
            frame = frame%maxframes;
        }
        
        Rectangle source{frame * (float)knight.width/6.f,0.f,right_left*(float)knight.width/6.f, (float)knight.height};
        Rectangle dest{knightpos.x,knightpos.y,8.f*(float)knight.width/6.f, 8.f*(float)knight.height};
        DrawTexturePro(knight,source,dest,Vector2{},0.0,WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
    CloseWindow();

    return 0;
}