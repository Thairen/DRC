#include "Game.h"
#include "GameObject.h"
#include "Card.h"

Game::Game()
	: m_gameOver(false)
{
	player = new Player(sf::Vector2f(0, 0));
	AddObject(player);
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

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		Tile* tile = dynamic_cast<Tile*>(current);

		if (tile != NULL && tile->IsHovering())
		{
			MoveToEnd(m_gameObjects, i);
			break;
		}

	}
	//Update GameObjects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];
		current->Update(window, dt);
	}

	HandleInput(window);
	//ShiftTiles();
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

void Game::HandleInput(sf::RenderWindow* window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		MousePressed();
	}
}

void Game::MoveToEnd(std::vector<GameObject*>, int index)
{
	GameObject* tmp = m_gameObjects[index];
	m_gameObjects.erase(m_gameObjects.begin() + index);
	m_gameObjects.push_back(tmp);
}

void Game::ShiftTiles()
{
	for (int i = row - 1; i > 0; i--)
	{
		for (int j = col -1; j > 0; j--)
		{
			Tile* tile = gameBoard[i][j]; //Get current tile
			Tile* check = gameBoard[i + 1][j];
			if (check != NULL && check->IsDestroyed() && tile != NULL)
			{
				if(i + 1 < col)
					gameBoard[i + 1][j] = NULL;

				tile->SetPos(sf::Vector2f(check->GetPosition().x, check->GetPosition().y));
			}
		}
	}
}

void Game::AddPoints(TileType type, float val)
{
	switch (type)
	{
	case TileType::Armor:
		player->AddArmor(val);
		break;

	case TileType::Gold:
		player->AddGold(val);
		break;

	case TileType::Health:
		player->AddHealth(val);
		break;

	case TileType::Enemy:
		player->AddExp(val);
		break;

	case TileType::Sword:
		break;
	}
}

void Game::MousePressed()
{
	Tile* tile = GetCurrentTile();
	if (tile != nullptr && CanSelect(tile))
	{
		AddToSelected(tile);
	}
}

void Game::MouseReleased()
{
		ClearSelected();
}

Tile* Game::GetCurrentTile()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		GameObject* current = m_gameObjects[i];

		Tile* currentTile = dynamic_cast<Tile*>(current);
		
		if (currentTile != NULL && currentTile->IsHovering())
			return currentTile;
	}

	return NULL;
}

bool Game::CanSelect(Tile* tile)
{
	if (m_selectedTiles.size() == 0) // If vector is empty, add
	{
		return true;
	}

	if (tile->IsSelected())  // check if tile is already in vector
	{                     
		return false;
	}

	if (m_selectedTiles[0]->GetType() == TileType::Sword && tile->GetType() == TileType::Enemy)
	{
		return true;
	}

	if (m_selectedTiles[0]->GetType() == TileType::Enemy && tile->GetType() == TileType::Sword)
	{
		return true;
	}

	return m_selectedTiles[0]->GetType() == tile->GetType(); //If current tile matches the tile type of the vector
}

void Game::AddToSelected(Tile* tile)
{
	tile->SetSelection(true);
	m_selectedTiles.push_back(tile);
}

void Game::ClearSelected()
{
	for (int i = 0; i < m_selectedTiles.size(); i++)
	{
		m_selectedTiles[i]->SetSelection(false);
	}

	if (m_selectedTiles.size() >= 3)
	{
		for (int i = 0; i < m_selectedTiles.size(); i++)
		{
			RemoveTile(m_selectedTiles[i]);
		}
	}

	m_selectedTiles.clear();
}

void Game::CreateBoard()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			gameBoard[i][j] = CreateTile(sf::Vector2f(350.f + j * 62.f, 100.f + i * 62.f));
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
		tile = new EnemyTile("Sprites/skull.jpg", pos);
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

void Game::RemoveTile(Tile* tile)
{
	AddPoints(tile->GetType(), 2);
	//Need to add in player behavior for setting stats on how much is offered based on the match.
	tile->Destroy();
}