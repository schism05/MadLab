#include <SFML/Graphics.hpp>

int main()
{
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::Keyboard;

	if (!texture.loadFromFile("..\\..\\Users\\Student\\Desktop\\homme3.png"))
	{
		// erreur...
	}

	//initialisation
	int nbr_lignes = 2;
	int total_anims = 10;
	int vitesse = 8;
	bool go_left = false;

	sprite.setTexture(texture);

	//Taille du template
	int l = texture.getSize().x;
	int h = texture.getSize().y;

	//Taille du sprite
	int hauteur= h / nbr_lignes;
	int largeur = l / total_anims;

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
				window.close();
		}

		window.clear();

		int frame_index = int( clock.getElapsedTime().asSeconds() * vitesse ) % total_anims;

		sprite.setTextureRect(sf::IntRect((frame_index*largeur), hauteur, largeur, hauteur));

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			go_left = false;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			go_left = true;
		}

		if( go_left )
			sprite.setTextureRect(sf::IntRect((frame_index*largeur), 0, largeur, hauteur));

		else
			sprite.setTextureRect(sf::IntRect((frame_index*largeur), hauteur, largeur, hauteur));

		window.draw(sprite);
		window.display();
	}
	return 0;
}