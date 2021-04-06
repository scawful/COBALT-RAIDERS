//  GameState.cpp
//  SDL

#include "GameState.hpp"
#include "MenuState.hpp"
#include "../Bullet/Bullet.hpp"

GameState GameState::m_GameState;

void GameState::init( SDL_Renderer *zRenderer, SDL_Window *zWindow )
{
    this->zRenderer = zRenderer;
    
    // ===============================================================================
    // Load image at specified path
    std::string path = "romfs:/data/space_bg.png";
    
    if ( !zBackgroundTexture.loadFromFile( zRenderer, path ) )
    {
        SDL_Log( "Failed to load texture image!\n" );
    }
    
    SDL_Color fontColor = { 255, 255, 255 };
    statusFont = TTF_OpenFont( "romfs:/data/ARCADECLASSIC.TTF", 128 );
    if ( statusFont == NULL )
    {
        SDL_Log( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        if ( !statusTexture.loadFromRenderedText( zRenderer, statusFont, "Cobalt Raiders NX", fontColor ) )
        {
            SDL_Log("Failed to render text texture!\n");
        }
    }

    // ===============================================================================
    
    SDL_Log("GameState Initialization\n");
}

void GameState::cleanup()
{
    // Free loaded images and fonts
    zBackgroundTexture.free();
}

void GameState::pause()
{
    SDL_Log("GameState Pause\n");
}

void GameState::resume()
{
    SDL_Log("GameState Resume\n");
}

void GameState::handleEvents( Manager *game )
{
    SDL_Event event;

    while ( SDL_PollEvent(&event) ) 
    {
        switch (event.type) 
        {
            case SDL_JOYBUTTONDOWN:
                if (event.jbutton.which == 0) 
                {
                    if (event.jbutton.button == 0) 
                    {
                        // (A) button down
                        game->change( MenuState::instance() );
                    } 
                    else if (event.jbutton.button == 10) 
                    {
                        // (+) button down
                        game->quit();
                    }
                }
                break;

            default:
                break;
        }
    }
}

void GameState::update( Manager *game )
{
    SDL_RenderClear( zRenderer );
}

void GameState::draw( Manager *game )
{
    zBackgroundTexture.render( zRenderer, 0, 0 );
    //statusTexture.render( zRenderer, (1920 - statusTexture.getWidth()) - (1920 / 4),  83);
    statusTexture.render( zRenderer, (1920 - statusTexture.getWidth()) / 2,  100);

    SDL_RenderPresent( zRenderer );
    SDL_Delay(16);
}
