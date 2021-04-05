//  GameState.cpp
//  SDL

#include "GameState.hpp"
#include "MenuState.hpp"

GameState GameState::m_GameState;

void GameState::init( SDL_Renderer *zRenderer, SDL_Window *zWindow )
{
    this->zRenderer = zRenderer;
    
    // ===============================================================================
    // make this a function lol
    SDL_Texture* newTexture = NULL;

    // Load image at specified path
    std::string path = "romfs:/data/space_bg.png";
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        SDL_Log( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( zRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            SDL_Log( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
    // ===============================================================================

    backgroundTexture = newTexture;
    
    // SDL_Color fontColor = { 255, 255, 255 };
    // // Large font loading
    // statusFont = TTF_OpenFont( "/Users/scawful/Documents/C++/SDL/SDL/assets/ARCADECLASSIC.TTF", 36 );
    // if ( statusFont == NULL )
    // {
    //     printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
    // }
    // else
    // {
        
    //     if ( !statusTexture.loadFromRenderedText( zRenderer, statusFont, "Score", textColor ) )
    //     {
    //         printf("Failed to render text texture!\n");
    //     }
        
    // }
    
    SDL_Log("GameState Initialization\n");
}

void GameState::cleanup()
{
    // Free loaded images and fonts
    SDL_DestroyTexture( backgroundTexture );
    backgroundTexture = NULL;
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
    int w = 1920, h = 1080;
    // fill window bounds
    SDL_SetRenderDrawColor(this->zRenderer, 0, 0, 0, 255);
    SDL_GetWindowSize(this->zWindow, &w, &h);
    SDL_Rect f = {0, 0, 1920, 1080};
    SDL_RenderFillRect(this->zRenderer, &f);

    SDL_RenderCopy( zRenderer, backgroundTexture, NULL, NULL );

    SDL_RenderPresent( zRenderer );
    SDL_Delay(16);
}
