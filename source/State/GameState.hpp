//  MenuState Class Header

#ifndef GameState_hpp
#define GameState_hpp

#include "State.hpp"
#include "../Graphics/Texture.hpp"
#include "../Bullet/Bullet.hpp"


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

    TTF_Font *statusFont = NULL;
    TTF_Font *menuFont = NULL;

    ZTexture zBackgroundTexture;
    ZTexture statusTexture;
    ZTexture startGameTexture;
    ZTexture prototypeTexture;

    ZTexture bulletTexture;
    
    Bullet* redBullet;
    SDL_Rect redBulletRect;
    
};

#endif /* MenuState_hpp */
