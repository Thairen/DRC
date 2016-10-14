#include "Game.h"
#include "GameObject.h"
#include "Card.h"

Game::Game()
	: m_gameOver(false)
{
	m_mainFont.loadFromFile("Fonts/kenpixel_high_square.ttf");
	CreateBoard();
}
void Game::Draw(sf::RenderWindow * window)
{	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Draw(window);
	}
}

void Game::Update(sf::RenderWindow * window, float dt)
{
	//Check and delete destroyed objects
	for (int i = m_gameObjects.size() - 1; i >= 0; i--)
	{
		GameObject* current = m_gameObjects[i];
		if (current->IsDestroyed())
		{
			delete current;
			m_gameObjects.erase(m_gameObjects.begin() + i);
		}
	}

	//Update GameObjects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		Tile* tile = dynamic_cast<Tile*>(current);

		if (tile->IsHovering())
		{
			MoveToEnd(m_gameObjects, i);
		}

		current->Update(window, dt);
	}
}

void Game::AddObject(GameObject * object)
{
	object->SetOwner(this);
	m_gameObjects.push_back(object);
}

void Game::ShowFonts(sf::RenderWindow* window)
{
	if (m_gameOver)
	{
		sf::Text gameOverText;
		gameOverText.setFont(m_mainFont);
		gameOverText.setString("GAME OVER!");
		gameOverText.setCharacterSize(110);
		gameOverText.setPosition(450, 150);
		window->draw(gameOverText);
	}
}

void Game::CreateBoard()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			gameBoard[i][j] = CreateTile(sf::Vector2f(450.f + j * 62.f, 100.f + i * 62.f));
			//Add the tile
			AddObject(gameBoard[i][j]);
		}
	}
}

Tile* Game::CreateTile(const sf::Vector2f& pos)
{
	int choice = rand() % 5 + 1;
	Tile* tile = nullptr;

	switch (choice)
	{
	case 1:
		tile = new SwordTile("Sprites/sword.jpg", pos);
		break;
	case 2:
		tile = new ArmorTile("Sprites/armor.jpg", pos);
		break;
	case 3:
		tile =  new EnemyTile("Sprites/skull.jpg", pos);
		break;
	case 4:
		tile = new HealthTile("Sprites/health.jpg", pos);
		break;
	case 5:
		tile = new GoldTile("Sprites/gold.jpg", pos);
		break;
	}

	return tile;
}

void Game::MoveToEnd(std::vector<GameObject*>, int index)
{
	GameObject* tmp = m_gameObjects[index];
	m_gameObjects.erase(m_gameObjects.begin() + index);
	m_gameObjects.push_back(tmp);
}

//std::vector<Tile*> GetNeighbors(int x, int y, int maxX, int maxY)
//{
//	std::vector<Tile*> neighbors;
//
//	if (x > 0)
//		neighbors.push_back( x - 1, y );
//}
