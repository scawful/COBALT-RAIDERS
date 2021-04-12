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

Sprite::Sprite(ZTexture& texture, const SDL_Rect& rectangle)
{
    z_texture = &texture;
    z_textureRect = rectangle;
}

void Sprite::setTexture(ZTexture& texture, bool resetRect)
{
    z_texture = &texture;
}

void Sprite::setTextureRect(const SDL_Rect& rectangle)
{
    z_textureRect = rectangle;
}

void Sprite::setPosition(Vector2f position)
{
    z_textureRect.x = position.x;
    z_textureRect.y = position.y;

    z_texturePosition.x = position.x;
    z_texturePosition.y = position.y;
}

void Sprite::setColor(const SDL_Color& color)
{
    z_textureColor = color;
    z_texture->setColor( color.r, color.b, color.g );
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

const SDL_Rect& Sprite::getTextureRect() const
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