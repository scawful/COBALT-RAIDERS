//  Manager (State) Class

#include "Manager.hpp"
#include "State.hpp"

void Manager::init(int width, int height)
{
    romfsInit();
    this->zRenderer = zRenderer;
    this->zWindow = zWindow;
    m_running = true;
    
    const int SCREEN_WIDTH = width;
    const int SCREEN_HEIGHT = height;

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
            left_joycon = SDL_JoystickOpen( 0 );
            if ( left_joycon == NULL )
            {
                SDL_Log("SDL_JoystickOpen [LHS]: %s\n", SDL_GetError());
                SDL_Quit();
            }

            right_joycon = SDL_JoystickOpen( 1 );
            if ( right_joycon == NULL )
            {
                SDL_Log("SDL_JoystickOpen [RHS]: %s\n", SDL_GetError());
                SDL_Quit();
            }

        }
    }

}

void Manager::cleanup()
{
    while ( !states.empty() )
    {
        states.back()->cleanup();
        states.pop_back();
    }

    // Close the open joysticks
    SDL_JoystickClose( left_joycon );
    SDL_JoystickClose( right_joycon );

    // Close and destroy the window
    SDL_DestroyRenderer( zRenderer );
    SDL_DestroyWindow( zWindow );
    zWindow = NULL;
    zRenderer = NULL;
    
    // Final clean up
    romfsExit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Manager::change( State* state )
{
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->cleanup();
        states.pop_back();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->init( this->zRenderer, this->zWindow );
}

void Manager::push(State* state)
{
    // pause current state
    if ( !states.empty() ) {
        states.back()->pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->init( this->zRenderer, this->zWindow );
}

void Manager::pop()
{
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->cleanup();
        states.pop_back();
    }

    // resume previous state
    if ( !states.empty() ) {
        states.back()->resume();
    }
}

void Manager::handleEvents(const float& dt)
{
    // let the state handle events
    states.back()->handleEvents(this, dt);
}

void Manager::update(const float& dt)
{
    // let the state update the game
    states.back()->update(this, dt);
}

void Manager::draw()
{
    // let the state draw the screen
    states.back()->draw(this);
}
