#include <SFML/Graphics.hpp>
#include "fichier/case.hpp"
#include "fichier/plateau.hpp"


using namespace std;

int main()
{
    //window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Jeu de la vie");

    //Texts
    sf::Font font;
    font.loadFromFile("../res/sansation.ttf");

    //plateau
    Plateau P(500, font);

    //Temps
    sf::Clock horloge;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed)
                {
                    //Traitement de l'événement, par exemple fermeture de la fenêtre:
                    window.close();
                }

            if (event.type == sf::Event::KeyPressed)
                {
                    switch(event.key.code)
                    {
                        case(sf::Keyboard::A):

                        P.remove(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                        break;

                        case(sf::Keyboard::Space):

                        P.on_run();
                        break;

                        case(sf::Keyboard::R):

                        P.restart();
                        break;

                        default:

                        break;
                    }
                }
        }

        P.update(horloge.getElapsedTime());
        horloge.restart();

        P.draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}
