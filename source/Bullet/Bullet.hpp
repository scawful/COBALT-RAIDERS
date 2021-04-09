//  Bullet Class Header

#ifndef Bullet_hpp
#define Bullet_hpp

#include "../State/State.hpp"
#include "../Sprite/Sprite.hpp"

class Bullet
{
private:
    Sprite sprite;
    Vector2f velocity;

public:
    Bullet( ZTexture *texture, Vector2f velocity, Vector2f position, SDL_Rect rect )
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