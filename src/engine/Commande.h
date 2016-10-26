// Generated by dia2code
#ifndef ENGINE__COMMANDE__H
#define ENGINE__COMMANDE__H

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../state.h"
#include <string>
#include <vector>

namespace state {
  class Etat;
};
namespace engine {
  class Regles;
  class ListeCommandes;
  class Action;
}

#include "Regles.h"
#include "ListeCommandes.h"
#include "Action.h"

namespace engine {

  /// class Commande - 
  class Commande {
    // Associations
    // Attributes
  protected:
    std::map<char,Action*> mmap;
    sf::Clock cl;
    // Operations
  public:
    Commande (state::Etat* e, sf::Clock cl, std::string cmd, int id, std::vector<int> params);
    ~Commande ();
    int const getSize ();
  };

};

#endif
