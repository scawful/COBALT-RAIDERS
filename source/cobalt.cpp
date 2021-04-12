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

    // state manager creation
    Manager game;
    game.init();

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
