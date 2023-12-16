#include "raylib.h"
#include "raymath.h"

const int width=768, height=768;

class character{
    Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
    Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
    Vector2 pos{};
    Vector2 worldpos{};

    float right_left{1.f};     // right - 1.0, left - -1.0

    float runningtime{};
    int frame{};
    const int maxframes{6};
    const float updatetime{1.f/12.f};
    const float speed{8.f};
public:

    Vector2 getworldpos(){return worldpos;}
    void setpos();
    void tick(float dt);
};

void character::setpos(){
    pos = {(float)width/2.0f - 2.f*(float)texture.width/3.0f,
            (float)height/2.0f - 4.f*(float)texture.height};
}

void character::tick(float dt){
    Vector2 direction{};
    if(IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)){direction.x -= 1.0;}
    if(IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)){direction.x += 1.0;}
    if(IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)){direction.y -= 1.0;}
    if(IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)){direction.y += 1.0;}
    
    if(Vector2Length(direction)!=0.0){
        
        worldpos = Vector2Add(worldpos,Vector2Scale(Vector2Normalize(direction),speed));
        
        direction.x < 0.f ? right_left=-1.f : right_left=1.f;

        texture = run;
    }else{
        texture = idle;
    }

    runningtime += dt;
    if(runningtime>=updatetime){
        runningtime=0.f;
        frame++;
        frame = frame%maxframes;
    }
    
    Rectangle source{frame * (float)texture.width/6.f,0.f,right_left*(float)texture.width/6.f, (float)texture.height};
    Rectangle dest{pos.x,pos.y,8.f*(float)texture.width/6.f, 8.f*(float)texture.height};
    DrawTexturePro(texture,source,dest,Vector2{},0.0,WHITE);

}

int main(){

    InitWindow(width,height,"CLASH!!");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap.png");
    Vector2 mappos{0.0,0.0};


    character knight;
    knight.setpos();

    
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