#pragma once
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"

class AnimationSprite
{
	sf::Keyboard keyboard;

public:
	AnimationSprite(int vitesse, bool direction, SSprite homme, sf::RenderWindow & window);
	~AnimationSprite(void);

	//Direction gauche ou droite (uniquement hammster)
	void SetDirection(SSprite homme, bool dir);

private:

	//Initialisation
	int vitesse;
	bool go_left;
	int frame_index;

};

