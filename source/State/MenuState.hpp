//  MenuState Class Header

#ifndef MenuState_hpp
#define MenuState_hpp

#include "State.hpp"

class MenuState : public State
{
public:
    void init(SDL_Renderer *zRenderer, SDL_Window *zWindow);
    void cleanup();

    void pause();
    void resume();

    void handleEvents(Manager* game);
    void update(Manager* game);
    void draw(Manager* game);

    static MenuState* instance()
    {
        return &m_MenuState;
    }

protected:
    MenuState() { }

private:
    static MenuState m_MenuState;
    
    SDL_Window *zWindow = NULL;
    SDL_Renderer *zRenderer = NULL;
    SDL_Texture *zTexture = NULL;
    TTF_Font *gFont = NULL;
    TTF_Font *menuFont = NULL;
    
};

#endif /* MenuState_hpp */
