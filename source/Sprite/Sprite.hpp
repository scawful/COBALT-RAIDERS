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
    SDL_Rect*          z_textureRect;
    SDL_Color          z_textureColor;
    Vector2f           z_texturePosition;
    Vector2f           z_origin;
    Vector2f           z_scale;

public:
    Sprite();

    explicit Sprite(ZTexture& texture);

    Sprite(ZTexture& texture, SDL_Rect& rectangle);

    void setTexture(ZTexture& texture, bool resetRect = false);

    void setTextureRect(SDL_Rect& rectangle);

    void setPosition(Vector2f position);

    void setColor(const SDL_Color& color);

    void setOrigin(const Vector2f& position);

    void setScale(const Vector2f& factor);

    void render( SDL_Renderer *zRenderer, int x, int y );

    void move( const Vector2f& offset );

    const ZTexture* getTexture() const;

    SDL_Texture* getRawTexture();

    SDL_Rect* getTextureRect();

    const Vector2f& getPosition() const;

    const SDL_Color& getColor() const;    

};

#endif