#include "case.hpp"
#include <SFML/Graphics.hpp>
#include "plateau.hpp"

using namespace std;

Case::Case(double x, double y, bool vivant, Plateau *Pl)
    :vie(vivant),
     couleur(sf::Color::White),
     x(x/10),
     y(y/10),
     P(Pl)
{
    carre.setSize(sf::Vector2f(10, 10));
    carre.setPosition(x, y);
}

sf::Color Case::get_vie() {
    return couleur;
}

void Case::naissance() {
    vie = true;
}

void Case::mort() {
    vie = false;
}

void Case::remove() {
    vie = !vie;
}

void Case::draw(sf::RenderTarget& target) {
    if (vie) {
        couleur =sf::Color::Black;
    } else {
        couleur = sf::Color::White;
    }
    carre.setFillColor(couleur);
    target.draw(carre);
}

void Case::update() {
    int voisin(P->compte(x,y));
    if(voisin != 0) {
        cerr << voisin << " ";
    }

    if(vie and (voisin != 2 and voisin != 3)) {
        mort();
    } else if (!vie and voisin == 3) {
        naissance();
    }
}
