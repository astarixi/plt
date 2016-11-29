// Generated by dia2code
#ifndef STATE__GRILLEELEMENTS__H
#define STATE__GRILLEELEMENTS__H


namespace state {
  class Etat;
  class Element;
  class ListeElements;
}

#include "ListeElements.h"

namespace state {

  /// class GrilleElements - 
  class GrilleElements : public state::ListeElements {
    // Attributes
  protected:
    int longueur;
    int largeur;
    // Operations
  public:
    GrilleElements (int nv, Etat* etat);
    int getLongueur ();
    int getLargeur ();
    bool const isAcces (int i, int j);
    void setCase (Element* e, int i, int j);
    void charger (char* nom_fichier);
    void setLongueur (int i);
    void setLargeur (int i);
    void ajoutCaseAcces (int i, int j);
  };

};

#endif
