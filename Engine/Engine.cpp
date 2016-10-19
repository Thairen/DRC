// Engine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameObject.h"
#include <string>
#include <iostream>
#include <vector>

bool fullscreen = false;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Dungeon Raider");		
	Game game;
	
	
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return &&
					event.key.alt)
				{					
					window.close();
					fullscreen = !fullscreen;
					window.create(fullscreen ? sf::VideoMode(1920,1080) : sf::VideoMode(1280, 720), "Dungeon Raider", fullscreen ? sf::Style::Fullscreen : sf::Style::Titlebar);
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				game.MousePressed();
			}

			if (event.type == sf::Event::MouseButtonReleased)
				game.MouseReleased();
				
		}
		


		window.clear();	

		game.Draw(&window);
		game.Update(&window, dt.asSeconds());
		
		window.display();
	}

	return 0;
}
