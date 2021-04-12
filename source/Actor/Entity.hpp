//  Entity.hpp

#ifndef Entity_hpp
#define Entity_hpp

#include "../Components/Movement.hpp"

class Entity 
{
private:    
    
protected:
    Sprite sprite;

    MovementComponent* movementComponent;
    
public:
    Entity();
    virtual ~Entity();
    
    // Component Functions
    void setTexture(ZTexture& texture);
    void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
    
    // Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y, const float& dt);
    
    virtual void update(const float& dt);
    virtual void render(SDL_Renderer *zRenderer);
};

#endif /* Entity_hpp */
