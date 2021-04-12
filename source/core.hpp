// core class
// additional shit

#ifndef core_hpp
#define core_hpp

#include <SDL2/SDL.h>

class Vector2f
{
private:
    float value;

public:
    float x;
    float y;

    // default constructor
    Vector2f() { x = 0.0; y = 0.0; }
    Vector2f( const double x, const double y ) { }

    // scalar value
    Vector2f( float x ) : value(x) {}

    // default operations
    Vector2f operator+( const Vector2f& augend )
    {
        Vector2f sum = { this->x + augend.x, this->y + augend.y };
        return sum;
    }

    Vector2f operator*( const Vector2f& factor )
    {
        Vector2f product = { this->x * factor.x, this->y * factor.y };
        return product;
    }

    // scalar operations
    // Vector2f operator+( const Vector2f& right )
    // {
    //     value += right.value;
    //     return *this;
    // }

    // Vector2f operator*( const Vector2f& right )
    // {
    //     value *= right.value;
    //     return *this;
    // }
};

class DeltaClock
{
private:
    uint32_t start_time;
    uint32_t current_time;
    double   elapsed_time;

public:
    DeltaClock() 
    { 
        start_time = SDL_GetTicks();
    }

    // returns current time in seconds
    uint32_t getElapsedTime()
    {
        current_time = SDL_GetTicks();
        elapsed_time = (current_time - start_time) / 1000.0; 
        return current_time;
    }

    uint32_t restartClock()
    {
        uint32_t current = SDL_GetTicks();
        double elapsed = (current - start_time) / 1000.0;
        start_time = current;

        return elapsed;
    }
    
};

#endif