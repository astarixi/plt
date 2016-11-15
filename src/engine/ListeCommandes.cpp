#include "../engine.h"
#include <iostream>
using namespace engine;
using namespace std;
void ListeCommandes::Ajouter (Commande cmd){
    commandes.push_back(cmd);
}

void ListeCommandes::ToutExecuter (){
    if (commandes.size() > 0){
        unsigned int i;
        for (i=0;i<commandes.size();i++){
            (commandes[i]).run();
        }
        commandes.clear();
    }
}

