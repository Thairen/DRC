#include "Player.h"



Player::Player(const sf::Vector2f& pos) : GameObject("Sprites/skull.png", pos)
{
	m_baseAttack = new Stat("Health", 4.f, 4.f);
	m_weaponAttack = new Stat("WpAt", 2.f, 2.f);
	m_defense = new Stat("Defense", 3.f, 3.f);
	m_health = new Stat("Health", 50.f, 50.f);
	m_exp = new Stat("EXP", 0.f, 100.f);
	m_gold = new Stat("Gold", 0.f, 100.f);
	m_upgrade = new Stat("Up", 0.f, 100.f);

	m_font.loadFromFile("Fonts/kenpixel_high_square.ttf");
	tex.loadFromFile("Sprites/icons.jpg");

	attackIcon.setTexture(tex);
	defenseIcon.setTexture(tex);
	healthIcon.setTexture(tex);
	goldIcon.setTexture(tex);
	baseAttackIcon.setTexture(tex);

	attackIcon.setTextureRect(sf::IntRect(205, 5, 64, 64));
	defenseIcon.setTextureRect(sf::IntRect(340, 138, 64, 64));
	healthIcon.setTextureRect(sf::IntRect(138, 5, 64, 64));
	goldIcon.setTextureRect(sf::IntRect(405, 340, 64, 64));
	baseAttackIcon.setTextureRect(sf::IntRect(340, 340, 64, 64));

	attackIcon.setPosition(sf::Vector2f(700.f,580.f));
	defenseIcon.setPosition(sf::Vector2f(525.f, 580.f));
	healthIcon.setPosition(sf::Vector2f(1000, 580));
	goldIcon.setPosition(sf::Vector2f(150, 580));
	baseAttackIcon.setPosition(sf::Vector2f(350, 580));
}

void Player::Draw(sf::RenderWindow* window)
{
	GameObject::Draw(window);

	window->draw(attackIcon);
	window->draw(defenseIcon);
	window->draw(healthIcon);
	window->draw(goldIcon);
	window->draw(baseAttackIcon);
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
	baseDamageRead.setPosition(sf::Vector2f(350, 640));//figure where to set
	window->draw(baseDamageRead);

	sf::Text weaponDamageRead;
	weaponDamageRead.setFont(m_font);
	weaponDamageRead.setString("Weapon Damage: " + std::to_string((int)m_weaponAttack->GetCurrent()));
	weaponDamageRead.setCharacterSize(17);
	weaponDamageRead.setColor(sf::Color::Red);
	weaponDamageRead.setPosition(sf::Vector2f(700, 640));//figure where to set
	window->draw(weaponDamageRead);

	sf::Text defenseRead;
	defenseRead.setFont(m_font);
	defenseRead.setString("Defense: " + std::to_string((int)m_defense->GetCurrent()) + " / " + std::to_string((int)m_defense->GetMax()));
	defenseRead.setCharacterSize(17);
	defenseRead.setPosition(sf::Vector2f(525, 640));//figure where to set
	window->draw(defenseRead);

	sf::Text healthRead;
	healthRead.setFont(m_font);
	healthRead.setString("Health: "  + std::to_string((int)m_health->GetCurrent()) +  " / " + std::to_string((int)m_health->GetMax()));
	healthRead.setCharacterSize(17);
	healthRead.setColor(sf::Color::Red);
	healthRead.setPosition(sf::Vector2f(1000, 640));//figure where to set
	window->draw(healthRead);

	sf::Text xpRead;
	xpRead.setFont(m_font);
	xpRead.setString("Experience: " + std::to_string((int)m_exp->GetCurrent()) + " / " + std::to_string((int)m_exp->GetMax()));
	xpRead.setCharacterSize(17);
	xpRead.setColor(sf::Color::Green);
	xpRead.setPosition(sf::Vector2f(525, 700));//figure where to set
	window->draw(xpRead);

	sf::Text upRead;
	upRead.setFont(m_font);
	upRead.setString("Upgrade Bar: " + std::to_string((int)m_upgrade->GetCurrent()) + " / " + std::to_string((int)m_upgrade->GetMax()));
	upRead.setCharacterSize(17);
	upRead.setColor(sf::Color::Blue);
	upRead.setPosition(sf::Vector2f(525, 675));//figure where to set
	window->draw(upRead);

	sf::Text goldRead;
	goldRead.setFont(m_font);
	goldRead.setString("Gold: " + std::to_string((int)m_gold->GetCurrent()) + " / " + std::to_string((int)m_gold->GetMax()));
	goldRead.setCharacterSize(17);
	goldRead.setColor(sf::Color::Yellow);
	goldRead.setPosition(sf::Vector2f(150, 640));//figure where to set
	window->draw(goldRead);

}

float Player::Attack(float mod)
{
	//Need to take in an add to attack, m_weaponAttack * number of swords matched
	return m_baseAttack->GetMax() + (m_weaponAttack->GetMax() * mod);
}

void Player::TakeDamage(float amount)
{
	amount -= m_defense->GetCurrent();
	m_defense->SubtractCurrent(1);
	m_health->SubtractCurrent(amount);
}
