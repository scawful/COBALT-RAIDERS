// Movement Component Class Header

#ifndef MovementComponent_hpp
#define MovementComponent_hpp

#include "../Sprite/Sprite.hpp"

enum movement_states { IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN };

class MovementComponent {
private:
    // Variables
    Sprite& sprite;
    
    float maxVelocity;    
    float acceleration;
    float deceleration;
    
    Vector2f velocity;

    
    // Initializer functions
    
public:
    MovementComponent(Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
    virtual ~MovementComponent();
    
    // Accessors
    const float& getMaxVelocity() const;
    const Vector2f& getVelocity() const;
    
    // Functions
    const bool getState(const short unsigned state) const;
    
    void move(const float x, const float y, const float& dt);
    void update(const float& dt);
    
};

#endif /* MovementComponent_hpp */
