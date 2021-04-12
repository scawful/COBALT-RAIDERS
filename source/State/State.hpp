// State Class Header

#ifndef State_hpp
#define State_hpp

#include "../core.hpp"
#include "Manager.hpp"

class State
{
public:
    virtual void init(SDL_Renderer *zRenderer, SDL_Window *zWindow) = 0;
    virtual void cleanup() = 0;
    
    virtual void pause() = 0;
    virtual void resume() = 0;
    
    virtual void handleEvents(Manager *game, const float& dt) = 0;
    virtual void update(Manager *game, const float& dt) = 0;
    virtual void draw(Manager *game) = 0;
    
    void changeState(Manager *game, State *state)
    {
        game->change(state);
    }
    
protected:
    State() { }
};

#endif /* State_hpp */
