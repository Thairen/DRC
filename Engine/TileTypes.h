#pragma once
#include "Tile.h"
#include "GameObject.h"
#include "Stat.h"

class SwordTile : public Tile
{
public:

	SwordTile(std::string texturePath, const sf::Vector2f& pos);

	virtual void Destroy();
};

class ArmorTile : public Tile
{
public:

	ArmorTile(std::string texturePath, const sf::Vector2f& pos);

	virtual void Destroy();
};
class HealthTile : public Tile
{
public:

	HealthTile(std::string texturePath, const sf::Vector2f& pos);

	virtual void Destroy();
};
class EnemyTile : public Tile
{
public:

	EnemyTile(std::string texturePath, const sf::Vector2f& pos);
	virtual void Destroy();
	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	void ShowStats(sf::RenderWindow* window);

private:
	Stat* m_attack; // Damage that gets added at end of the turn
	Stat* m_defense;
	Stat* m_health;
	Stat* m_exp; //Exp rewarded to the player on death

	sf::Font m_font;
};

class GoldTile : public Tile
{
public:

	GoldTile(std::string texturePath, const sf::Vector2f& pos);
	virtual void Destroy();
};
