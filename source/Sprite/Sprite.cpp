// Sprite.cpp

#include "Sprite.hpp"

Sprite::Sprite()
{
    z_texture = nullptr;
}

Sprite::Sprite(ZTexture& texture)
{
    z_texture = &texture;
}

Sprite::Sprite(ZTexture& texture, SDL_Rect& rectangle)
{
    z_texture = &texture;
    z_textureRect = &rectangle;
}

void Sprite::setTexture(ZTexture& texture, bool resetRect)
{
    z_texture = &texture;
}

void Sprite::setTextureRect(SDL_Rect& rectangle)
{
    z_textureRect = &rectangle;
}

void Sprite::setPosition(Vector2f position)
{
    z_textureRect->x = position.x;
    z_textureRect->y = position.y;

    z_texturePosition.x = position.x;
    z_texturePosition.y = position.y;
}

void Sprite::setColor(const SDL_Color& color)
{
    z_textureColor = color;
    z_texture->setColor( color.r, color.b, color.g );
}

void Sprite::setOrigin(const Vector2f& position)
{
    z_origin = position;
}

void Sprite::setScale(const Vector2f& factor)
{
    z_scale = factor;
}

void Sprite::render( SDL_Renderer *zRenderer, int x, int y )
{
    z_texture->render( zRenderer, x, y );
}

void Sprite::move( const Vector2f& offset )
{
    Vector2f currentPosition = getPosition();

    setPosition( currentPosition + offset );
}

const ZTexture* Sprite::getTexture() const
{
    return z_texture;
}

SDL_Texture* Sprite::getRawTexture()
{
    return z_texture->getRawTexture();
}

SDL_Rect* Sprite::getTextureRect()
{
    return z_textureRect;
}

const Vector2f& Sprite::getPosition() const
{
    return z_texturePosition;
}

const SDL_Color& Sprite::getColor() const
{
    return z_textureColor;
}  