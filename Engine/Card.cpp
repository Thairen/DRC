#include "Card.h"



Card::Card(std::string texturePath, const sf::Vector2f & pos)
	: GameObject(texturePath, pos)
{
	SetCollisionRadius(15);
}

void Card::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}

void Card::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);
}

void Card::FlipCard()
{
	m_isFaceUp = !(m_isFaceUp);
}