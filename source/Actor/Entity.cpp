//  Entity.cpp

#include "Entity.hpp"

Entity::Entity() 
{
    this->movementComponent = NULL;
    this->animationComponent = NULL;
}

Entity::~Entity() 
{
    delete this->movementComponent;
    delete this->animationComponent;
}


void Entity::setTexture(ZTexture& texture) 
{
    this->sprite.setTexture(texture);
}

void Entity::createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration) 
{
    this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimatiomComponent(ZTexture & texture_sheet)
{
    this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

// void Entity::createHitboxComponent(Sprite& sprite, float offset_x, float offset_y,
//                                    float width, float height) {
//     this->hitboxComponent = new HitboxComponent(sprite, offset_x, offset_y, width, height);
// }

// Functions
void Entity::setPosition( const float x, const float y )
{
    Vector2f newPosition = { x, y };
    this->sprite.setPosition( newPosition );
}

void Entity::move( const float dir_x, const float dir_y, const float& dt )
{
    if ( this->movementComponent ) 
    {
        this->movementComponent->move(dir_x, dir_y, dt); // sets velocity
    }
}

void Entity::update( const float & dt ) 
{
    
}

void Entity::render( SDL_Renderer *zRenderer, SDL_Rect *dstRect ) 
{
    SDL_RenderCopy( zRenderer, this->sprite.getRawTexture(), this->sprite.getTextureRect(),  dstRect );
    //this->sprite.render( zRenderer, this->sprite.getPosition().x, this->sprite.getPosition().y );
        // target.draw(this->sprite); zRenderer
    
        // if(this->hitboxComponent)
        //     this->hitboxComponent->render(target);
}
