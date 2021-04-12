//  Actor.cpp

#include "Actor.hpp"

Actor::Actor ( ZTexture& texture_sheet, SDL_Rect& rect, Vector2f position ) 
{
    this->attacking = false;
    sprite.setTexture( texture_sheet );
    sprite.setTextureRect( rect );
    sprite.setPosition( position );
    
    //this->createHitboxComponent(this->sprite, 40.f, 15.f, 60.f, 70.f);
    this->createMovementComponent(350.f, 15.f, 5.f);
    this->createAnimatiomComponent(texture_sheet);
    
    this->animationComponent->addAnimation("IDLE_RIGHT", 11.f, 0, 0, 5, 0, 72, 84);
    this->animationComponent->addAnimation("WALK_RIGHT", 7.f, 0, 1, 7, 1, 72, 84);
    this->animationComponent->addAnimation("WALK_LEFT", 7.f, 0, 2, 7, 2, 72, 84);
    this->animationComponent->addAnimation("SPELL_CAST", 7.f, 0, 3, 11, 3, 72, 84);
}

Actor::~Actor() {
    
}

void Actor::update( const float & dt ) 
{
    
    this->movementComponent->update(dt);

    if (this->attacking)
    {
        SDL_Log("attack!");
        if ( this->animationComponent->play("SPELL_CAST", dt, true) )
            this->attacking = false;
    }
    
    if (this->movementComponent->getState(IDLE))
    {
        this->animationComponent->play("IDLE_RIGHT", dt);
    }
    else if (this->movementComponent->getState(MOVING_RIGHT))
    {
        this->sprite.setOrigin( Vector2f(0.f, 0.f) );
        this->sprite.setScale( Vector2f(1.f, 1.f) );
        this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }
    else if (this->movementComponent->getState(MOVING_LEFT))
    {
        this->sprite.setOrigin( Vector2f(150.f, 0.f) );
        this->sprite.setScale( Vector2f(-1.f, 1.f) );
        this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }
    else if (this->movementComponent->getState(MOVING_UP))
    {
        this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }
    else if (this->movementComponent->getState(MOVING_DOWN))
    {
        this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
    }
    
    //this->hitboxComponent->update();
}

void Actor::setAttack()
{
    this->attacking = true;
}
