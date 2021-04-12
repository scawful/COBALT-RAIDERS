//  Manager (State) Class Header

#ifndef Manager_hpp
#define Manager_hpp

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <random>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "switch.h"

class State;

class Manager
{
private:
    std::vector<State*> states;
    
    bool m_running;
    
public:
    void init(int width = 1920, int height = 1080);
    void cleanup();
    
    void change(State *state);
    void push(State *state);
    void pop();
    
    void updateDt();
    void handleEvents(const float& dt);
    void update(const float& dt);
    void draw();
    
    bool running() { return m_running; }
    void quit() { m_running = false; }
    
    SDL_Renderer *zRenderer = NULL;
    SDL_Window *zWindow = NULL;
    SDL_Surface *screen;
    SDL_Joystick *left_joycon = NULL;
    SDL_Joystick *right_joycon = NULL;

};

#endif /* Manager_hpp */
