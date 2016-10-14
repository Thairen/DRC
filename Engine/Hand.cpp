#include "Hand.h"



Hand::Hand(std::string texturePath, const sf::Vector2f& pos) : GameObject(texturePath,pos)
{
}


Hand::~Hand()
{
}

void Hand::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}

void Hand::Update(sf::RenderWindow* window, float dt)
{
	GameObject::Update(window, dt);
}

void Hand::AddCard(Card* card)
{
	m_Hand.push_back(card);
}
