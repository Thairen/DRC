#include "Deck.h"



Deck::Deck(std::string texturePath, const sf::Vector2f& pos) : GameObject(texturePath, pos)
{
}


Deck::~Deck()
{
}

void Deck::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}

void Deck::Update(sf::RenderWindow* window, float dt)
{
	GameObject::Update(window, dt);
}

void Deck::Populate()
{
	m_Deck.clear();

}

void Deck::Shuffle()
{
	//Shuffle
	std::random_shuffle(m_Deck.begin(), m_Deck.end());
}

//Card* Deck::Draw()
//{
//
//}
