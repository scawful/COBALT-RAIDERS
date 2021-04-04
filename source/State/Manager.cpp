//  Manager (State) Class

#include "Manager.hpp"
#include "State.hpp"

void Manager::init(SDL_Renderer *zRenderer,
                   SDL_Window *zWindow,
                   int width, int height,
                   bool fullscreen)
{
    this->zRenderer = zRenderer;
    this->zWindow = zWindow;
    m_running = true;
    m_fullscreen = fullscreen;
}

void Manager::cleanup()
{
    while ( !states.empty() )
    {
        states.back()->cleanup();
        states.pop_back();
    }
    
    if ( m_fullscreen )
    {
        SDL_SetWindowFullscreen( zWindow, SDL_WINDOW_OPENGL );
    }
    
    // Close and destroy the window
    SDL_DestroyRenderer( zRenderer );
    SDL_DestroyWindow( zWindow );
    zWindow = NULL;
    zRenderer = NULL;
    
    // Final clean up
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


void Manager::handleEvents()
{
    // let the state handle events
    states.back()->handleEvents(this);
}

void Manager::update()
{
    // let the state update the game
    states.back()->update(this);
}

void Manager::draw()
{
    // let the state draw the screen
    states.back()->draw(this);
}
