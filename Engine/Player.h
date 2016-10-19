#pragma once
#include "GameObject.h"
#include "Stat.h"

class Player :	public GameObject
{
public:
	Player(const sf::Vector2f& pos);
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);
	void ShowStats(sf::RenderWindow* window);

	void AddPoints(Stat* stat, float val);

private:
	Stat* m_baseAttack;
	Stat* m_weaponAttack;
	Stat* m_defense;
	Stat* m_health;
	Stat* m_exp;
	Stat* m_gold;
	Stat* m_upgrade;

	sf::Font m_font;
};

