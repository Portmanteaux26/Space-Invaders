#include "GameObject.h"


GameObject::GameObject(glm::vec2 pos, glm::vec2 size, const Texture2D& sprite, glm::vec3 color, glm::vec2 velocity)
    : Position(pos)
    , Size(size)
    , Velocity(velocity)
    , Color(color)
    , Rotation(0.0f)
    , Sprite(sprite)
    , IsSolid(false)
    , Destroyed(false)
{ }

void GameObject::Draw(SpriteRenderer& renderer)
{
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}