//  MenuState Class Header

#ifndef GameState_hpp
#define GameState_hpp

#include "State.hpp"
#include "../Graphics/Texture.hpp"
#include "../Actor/Actor.hpp" 
#include "../Bullet/Bullet.hpp"


class GameState : public State
{
private:
    static GameState m_GameState;
    
    std::map<std::string, ZTexture> textures;

    SDL_Window *zWindow = NULL;
    SDL_Renderer *zRenderer = NULL;

    TTF_Font *statusFont = NULL;
    TTF_Font *menuFont = NULL;

    ZTexture zBackgroundTexture;
    ZTexture statusTexture;
    ZTexture startGameTexture;
    ZTexture prototypeTexture;
    ZTexture bulletTexture;

    Actor* actor;
    SDL_Rect actorRect;
    
    Bullet* redBullet;
    SDL_Rect redBulletRect;

protected:
    GameState() { }
    
public:
    void loadTextures();
    void createActor();
    void init(SDL_Renderer *zRenderer, SDL_Window *zWindow);
    void cleanup();

    void pause();
    void resume();

    void updateActorInput(SDL_Event *event);

    void handleEvents(Manager* game, const float& dt);
    void update(Manager* game, const float& dt);
    void draw(Manager* game);

    static GameState* instance()
    {
        return &m_GameState;
    }

};

#endif /* MenuState_hpp */
