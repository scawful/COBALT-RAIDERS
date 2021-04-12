//  GameState.cpp
//  SDL

#include "GameState.hpp"
#include "MenuState.hpp"

GameState GameState::m_GameState;

void GameState::loadTextures()
{
    // Load image at specified path
    std::string path = "romfs:/data/space_bg.png";
    
    if ( !zBackgroundTexture.loadFromFile( zRenderer, path ) )
    {
        SDL_Log( "Failed to load texture image!\n" );
    }

    std::string path2 = "romfs:/data/red_bullet.png";

    if ( !bulletTexture.loadFromFile( zRenderer, path2 ) )
    {
        SDL_Log("Failed to load bullet texture image!\n");
    }

    this->textures["PLAYER_SHEET"].loadFromFile( zRenderer, "romfs:/data/player_sheet.png" );
}

void GameState::createActor()
{
    this->actor = new Actor(this->textures["PLAYER_SHEET"], actorRect, Vector2f(500.0, 500.0) );
    actorRect = { 100, 100, 72, 84 };
}

void GameState::init( SDL_Renderer *zRenderer, SDL_Window *zWindow )
{
    this->zRenderer = zRenderer;
    this->loadTextures();
    this->createActor();
    
    Vector2f velocity = {0,0};
    Vector2f position = {0,0};

    redBullet = new Bullet( &bulletTexture, velocity, position, redBulletRect );
    
    SDL_Log("GameState Initialization\n");
}

void GameState::cleanup()
{
    // Free loaded images and fonts
    this->zBackgroundTexture.free();
    this->bulletTexture.free();
    this->textures["PLAYER_SHEET"].free();

    delete this->actor;
    delete redBullet;
}

void GameState::pause()
{
    SDL_Log("GameState Pause\n");
}

void GameState::resume()
{
    SDL_Log("GameState Resume\n");
}

void GameState::updateActorInput( SDL_Event *event )
{
    
}

void GameState::handleEvents( Manager *game, const float& dt )
{
    SDL_Event event;

    while ( SDL_PollEvent(&event) ) 
    {
        switch (event.type) 
        {
            case SDL_JOYAXISMOTION:
                SDL_Log("Joystick %d axis %d value: %d\n",
                        event.jaxis.which,
                        event.jaxis.axis, event.jaxis.value);

                // lhs joystick has moved
                if ( event.jaxis.which == 0 )
                {
                    // x axis has changed 
                    if ( event.jaxis.axis == 0 )
                    {
                        //If the X axis is neutral
                        if ( ( event.jaxis.value > -8000 ) && ( event.jaxis.value < 8000 ) )
                        {
                            this->actor->move(0.f, 0.f, dt);
                        }
                        //If not
                        else
                        {
                            //Adjust the velocity
                            if ( event.jaxis.value < 0 )
                            {
                                this->actor->move(-1.f, 0.f, dt);
                            }
                            else
                            {
                                this->actor->move(1.f, 0.f, dt);
                            }
                        }  
                    }
                }

                break;

            case SDL_JOYBUTTONDOWN:
                if (event.jbutton.which == 0) 
                {
                    if (event.jbutton.button == 0) 
                    {
                        // (A) button down
                        this->actor->attacking = true;
                    } 
                    else if (event.jbutton.button == 10) 
                    {
                        // (+) button down
                        game->change( MenuState::instance() );
                    }
                    else if (event.jbutton.button == 11) 
                    {
                        // (-) button down
                        game->quit();
                    }

                    switch ( event.jbutton.button )
                    {
                        case 12: // move left
                            this->actor->move(-1.f, 0.f, dt);
                            break;
                        case 13: // move up
                            this->actor->move(1.f, 0.f, dt);
                            break;
                        case 14: // move right
                            this->actor->move(0.f, -1.f, dt);
                            break;
                        case 15: // move down
                            this->actor->move(0.f, 1.f, dt);
                            break;
                        default:
                            break;
                    }
                }
                break;

            default:
                break;
        }
    }
}

void GameState::update( Manager *game, const float& dt )
{
    this->actor->update( dt );
    SDL_RenderClear( zRenderer );
}

void GameState::draw( Manager *game )
{
    zBackgroundTexture.render( zRenderer, 0, 0 );
    //redBullet->getSprite()->render( zRenderer, 0, 0 );
    this->actor->render( zRenderer, &actorRect );

    SDL_RenderPresent( zRenderer );
    //SDL_Delay(16);
}
