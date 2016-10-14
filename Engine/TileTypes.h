#pragma once
#include "Tile.h"
#include "GameObject.h"

class SwordTile : public Tile
{
public:

	SwordTile(std::string texturePath, const sf::Vector2f& pos);

	virtual void AddStatus(GameObject* object);
};

class ArmorTile : public Tile
{
public:

	ArmorTile(std::string texturePath, const sf::Vector2f& pos);

	virtual void AddStatus(GameObject* object);
};
class HealthTile : public Tile
{
public:

	HealthTile(std::string texturePath, const sf::Vector2f& pos);

	virtual void AddStatus(GameObject* object);
};
class EnemyTile : public Tile
{
public:

	EnemyTile(std::string texturePath, const sf::Vector2f& pos);

	virtual void AddStatus(GameObject* object);
};

class GoldTile : public Tile
{
public:

	GoldTile(std::string texturePath, const sf::Vector2f& pos);

	virtual void AddStatus(GameObject* object);
};
