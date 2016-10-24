#include "Item.h"



Item::Item(const sf::Vector2f& pos) : GameObject("", pos)
{
}


void Item::Update(sf::RenderWindow* window, float dt)
{
	GameObject::Update(window, dt);
}

void Item::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}
