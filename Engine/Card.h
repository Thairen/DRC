#pragma once
#include "GameObject.h"

class Card : public GameObject
{
public:
	Card(std::string texturePath, const sf::Vector2f& pos);

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow * window, float dt);

	void FlipCard();

private:
	bool m_isFaceUp;
	std::string m_name;
};
