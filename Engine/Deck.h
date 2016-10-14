#pragma once
#include <vector>
#include "Card.h"

class Deck : public GameObject
{
public:
	Deck(std::string texturePath, const sf::Vector2f& pos);
	~Deck();

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	void Populate(); // Create the deck
	void Shuffle();

	//Card* Draw();

private:

	std::vector<Card*> m_Deck;
};

