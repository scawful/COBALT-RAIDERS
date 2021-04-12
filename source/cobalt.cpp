// Program: Cobalt Raiders
// Author: scawful
// Date Created: 04/04/2021
// Platform: Nintendo Switch
// Toolchain: DEVKITPROA64
// Dependencies: SDL2, SDL2_image, SDL2_ttf

#include "delta.hpp"
#include "State/Manager.hpp"
#include "State/MenuState.hpp"
#include "State/GameState.hpp"

int main (int argc, char* argv[])
{
    Manager game;
    DeltaClock deltaClock;

    // Console debug for Ryujinx
    consoleDebugInit(debugDevice_SVC);
    game.init();

    // default state
    game.change( MenuState::instance() );
    
    // main loop
    while ( game.running() )
    {
        delta_time = deltaClock.restartClock();
        game.handleEvents( delta_time );
        game.update( delta_time );
        game.draw();
    }

    // cleanup the engine
    game.cleanup();

    return 0;
}
