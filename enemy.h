#include "basecharacter.h"

class enemy : public basecharacter{


public:

    enemy(Vector2 position, Texture2D idle_tex, Texture2D run_tex);


    
    void tick(float dt);

};