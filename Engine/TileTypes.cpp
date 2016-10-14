#include "TileTypes.h"

SwordTile::SwordTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Sword);
}

void SwordTile::AddStatus(GameObject* object)
{
	
}

ArmorTile::ArmorTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Armor);
}

void ArmorTile::AddStatus(GameObject* object)
{

}

HealthTile::HealthTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Health);
}

void HealthTile::AddStatus(GameObject* object)
{

}

EnemyTile::EnemyTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Enemy);
}

void EnemyTile::AddStatus(GameObject* object)
{

}

GoldTile::GoldTile(std::string texturePath, const sf::Vector2f& pos) : Tile(texturePath, pos)
{
	SetType(TileType::Gold);
}

void GoldTile::AddStatus(GameObject* object)
{

}