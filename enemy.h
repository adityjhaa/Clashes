#include "basecharacter.h"

class enemy : public basecharacter{
    Vector2 worldpos{};
    Texture2D texture{};
    Texture2D idle{};
    Texture2D run{};
    Vector2 pos{};

    Vector2 lastframe{};

    float right_left{1.f};     // right - 1.0, left - -1.0

    float runningtime{};
    int frame{};
    int maxframes{6};
    float updatetime{1.f/12.f};
    float speed{8.f};
    float width{};
    float height{};

    int winwidth{},winheight{};

    float scale{8.f};


public:

    enemy(Vector2 position, Texture2D idle_tex, Texture2D run_tex);

    Vector2 getworldpos();
    
    void tick(float dt);

    Rectangle getcollisionrec();

    void undo();

};