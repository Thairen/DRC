#include "TileTypes.h"


// SWORD CLASS FUNCS ===============================================================

SwordTile::SwordTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Sword);
}

void SwordTile::Destroy()
{
	GameObject::Destroy();
	//ADD Whatever Tile behavior when destroyed ----------------
}

// Armor CLASS FUNCS ===============================================================

ArmorTile::ArmorTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Armor);
}

void ArmorTile::Destroy()
{
	GameObject::Destroy();
	//ADD Whatever Tile behavior when destroyed ----------------
}

// Health CLASS FUNCS ===============================================================

HealthTile::HealthTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Health);
}

void HealthTile::Destroy()
{
	GameObject::Destroy();
	//ADD Whatever Tile behavior when destroyed ----------------
}

// Enemy CLASS FUNCS ===============================================================

EnemyTile::EnemyTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Enemy);
}

void EnemyTile::Destroy()
{
	GameObject::Destroy();
	//ADD Whatever Tile behavior when destroyed ----------------
}

// Gold CLASS FUNCS ===============================================================

GoldTile::GoldTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Gold);
}

void GoldTile::Destroy()
{
	GameObject::Destroy();
	//ADD Whatever Tile behavior when destroyed ----------------
}