#include "basecharacter.h"


class character : public basecharacter{
    

public:
    character(int winwidth,int winheight);
    
    void tick(float dt);

};