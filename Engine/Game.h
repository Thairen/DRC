#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Tile.h"
#include "TileTypes.h"

const int row = 8;
const int col = 8;

class Game
{
public:
	Game();
	void Draw(sf::RenderWindow* window);
	void Update(sf::RenderWindow * window, float dt);
	void AddObject(GameObject* object);
	void GameOver() { m_gameOver = true;  }
	void ShowFonts(sf::RenderWindow* window);

	void CreateBoard(); // Fill the board with objects
	Tile* CreateTile(const sf::Vector2f& pos);

	void MoveToEnd(std::vector<GameObject*>, int index);
	std::vector<Tile*> GetNeighbors(int i, int j, int maxI, int maxJ);

private:

	Tile* gameBoard[row][col];

	std::vector<GameObject*> m_gameObjects;
	bool m_gameOver;
	sf::Font m_mainFont;
};