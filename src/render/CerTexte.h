// Generated by dia2code
#ifndef RENDER__CERTEXTE__H
#define RENDER__CERTEXTE__H

#include <SFML/Graphics.hpp>

namespace render {

  /// class CerTexte - 
  class CerTexte {
    // Attributes
  public:
    sf::Texte Texte;
    sf::CircleShape Cercle;
    sf::Font font;
    // Operations
  public:
    void ChangeTexte (String t);
    CerTexte ();
    ~CerTexte ();
  };

};

#endif
