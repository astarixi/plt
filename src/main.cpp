#include <iostream>

//test Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "./state.h"
#include "./render.h"
#include "./engine.h"
#include "./ia.h"
#include <vector>

// Fin test SFML


using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;
using namespace ia;

int main(int argc,char* argv[]) 
{
    // create the window
	cout << "[Main] Initialisation de ma fenetre" << endl;   
	sf::RenderWindow window(sf::VideoMode(1000, 800), "grille");

	cout << "[Main] Creation de l'etat" << endl;
	Etat* e= new Etat; 
	cout << "[Main] Rajout des persos" << endl;
	e->rajouterPerso('h');
	cout << "[Main] Accès a un perso" << endl;
	Personnage& p = e->getRefPersonnage(0);
	cout << "[Main] Parametrisation du perso" << endl;
	p.setTypePersonnage(TypePersonnage(HEROS));
	p.setX(200);
	p.setY(350);
	p.setDirection(OUEST);
        p.setEnDeplacement(false);
	sf::Clock c;
	sf::RenderStates rs;
        ListeCommandes liste;
        std::vector<int> v;
	v.push_back(1);
	// On devrait rajouter dans les commandes une vérification de l'existence des parametres.
	std::cout << "[Main] Initialisation de la Map" << std::endl;
	liste.Ajouter(Commande (e,"cm",c.getElapsedTime(),v,0));
	liste.ToutExecuter();
    // create the tilemap from the level definition
    //RenduGrille map;
	std::cout << "[Main] Initialisation du rendu" << endl;
	Rendu r;
	IAminimale ias(e);
	std::vector <int> IdPersosMonstres;
	for (int i = 1; i < e->getPersoSize(); ++i) {
			IdPersosMonstres.push_back(i);
		
	}

    // run the main loop
	std::cout << "[Main] Debut de la boucle" << std::endl;
	std::cout << "/!\\ Si jamais, il n'y a qu'un seul personnage sur la carte, relancer le jeu"  << std::endl;
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x=event.mouseButton.x;
                    int y=event.mouseButton.y;
                    sf::Vector2f pos = e->getGrilleCoord(x,y); 
                    v.push_back(pos.x);
                    v.push_back(pos.y);
                    Commande cmd(e,"d",c.getElapsedTime(),v,0);
                    liste.Ajouter(cmd);
                    v.clear();
                    std::cout<< "pos Souris " << x << " et " << y << std::endl;
                    std::cout<< "pos Grille " << pos.x << " et " << pos.y << std::endl;
                    
                    //cmd1.run();
                }
            }
        }

	// IA 
	for (int i = 0; i < IdPersosMonstres.size(); ++i) {
		liste.Ajouter(ias.exec_cmd(IdPersosMonstres[i], c.getElapsedTime())); 	
	}

	// Update Persos
	for (int i = 0; i < e->getPersoSize(); ++i) {
        	Commande cmdUpdate(e,"u",c.getElapsedTime(),v,i);
        	liste.Ajouter(cmdUpdate);
	}
        v.clear();
        int mapact;
        if (e->getMapActuel()==1)
        mapact=2;
        else
        mapact=1;
        v.push_back(mapact);
        std::cout<<"[main] changer de map:"<<v[0]<<std::endl;
        Commande cmd1(e,"cm",c.getElapsedTime(),v,0);
        liste.Ajouter(cmd1);
	v.clear();
	liste.ToutExecuter();

        // draw the map
        window.clear();
	v.clear();
        r.run(e, window, c.getElapsedTime(), rs);
        window.display();
    }

    return 0;
}
