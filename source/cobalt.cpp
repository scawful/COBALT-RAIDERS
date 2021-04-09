// Program: Cobalt Raiders
// Author: scawful
// Date Created: 04/04/2021
// Platform: Nintendo Switch
// Toolchain: DEVKITPROA64
// Dependencies: SDL2, SDL2_image, SDL2_ttf

#include "State/Manager.hpp"
#include "State/MenuState.hpp"
#include "State/GameState.hpp"


int main (int argc, char* argv[])
{
    // Console debug for Ryujinx
    consoleDebugInit(debugDevice_SVC);

    SDL_Renderer *zRenderer = NULL;
    SDL_Window *zWindow = NULL;
    
    const int SCREEN_WIDTH = 1920;
    const int SCREEN_HEIGHT = 1080;

    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ) )
    {
        SDL_Log("SDL_Init: %s\n", SDL_GetError() );
    }
    else
    {
        zWindow = SDL_CreateWindow(
            "Cobalt Raiders",                   // window title
            SDL_WINDOWPOS_UNDEFINED,            // initial x position
            SDL_WINDOWPOS_UNDEFINED,            // initial y position
            SCREEN_WIDTH,                       // width, in pixels
            SCREEN_HEIGHT,                      // height, in pixels
            0                                   // flags - see below
        );
        
        if ( zWindow == NULL )
        {
            SDL_Log("SDL_CreateWindow: %s\n", SDL_GetError());
            SDL_Quit();
        }
        else
        {
            zRenderer = SDL_CreateRenderer( zWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( zRenderer == NULL )
            {
                SDL_Log("SDL_CreateRenderer: %s\n", SDL_GetError());
                SDL_Quit();
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( zRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    SDL_Log("Error initializing SDL_Image: %s\n", IMG_GetError());
                }
                
                if ( TTF_Init() == -1 )
                {
                    SDL_Log("Error initializing SDL_ttf: %s\n", TTF_GetError());
                }
            }

            // Opening two controllers, accounting for each joycon
            for (int i = 0; i < 2; i++) 
            {
                if (SDL_JoystickOpen(i) == NULL) {
                    SDL_Log("SDL_JoystickOpen: %s\n", SDL_GetError());
                    SDL_Quit();
                }
            }

        }
    }

    // state manager creation
    Manager game;
    game.init( zRenderer, zWindow );

    // default state
    game.change( MenuState::instance() );
    
    // main loop
    while ( game.running() )
    {
        game.handleEvents();
        game.update();
        game.draw();
    }

    // cleanup the engine
    game.cleanup();

    return 0;
}
