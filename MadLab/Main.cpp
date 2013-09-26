#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "MadLab");
	sf::Clock clock;


	int totalAnims[] = { 4, 4, 2 };
	AnimatedSprite homme ("ham0.png",3,totalAnims);

	int nbrAnim[] = {2};
	AnimatedSprite lampe("lampe.png",1, nbrAnim);

	homme.Update(8);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if ((event.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
				window.close();
		}

		//obj animé à l'infini
		lampe.Update(6);

		//Il reste a faire précisément x nombres de boucles

		if((!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
			homme.Update(1, 2); //(vitesse, numero de ligne du sprite)

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			homme.Update(8, 0);

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			homme.Update(8, 1);

		window.clear();
		//window.draw(homme.sprite);
		window.draw(lampe.sprite);
		window.display();
	}
	return 0;
}
