#include "GameObject.h"


GameObject::GameObject(const Texture2D& sprite)
    : Size(glm::vec2(0.0f))
    , Position(glm::vec2(0.0f))
    , Destroyed(false)
    , Sprite(sprite)
    , Color(glm::vec3(1.0f))
    , Velocity(0.0f)
    , Rotation(0.0f)
    , IsSolid(true)
{ }

void GameObject::Draw(SpriteRenderer& renderer)
{
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}