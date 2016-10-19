#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Tile.h"
#include "TileTypes.h"
#include "Player.h"

const int row = 8;
const int col = 8;

class Game
{
public:
	Game();
	void Draw(sf::RenderWindow* window);
	void Update(sf::RenderWindow * window, float dt);
	void AddObject(GameObject* object); // Push object into object vector
	void GameOver() { m_gameOver = true;  }
	void ShowFonts(sf::RenderWindow* window);
	void HandleInput(sf::RenderWindow* window);
	Tile* GetCurrentTile();
	bool CanSelect(Tile* tile);
	void AddToSelected(Tile* tile);
	void ClearSelected(); // Clear selected Vector on mouse up

	void CreateBoard(); // Fill the board with objects
	Tile* CreateTile(const sf::Vector2f& pos);
	void RemoveTile(Tile* tile); //Remove tiles in selection list

	void MoveToEnd(std::vector<GameObject*>, int index); //Move hovering tile to end of vector (DRAW LAST)
	void ShiftTiles(); //Move Tiles down as tiles below get destroyed

	void MousePressed();
	void MouseReleased();

	Player* player;

private:

	Tile* gameBoard[row][col];

	std::vector<GameObject*> m_gameObjects; // List of every object in game
	std::vector<Tile*> m_selectedTiles; //Tiles selected by player

	// NO IMPLEMENTATION AT THIS TIME
	bool m_gameOver;
	sf::Font m_mainFont;
};