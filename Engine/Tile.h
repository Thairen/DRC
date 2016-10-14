#pragma once
#include "GameObject.h"
#include <vector>

enum class TileType
{
	Sword, Armor, Enemy, Health, Gold
};

class Tile : public GameObject
{
public:
	Tile(std::string texturePath, const sf::Vector2f& pos);
	~Tile();

	TileType GetType() { return m_type; }
	void SetType(TileType tileType) { m_type = tileType; }
	bool IsHovering() { return m_isHovering; }

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow * window, float dt);

	virtual void AddStatus(GameObject* object);

	void Hovering(sf::RenderWindow * window);

private:

	sf::RectangleShape* border;

	bool m_isSelected;
	bool m_isHovering;
	float selectedTimer;
	float clickTimer;
	TileType m_type;
};

