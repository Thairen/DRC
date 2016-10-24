#include "Player.h"



Player::Player(const sf::Vector2f& pos) : GameObject("Sprites/skull.png", pos)
{
	m_baseAttack = new Stat(4.f);
	m_weaponAttack = new Stat(2.f);
	m_defense = new Stat(3.f);
	m_health = new Stat(50.f);
	m_exp = new Stat(100.f);
	m_gold = new Stat(100.f);
	m_upgrade = new Stat(100.f);

	m_exp->SetCurrent(0.f);
	m_gold->SetCurrent(0.f);
	m_upgrade->SetCurrent(0.f);

	m_font.loadFromFile("Fonts/kenpixel_high_square.ttf");
}

void Player::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);
}

void Player::Update(sf::RenderWindow* window, float dt)
{
	GameObject::Update(window, dt);
	ShowStats(window);
}

void Player::ShowStats(sf::RenderWindow* window)
{
	sf::Text baseDamageRead;
	baseDamageRead.setFont(m_font);
	baseDamageRead.setString("Base Damage: " + std::to_string((int)m_baseAttack->GetCurrent()));
	baseDamageRead.setCharacterSize(17);
	baseDamageRead.setColor(sf::Color::Red);
	baseDamageRead.setPosition(sf::Vector2f(350, 580));//figure where to set
	window->draw(baseDamageRead);

	sf::Text weaponDamageRead;
	weaponDamageRead.setFont(m_font);
	weaponDamageRead.setString("Weapon Damage: " + std::to_string((int)m_weaponAttack->GetCurrent()));
	weaponDamageRead.setCharacterSize(17);
	weaponDamageRead.setColor(sf::Color::Red);
	weaponDamageRead.setPosition(sf::Vector2f(700, 580));//figure where to set
	window->draw(weaponDamageRead);

	sf::Text defenseRead;
	defenseRead.setFont(m_font);
	defenseRead.setString("Defense: " + std::to_string((int)m_defense->GetCurrent()) + " / " + std::to_string((int)m_defense->GetMax()));
	defenseRead.setCharacterSize(17);
	defenseRead.setPosition(sf::Vector2f(525, 580));//figure where to set
	window->draw(defenseRead);

	sf::Text healthRead;
	healthRead.setFont(m_font);
	healthRead.setString("Health: "  + std::to_string((int)m_health->GetCurrent()) +  " / " + std::to_string((int)m_health->GetMax()));
	healthRead.setCharacterSize(17);
	healthRead.setColor(sf::Color::Red);
	healthRead.setPosition(sf::Vector2f(1000, 580));//figure where to set
	window->draw(healthRead);

	sf::Text xpRead;
	xpRead.setFont(m_font);
	xpRead.setString("Experience: " + std::to_string((int)m_exp->GetCurrent()) + " / " + std::to_string((int)m_exp->GetMax()));
	xpRead.setCharacterSize(17);
	xpRead.setColor(sf::Color::Green);
	xpRead.setPosition(sf::Vector2f(525, 650));//figure where to set
	window->draw(xpRead);

	sf::Text upRead;
	upRead.setFont(m_font);
	upRead.setString("Upgrade Bar: " + std::to_string((int)m_upgrade->GetCurrent()) + " / " + std::to_string((int)m_upgrade->GetMax()));
	upRead.setCharacterSize(17);
	upRead.setColor(sf::Color::Blue);
	upRead.setPosition(sf::Vector2f(525, 625));//figure where to set
	window->draw(upRead);

	sf::Text goldRead;
	goldRead.setFont(m_font);
	goldRead.setString("Gold: " + std::to_string((int)m_gold->GetCurrent()) + " / " + std::to_string((int)m_gold->GetMax()));
	goldRead.setCharacterSize(17);
	goldRead.setColor(sf::Color::Yellow);
	goldRead.setPosition(sf::Vector2f(150, 580));//figure where to set
	window->draw(goldRead);

}

float Player::Attack(float mod)
{
	//Need to take in an add to attack, m_weaponAttack * number of swords matched
	return m_baseAttack->GetMax() + (m_weaponAttack->GetMax() * mod);
}

void Player::TakeDamage(float amount)
{
	m_health->SubtractCurrent(amount);
}
