#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Plateau;

class Case {
public :
    Case(double x, double y, bool vivant, Plateau* Pl);
    sf::Color get_vie();
    void naissance();
    void mort();
    void remove();
    void draw(sf::RenderTarget& target);
    void update();
private :
    bool vie;
    sf::RectangleShape carre;
    sf::Color couleur;
    int x;
    int y;
    Plateau* P;
};
