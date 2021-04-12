// delta ...

#ifndef Delta_hpp
#define Delta_hpp

#include <SDL2/SDL.h>

class DeltaClock
{
private:
    uint32_t start_time;
    uint32_t current_time;
    float   elapsed_time;

public:
    DeltaClock() 
    { 
        start_time = SDL_GetTicks();
        SDL_Log("DeltaClock initialized :: %d", start_time);
    }

    // returns current time in seconds
    float getElapsedTime()
    {
        current_time = SDL_GetTicks();
        elapsed_time = (current_time - start_time) / 1000.0; 
        return current_time;
    }

    float restartClock()
    {
        uint32_t current = SDL_GetTicks();
        double elapsed = (current - start_time) / 1000.0;
        start_time = current;

        return elapsed;
    }
    
};

float delta_time;

#endif