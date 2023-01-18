#ifndef CARTE_H
#define CARTE_H

#include "Point2D.h"
#include "Polygone.h"
#include "Parcelles.h"
#include <iostream>
#include <map>
#include <stdexcept>

using namespace std;

class Carte {
  private:
    vector<Parcelle*> parcelles;
    int surface_totale; 

  public:
  
    // Paramètres
    //std::vector<Parcelle> parcelles;
  
    // Constructeur
    Carte();
    Carte(const string &nomFichier);
  
    // Getter
    //vector<Parcelle> GetCarte() {return carte;}
    void sauvegarde(const string &nomFichierexport);

    friend std::ostream &operator<<(std::ostream &o, Carte const &C);
};

#endif