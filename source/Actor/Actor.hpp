//  Actor Class Header

#ifndef Actor_hpp
#define Actor_hpp

#include "../State/State.hpp"
#include "../Actor/Entity.hpp"
#include "../Sprite/Sprite.hpp"

class Actor : public Entity
{
private:
    Sprite sprite;
    Vector2f velocity;

public:
    Actor( ZTexture *texture, Vector2f velocity, Vector2f position, SDL_Rect rect )
    {
        this->velocity = velocity;
        sprite.setTexture( *texture );
        sprite.setTextureRect( rect );
        sprite.setPosition( position );
    }

    void update( double timeElapsed )
    {
        Vector2f newPos = { sprite.getPosition().x + timeElapsed * velocity.x,
                            sprite.getPosition().y + timeElapsed * velocity.y };
                    
        sprite.setPosition( newPos );
    }

    Sprite* getSprite()
    {
        return &sprite;
    }

};

#endif