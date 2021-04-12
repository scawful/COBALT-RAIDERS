//  Actor.cpp

#include "Actor.hpp"

Actor::Actor ( ZTexture *texture, Vector2f velocity, Vector2f position, SDL_Rect rect ) 
{
    this->getSprite()->setPosition(position);
    
    //this->createHitboxComponent(this->sprite, 40.f, 15.f, 60.f, 70.f);
    this->createMovementComponent(350.f, 15.f, 5.f);
    //this->createAnimatiomComponent(texture_sheet);
    
    // this->animationComponent->addAnimation("IDLE_RIGHT", 11.f, 0, 0, 3, 0, 156, 100);
    // this->animationComponent->addAnimation("WALK_RIGHT", 7.f, 0, 1, 3, 1, 156, 100);
    // this->animationComponent->addAnimation("ATTACK", 7.f, 0, 2, 4, 2, 156, 100);
    // this->animationComponent->addAnimation("IDLE_LEFT", 7.f, 0, 2, 3, 2, 88, 100);
    // this->animationComponent->addAnimation("WALK_LEFT", 100.f, 0, 3, 3, 3, 88, 100);
}

Actor::~Actor() {
    
}

void Actor::update(const float & dt) {
    
    this->movementComponent->update(dt);
    
    if (this->movementComponent->getState(IDLE))
    {
        this->animationComponent->play("IDLE_RIGHT", dt);
    }
    else if (this->movementComponent->getState(MOVING_RIGHT))
    {
        this->sprite.setOrigin(0.f, 0.f);
        this->sprite.setScale(1.f, 1.f);
        this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
    }
    else if (this->movementComponent->getState(MOVING_LEFT))
    {
        this->sprite.setOrigin(150.f, 0.f);
        this->sprite.setScale(-1.f, 1.f);
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
    
    this->hitboxComponent->update();
}
