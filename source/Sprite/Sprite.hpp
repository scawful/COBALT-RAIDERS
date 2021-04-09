// Sprite Class Header
// Bastardized port of SFML's sf::Sprite

#ifndef Sprite_hpp
#define Sprite_hpp

#include "../State/State.hpp"
#include "../Graphics/Texture.hpp"

class Sprite
{
private:
    const SDL_Texture* m_texture;
    ZTexture*          z_texture;
    SDL_Rect           z_textureRect;
    SDL_Color          z_textureColor;
    Vector2f           z_texturePosition;

public:
    Sprite();

    explicit Sprite(ZTexture& texture);

    Sprite(ZTexture& texture, const SDL_Rect& rectangle);

    void setTexture(ZTexture& texture, bool resetRect = false);

    void setTextureRect(const SDL_Rect& rectangle);

    void setPosition(Vector2f position);

    void setColor(const SDL_Color& color);

    void render( SDL_Renderer *zRenderer, int x, int y );

    const ZTexture* getTexture() const;

    const SDL_Rect& getTextureRect() const;

    const Vector2f& getPosition() const;

    const SDL_Color& getColor() const;    

};

#endif