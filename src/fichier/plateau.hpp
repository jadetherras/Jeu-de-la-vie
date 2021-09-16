#pragma once
#include <iostream>
#include <array>
#include "case.hpp"

class Plateau {
public :
    Plateau(unsigned int T, sf::Font &font);
    void draw(sf::RenderTarget& target);
    void remove(unsigned int x, unsigned int y);
    void update(sf::Time T);
    int compte(unsigned int x, unsigned int y);
    void on_run();
    void restart();
private :
    unsigned int taille;
    std::vector<std::vector<Case*>> tableau;
    sf::Time temps;
    bool on;
    sf::Text run;
    sf::Text information;
    sf::Clock Ts;
    sf::Text T;
};
