#include "Tile.h"



Tile::Tile(std::string texturePath, const sf::Vector2f& pos) : GameObject(texturePath, pos),
m_isSelected(false),
m_isHovering(false)
{
	border = new sf::RectangleShape();
	border->setPosition(this->GetPosition());
	border->setSize(sf::Vector2f(62.f, 62.f));
	border->setOrigin(this->m_sprite.getOrigin());
	border->setFillColor(sf::Color::Transparent);
	border->setOutlineThickness(5.f);
}


Tile::~Tile()
{
	Destroy();
	delete border;
}

void Tile::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
	
	window->draw(*border);
	
}

void Tile::Update(sf::RenderWindow * window, float dt)
{
	GameObject::Update(window, dt);
	Hovering(window);

	if (m_isSelected)
	{
		border->setOutlineColor(sf::Color::Red);
	}
	else
	{
		border->setOutlineColor(sf::Color::Transparent);
	}
	
}

void Tile::Hovering(sf::RenderWindow* window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

	if (mousePos.x >= this->GetPosition().x &&
		mousePos.x <= this->GetPosition().x + 55.f && //needs to be set size
		mousePos.y >= this->GetPosition().y &&
		mousePos.y <= this->GetPosition().y + 55.f)
	{
		m_isHovering = true;
		m_sprite.setScale(1.25f, 1.25f);
	}

	else
	{
		m_isHovering = false;
		m_sprite.setScale(1.0f, 1.0f);
	}
}

