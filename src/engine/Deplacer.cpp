#include "../engine.h"
#include "../state.h"

#include <iostream>

using namespace engine;
using namespace state;

#define ECART 2

int abs (int a) { return a >= 0 ? a : -a; }
int signe (int a) { return a >= 0 ? 1 : -1; }


/* Params :
0 -> id du personnage 
Besoin : clock ! > Changer le constructeur
*/

void Deplacer::run(Etat* e, std::vector<int> params,sf::Time t) {
	Personnage & p = e->getRefPersonnage(params[0]);
	if (p.getEnDeplacement()) {
		std::cout << "Maj Position" << std::endl;
	      	// Appel à la regle pour obtenir la vitesse du personnage !
	      	int speed = 1;
	      
	      	if (abs(p.getX()-p.getXobj()) > ECART) { 
			// Quand j'aurais une clock correcte
			p.setX(p.getX() + signe(p.getXobj()-p.getX()) * speed * (t.asMilliseconds()-p.getTimer().asMilliseconds()));
		}
	     	else if (abs(p.getY()-p.getYobj()) > ECART) {
			// Quand j'aurais une clock correcte
			p.setY(p.getY() + signe(p.getYobj()-p.getY()) * speed * (t.asMilliseconds()-p.getTimer().asMilliseconds()));
	      	}
		else {
			p.setEnDeplacement(false);
		}
	}
}
