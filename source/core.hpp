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
    Vector2f( float scalar ) : x(scalar), y(scalar) { }

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

inline bool operator!=( const SDL_Rect& a, const SDL_Rect& b )
{
    return a.x == b.x && a.y == b.y && a.w == b.w && a.h == b.h;
}

#endif