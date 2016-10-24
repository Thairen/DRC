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

	//Adding members
	void AddArmor(float val) { m_defense->AddCurrent(val); m_upgrade->AddCurrent(val); m_defense->BalanceStat(); m_upgrade->BalanceStat(); }
	void AddBaseAttack(float val) { m_baseAttack->AddMax(val); m_baseAttack->BalanceStat();}
	void AddHealth(float val) { m_health->AddCurrent(val); m_health->BalanceStat();}
	void AddExp(float val) { m_exp->AddCurrent(val); m_exp->BalanceStat();}
	void AddGold(float val) { m_gold->AddCurrent(val); m_gold->BalanceStat();}

	float Attack(float mod);
	void TakeDamage(float mod);

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

