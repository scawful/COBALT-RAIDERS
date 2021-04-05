//  MenuState Class Header

#ifndef GameState_hpp
#define GameState_hpp

#include "State.hpp"

class GameState : public State
{
public:
    void init(SDL_Renderer *zRenderer, SDL_Window *zWindow);
    void cleanup();

    void pause();
    void resume();

    void handleEvents(Manager* game);
    void update(Manager* game);
    void draw(Manager* game);

    static GameState* instance()
    {
        return &m_GameState;
    }

protected:
    GameState() { }

private:
    static GameState m_GameState;
    
    SDL_Window *zWindow = NULL;
    SDL_Renderer *zRenderer = NULL;
    SDL_Texture *backgroundTexture = NULL;

    TTF_Font *gFont = NULL;
    TTF_Font *menuFont = NULL;
    
};

#endif /* MenuState_hpp */
