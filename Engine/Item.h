#pragma once
#include "GameObject.h"
#include "Stat.h"

class Item : public GameObject
{
public:
	Item(const sf::Vector2f& pos);

	virtual void Update(sf::RenderWindow* window, float dt);
	virtual void Draw(sf::RenderWindow* window);

private:
	Stat* m_baseDmg;
	Stat* m_weaponDmg;
	Stat* m_armor;
	Stat* m_luck;
	
};

