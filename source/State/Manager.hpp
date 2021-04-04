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
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class State;

class Manager
{
private:
    std::vector<State*> states;
    
    bool m_running;
    bool m_fullscreen;
    
public:
    void init(SDL_Renderer *zRenderer,
              SDL_Window *zWindow,
              int width = 1920, int height = 1080,
              bool fullscreen = false);
    void cleanup();
    
    void change(State *state);
    void push(State *state);
    void pop();
    
    void handleEvents();
    void update();
    void draw();
    
    bool running() { return m_running; }
    void quit() { m_running = false; }
    
    SDL_Surface *screen;
    
    SDL_Window *zWindow;
    SDL_Renderer *zRenderer = NULL;

};

#endif /* Manager_hpp */
