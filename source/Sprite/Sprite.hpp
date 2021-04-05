// Sprite Class Header
// Bastardized port of SFML's sf::Sprite

#ifndef Sprite_hpp
#define Sprite_hpp

#include "../State/State.hpp"

class Sprite
{
private:
    const SDL_Texture* m_texture;
    SDL_Rect           m_textureRect;

public:
    Sprite();

    explicit Sprite(const SDL_Texture& texture);

    Sprite(const SDL_Texture& texture, const SDL_Rect& rectangle);

    void setTexture(const SDL_Texture& texture, bool resetRect = false);

    void setTextureRect(const SDL_Rect& rectangle);

    void setPosition(Vector2f position);

    void setColor(const SDL_Color& color);

    const SDL_Texture* getTexture() const;

    const SDL_Rect& getTextureRect() const;

    const Vector2f& getPosition() const;

    const SDL_Color& getColor() const;    

};

#endif