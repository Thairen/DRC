#pragma once
#include <vector>
#include "GameObject.h"
#include "Card.h"

class Hand : public GameObject
{
public:
	Hand(std::string texturePath, const sf::Vector2f& pos);
	~Hand();

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow * window, float dt);

	void AddCard(Card* card);

private:
	std::vector<Card*> m_Hand;
};

