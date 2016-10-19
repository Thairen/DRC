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
	bool IsSelected() { return m_isSelected; }

	void SetSelection(bool t) { m_isSelected = t; }

	virtual void Draw(sf::RenderWindow* window);
	virtual void Update(sf::RenderWindow* window, float dt);

	void Hovering(sf::RenderWindow * window);

private:

	sf::RectangleShape* border;

	bool m_isSelected;
	bool m_isHovering;
	TileType m_type;
};

