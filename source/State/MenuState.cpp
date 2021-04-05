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
    int w = 1920, h = 1080;
    // fill window bounds
    SDL_SetRenderDrawColor(this->zRenderer, 200, 111, 111, 255);
    SDL_GetWindowSize(this->zWindow, &w, &h);
    SDL_Rect f = {0, 0, 1920, 1080};
    SDL_RenderFillRect(this->zRenderer, &f);

    SDL_RenderPresent(this->zRenderer);

    SDL_Delay(16);
}
