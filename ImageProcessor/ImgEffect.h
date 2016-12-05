#pragma once
#include <SFML\Graphics.hpp>

namespace ImgEffect
{
	sf::Image& BackAndWhite(sf::Image& image)
	{
		const int width = image.getSize().x;
		const int height = image.getSize().y;

		// Loop through all pixels from left -> right, top -> bottom
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				sf::Color oldColor = image.getPixel(j, i);
				int bwColor = (oldColor.r + oldColor.g + oldColor.b) / 3;
				sf::Color newColor = oldColor;
				newColor.r = bwColor;
				newColor.g = bwColor;
				newColor.b = bwColor;

				image.setPixel(j, i, newColor);
			}
		}
		return image;
	}

	sf::Image& BinaryBlackAndWhite(sf::Image& image)
	{
		const int width = image.getSize().x;
		const int height = image.getSize().y;

		// Loop through all pixels from left -> right, top -> bottom
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				sf::Color oldColor = image.getPixel(j, i);
				int bwColor = (oldColor.r + oldColor.g + oldColor.b) / 3;

				if (bwColor < 127)
				{
					bwColor = 0;
				}
				else
				{
					bwColor = 255;
				}

				sf::Color newColor = oldColor;
				newColor.r = bwColor;
				newColor.g = bwColor;
				newColor.b = bwColor;

				image.setPixel(j, i, newColor);
			}
		}
		return image;
	}

	sf::Image& SimpleDithering(sf::Image& image)
	{
		const int width = image.getSize().x;
		const int height = image.getSize().y;
		int distance = 0;

		// Loop through all pixels from left -> right, top -> bottom
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				sf::Color oldColor = image.getPixel(j, i);
				int bwColor = (oldColor.r + oldColor.g + oldColor.b) / 3;				
				bwColor += distance;

				if (bwColor < 127)
				{
					distance = bwColor;
					bwColor = 0;
				}
				else
				{
					distance = 1 - (255 - bwColor);
					bwColor = 255;
				}

				sf::Color newColor = oldColor;
				newColor.r = bwColor;
				newColor.g = bwColor;
				newColor.b = bwColor;

				image.setPixel(j, i, newColor);
			}
		}
		return image;
	}
}