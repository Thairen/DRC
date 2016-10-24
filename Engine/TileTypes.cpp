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
	m_health = new Stat(4.f);
	m_attack = new Stat(1.f);
	m_defense = new Stat(0.f);
	m_exp = new Stat(5.f);

	m_font.loadFromFile("Fonts/kenpixel_high_square.ttf");
}

void EnemyTile::Destroy()
{
	GameObject::Destroy();
	delete m_health, m_attack, m_defense, m_exp;
	//ADD Whatever Tile behavior when destroyed ----------------
}

void EnemyTile::Draw(sf::RenderWindow* window)
{
	Tile::Draw(window);
	
}

void EnemyTile::Update(sf::RenderWindow* window, float dt)
{
	Tile::Update(window, dt);
	ShowStats(window);
}

void EnemyTile::ShowStats(sf::RenderWindow* window)
{
	sf::Text attackRead;
	attackRead.setFont(m_font);
	attackRead.setString(std::to_string((int)m_attack->GetCurrent()));
	attackRead.setCharacterSize(17);
	attackRead.setColor(sf::Color::Red);
	attackRead.setPosition(this->GetPosition().x + 20,this->GetPosition().y - 20);//figure where to set
	window->draw(attackRead);

	sf::Text defenseRead;
	defenseRead.setFont(m_font);
	defenseRead.setString(std::to_string((int)m_defense->GetCurrent()));
	defenseRead.setCharacterSize(17);
	defenseRead.setPosition(this->GetPosition().x + 20, this->GetPosition().y - 5);//figure where to set
	window->draw(defenseRead);

	sf::Text healthRead;
	healthRead.setFont(m_font);
	healthRead.setString(std::to_string((int)m_health->GetCurrent()));
	healthRead.setCharacterSize(17);
	healthRead.setColor(sf::Color::Green);
	healthRead.setPosition(this->GetPosition().x + 20, this->GetPosition().y + 10);//figure where to set
	window->draw(healthRead);
	
}

float EnemyTile::TakeDamage(float dmg)
{
	dmg -= m_defense->GetCurrent();
	float result = 0.f;

	if (dmg > 0)
	{
		m_health->SubtractCurrent(dmg);

		if (m_health->GetCurrent() <= 0)
		{
			return 0; //killed, return exp
		}
	}
	return m_health->GetCurrent(); // Enemy still alive, doesnt destroy.
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