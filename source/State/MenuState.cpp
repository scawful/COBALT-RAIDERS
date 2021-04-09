//  MenuState Class

#include "Manager.hpp"
#include "State.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"

MenuState MenuState::m_MenuState;

void MenuState::init( SDL_Renderer *zRenderer, SDL_Window *zWindow )
{
    this->zRenderer = zRenderer;
    this->zWindow = zWindow;

    // Load image at specified path
    std::string path = "romfs:/data/crystal.png";
    
    if ( !crystalTexture.loadFromFile( zRenderer, path ) )
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

        if ( !prototypeTexture.loadFromRenderedText( zRenderer, TTF_OpenFont( "romfs:/data/ARCADECLASSIC.TTF", 48 ), "Prototype  Version  01", fontColor ) )
        {
            SDL_Log("Failed to render text texture!\n");
        }

        if ( !startGameTexture.loadFromRenderedText( zRenderer, TTF_OpenFont( "romfs:/data/ARCADECLASSIC.TTF", 72 ), "Press any button to start!", fontColor ) )
        {
            SDL_Log("Failed to render text texture!\n");
        }
    }
}

void MenuState::cleanup()
{
    printf("MenuState Cleanup\n");
}

void MenuState::pause()
{
    printf("MenuState Pause\n");
}

void MenuState::resume()
{
    printf("MenuState Resume\n");
}

void MenuState::handleEvents( Manager* game )
{
    SDL_Event event;

    while ( SDL_PollEvent(&event) ) 
    {
        switch ( event.type ) 
        {
            case SDL_JOYAXISMOTION:
                SDL_Log("Joystick %d axis %d value: %d\n",
                        event.jaxis.which,
                        event.jaxis.axis, event.jaxis.value);
                break;

            case SDL_JOYBUTTONDOWN:
                SDL_Log("Joystick %d button %d down\n",
                        event.jbutton.which, event.jbutton.button);
                // https://github.com/devkitPro/SDL/blob/switch-sdl2/src/joystick/switch/SDL_sysjoystick.c#L52
                // seek for joystick #0
                if (event.jbutton.which == 0) 
                {
                    if (event.jbutton.button == 0) 
                    {
                        // (A) button down
                        game->change( GameState::instance() );

                    } 
                    else if ( event.jbutton.button == 1 )
                    {
                        // (b) button down
                        SDL_SetRenderDrawColor(this->zRenderer, 128, 0, 128, 255);
                    }
                    else if (event.jbutton.button == 10) 
                    {
                        // (+) button down
                        game->quit();
                    }
                    else if (event.jbutton.button == 11) 
                    {
                        // (-) button down
                        game->quit();
                    }
                }
                break;

            default:
                break;
        }
    }

    
}

void MenuState::update( Manager* game )
{
    //Clear screen
    SDL_RenderClear(this->zRenderer);
}

void MenuState::draw( Manager* game )
{
    // fill window bounds
    int w = 1920, h = 1080;
    SDL_SetRenderDrawColor(this->zRenderer, 200, 111, 111, 255);
    SDL_GetWindowSize(this->zWindow, &w, &h);
    SDL_Rect f = {0, 0, 1920, 1080};
    SDL_RenderFillRect(this->zRenderer, &f);

    statusTexture.render( zRenderer, (1920 - statusTexture.getWidth()) / 2,  100);
    prototypeTexture.render( zRenderer, (1920 - prototypeTexture.getWidth()) / 2,  200);
    crystalTexture.render( zRenderer, (1920 - crystalTexture.getWidth()) / 2,  275);
    startGameTexture.render( zRenderer, (1920 - startGameTexture.getWidth()) / 2, 800);

    SDL_RenderPresent(this->zRenderer);

    SDL_Delay(16);
}
