#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class AnimatedSprite
{

public:
	
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock clock;

	AnimatedSprite(string _Path, int nbr_lignes, int total_anims[]);
	~AnimatedSprite(void);
	
	void SetFrame(int index);
	void SetFrame(int index, int animID);

	void Update(int vitesse);
	void Update(int vitesse, int animID);

	//Initialisation
	string path;
	int nbr_lignes;
	int TotalAnims[20];

	bool Direction;
	int Vitesse;

	//Taille du template
	int l;
	int h;

	//Taille du sprite
	int SpriteHauteur;
	int SpriteLargeur;

};
