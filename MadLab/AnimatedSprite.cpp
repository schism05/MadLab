#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(string _Path, int _nbr_lignes, int total_anims[])
{
	if(_Path != "")
		path = _Path;

	if(_nbr_lignes >=0)
		nbr_lignes = _nbr_lignes;

	for( int i = 0; i< nbr_lignes; ++i)
	{
		TotalAnims[i] = total_anims[i];
	}

	if (!texture.loadFromFile(path))
	{
		// erreur...
	}

	//Taille du template
	l = texture.getSize().x;
	h = texture.getSize().y;

	//Taille du sprite
	SpriteHauteur = h / nbr_lignes;
	SpriteLargeur = l / TotalAnims[ 0 ];

	sprite.setTexture( texture );
}

AnimatedSprite::~AnimatedSprite(void)
{
}

void AnimatedSprite::Update(int vitesse)
{
	int index = int( clock.getElapsedTime().asSeconds() * vitesse ) % TotalAnims[0];
	SetFrame(index);
}

void AnimatedSprite::Update(int vitesse, int animID)
{
	int index = int( clock.getElapsedTime().asSeconds() * vitesse ) % TotalAnims[ animID ];
	SetFrame( index, animID);
}

void AnimatedSprite::SetFrame(int index)
{
	sprite.setTextureRect(sf::IntRect((index*SpriteLargeur), 0, SpriteLargeur, SpriteHauteur));
}

void AnimatedSprite::SetFrame(int index, int animID)
{
	switch (animID)
	{
	case 0:
		sprite.setTextureRect(sf::IntRect((index*SpriteLargeur), (SpriteHauteur * animID), SpriteLargeur, SpriteHauteur));
		break;
	case 1:
		sprite.setTextureRect(sf::IntRect((index*SpriteLargeur), (SpriteHauteur * animID), SpriteLargeur, SpriteHauteur));
		break;
	case 2:
		sprite.setTextureRect(sf::IntRect((index*SpriteLargeur), (SpriteHauteur * animID), SpriteLargeur, SpriteHauteur));
		break;
	}
}
