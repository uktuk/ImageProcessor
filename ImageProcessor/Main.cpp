#include <SFML/Graphics.hpp>
#include <iostream>
#include "ImgEffect.h"

void main()
{
		
	sf::Image image;
	if (!image.loadFromFile("../testCube.jpg"))
	{
		system("PAUSE");
	}

	const int width = image.getSize().x;
	const int height = image.getSize().y;
		
	image = ImgEffect::SimpleDithering(image);

	sf::Texture texture;
	texture.loadFromImage(image);	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	sf::RenderWindow window(sf::VideoMode(width, height), "SFML works");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{				
				window.close();
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}	
}