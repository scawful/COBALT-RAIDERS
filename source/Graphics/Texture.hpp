// Texture Class Header
// @scawful

#ifndef Texture_hpp
#define Texture_hpp

#include "../State/State.hpp"

//Texture wrapper class
class ZTexture
{
    public:
        //Initializes variables
        ZTexture();

        //Deallocates memory
        ~ZTexture();

        // Legacy texture loader from path
        SDL_Texture *loadTexture( SDL_Renderer *zRenderer, std::string path );

        //Loads image at specified path
        bool loadFromFile( SDL_Renderer *zRenderer, std::string path );
        
        //Creates image from font string
        bool loadFromRenderedText( SDL_Renderer *zRenderer, TTF_Font *gFont, std::string textureText, SDL_Color textColor );
        
        //Deallocates texture
        void free();

        //Set color modulation
        void setColor( Uint8 red, Uint8 green, Uint8 blue );

        //Set blending
        void setBlendMode( SDL_BlendMode blending );

        //Set alpha modulation
        void setAlpha( Uint8 alpha );
            
        //Renders texture at given point
        void render( SDL_Renderer *zRenderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

        SDL_Texture* getRawTexture();

        //Gets image dimensions
        int getWidth();
        int getHeight();
    
    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
};

#endif /* Texture_hpp */
