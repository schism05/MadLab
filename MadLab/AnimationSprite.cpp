#include "AnimationSprite.h"


AnimationSprite::AnimationSprite(int _vitesse, bool direction, SSprite homme,sf::RenderWindow & window)
{
	sf::Clock clock;
	vitesse = _vitesse;
	go_left = direction;


}


AnimationSprite::~AnimationSprite(void)
{
}
/*
void AnimationSprite::Draw( sf::RenderWindow & window )
{
	int fi = 0;//int( clock.getElapsedTime().asSeconds() * vitesse ) % homme.total_anims;
	homme.sprite.setTextureRect(sf::IntRect((fi*homme.SpriteLargeur), homme.SpriteHauteur, homme.SpriteLargeur, homme.SpriteHauteur));
	window.draw(homme.sprite);
}

//Direction gauche ou droite (uniquement hammster)
void AnimationSprite::SetDirection(SSprite homme, bool dir)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		dir = false;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		dir = true;
	}

	go_left = dir;
}

*/