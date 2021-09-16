#include "plateau.hpp"
#include <iostream>

using namespace std;

class Case;

Plateau::Plateau(unsigned int T, sf::Font &font)
    :taille(T/10),
     temps(sf::Time::Zero),
     on(false)
{
    for (unsigned int i(0); i < taille; ++i) {
        vector<Case*> n;
        tableau.push_back(n);
        for(unsigned int j(0); j < taille; ++j) {
            tableau[i].push_back(new Case(i*10,j*10,false, this));
        }
    }

    sf::Text texte("stop", font, 18);
    texte.setStyle(sf::Text::Bold); //En gras
    texte.setFillColor(sf::Color::Blue); //Couleur
    texte.setPosition(430,0);
    run = texte;

    sf::Text Ta(std::to_string(Ts.getElapsedTime().asSeconds()), font, 18);
    Ta.setStyle(sf::Text::Bold); //En gras
    Ta.setFillColor(sf::Color::Blue); //Couleur
    Ta.setPosition(10,0);
    this->T = Ta;

    sf::Text info("space : stat/stop \nA : remove/add a cell \nR : restart", font, 15);
    info.setFillColor(sf::Color::Blue); //Couleur
    info.setPosition(350,445);
    information = info;
}

void Plateau::draw(sf::RenderTarget& target) {
    for (auto l : tableau) {
        for(auto c : l) {
            c->draw(target);
        }
    }
        target.draw(run);
        target.draw(information);

    T.setString(std::to_string(Ts.getElapsedTime().asSeconds()));
    target.draw(T);
}

void Plateau::remove(unsigned int x,unsigned int y) {
    tableau[x/10][y/10]->remove();
}

void Plateau::update(sf::Time T)  {    
    temps += T;
    if(on and temps >= sf::seconds(1.0)) {
        for (auto l : tableau) {
            for(auto c : l) {
                c->update();
                }
            }
        temps = sf::Time::Zero;

    }
}

int Plateau::compte(unsigned int x,unsigned int y) {
    int N(0);
    if(x != 0 and tableau[x-1][y]->get_vie() == sf::Color::Black) {
        ++N;
    }
    if(x != 0 and y != 0 and tableau[x-1][y-1]->get_vie() == sf::Color::Black) {
        ++N;
    }
    if(x != 0 and y != tableau.size()-1 and tableau[x-1][y+1]->get_vie() == sf::Color::Black) {
        ++N;
    }
    if(y != 0 and tableau[x][y-1]->get_vie() == sf::Color::Black) {
        ++N;
    }
    if(y != tableau.size()-1 and tableau[x][y+1]->get_vie() == sf::Color::Black) {
        ++N;
    }
    if(x != tableau.size()-1 and tableau[x+1][y]->get_vie() == sf::Color::Black) {
        ++N;
    }
    if(x != tableau.size()-1 and y != 0 and tableau[x+1][y-1]->get_vie() == sf::Color::Black) {
        ++N;
    }
    if(x != tableau.size()-1 and y != tableau.size()-1 and tableau[x+1][y+1]->get_vie() == sf::Color::Black) {
        ++N;
    }
    return N;
}

void Plateau::on_run() {
    on = !on;
    if (on) {
        run.setString("on run");
    } else {
        run.setString("stop");
    }
}

void Plateau::restart() {
    on = false;
    run.setString("stop");
    for (auto L : tableau) {
        for(auto c : L) {
            c->mort();
        }
    }
    Ts.restart();
}
