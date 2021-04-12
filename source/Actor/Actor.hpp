//  Actor Class Header

#ifndef Actor_hpp
#define Actor_hpp

#include "../State/State.hpp"
#include "../Actor/Entity.hpp"
#include "../Sprite/Sprite.hpp"

class Actor : public Entity
{
private:
    

public:
    bool attacking;
    Actor( ZTexture& texture_sheet, SDL_Rect& rect, Vector2f position );
    virtual ~Actor();

    virtual void update( const float & dt );

    Sprite* getSprite()
    {
        return &sprite;
    }

    void setAttack();

};

#endif