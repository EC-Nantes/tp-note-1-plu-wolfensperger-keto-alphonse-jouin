#include "Carte.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Carte::Carte(const string &nomFichier) {
  // On crée un objet ifstream pour ouvrir le fichier en mode lecture

  string ligne;
  vector<Point2D<int>> points;
  
  ifstream fichier(nomFichier);
  // On vérifie si le fichier est ouvert
  if (fichier.is_open()){
    // On lit les mots dans le fichier un par un

    while (getline(fichier, ligne)) {
      // char token[];
      // char cligne[80] = ligne

      stringstream sligne(ligne);
      string typeParcelle;
      sligne >> typeParcelle;
      string numProprietaire;
      sligne >> numProprietaire;
      string nomProprietaire;
      sligne >> nomProprietaire;

      getline(fichier, ligne); // se rend à la ligne suivant
      stringstream sligne_coord(ligne); //decompose la ligne
      string point;
      Polygone poly;
      while(sligne_coord >> point){ // tant qu'il rest des coordonnees
        size_t index = point.find(";",1); // localiser le ";"
        size_t index2 = point.size()-index-2;
        // en déduire et convertir en int x et y :
        int x = stoi(point.substr(1,index-1));
        int y = stoi(point.substr(index+1,index2));
        Point2D<int> p(x, y); // creer un Point2D à partir des coordonnées
        poly.addPoint(p); // ajouter le point au polygone
      }
      
      if(typeParcelle=="ZU"){
        string pConstructible;
        sligne >> pConstructible;
        string surfaceConstruite;
        sligne >> surfaceConstruite;
        
        //constructeur
        this->parcelles.push_back(new Parcelle_ZU(stoi(numProprietaire), nomProprietaire, poly, stof(pConstructible)/100, stof(surfaceConstruite)));
      }
      else if (typeParcelle=="ZAU") {
        string pConstructible;
        sligne >> pConstructible;
        
        //constructeur
        this->parcelles.push_back(new Parcelle_ZAU(stoi(numProprietaire), nomProprietaire, poly, stof(pConstructible)/100));
      }
      else if (typeParcelle=="ZA"){
        string typeCulture;
        sligne >> typeCulture;
        
        //constructeur
        this->parcelles.push_back(new Parcelle_ZA(stoi(numProprietaire), nomProprietaire, poly, typeCulture));
      }
      else if (typeParcelle=="ZN") {
        //constructeur
        this->parcelles.push_back(new Parcelle_ZN(stoi(numProprietaire), nomProprietaire, poly));
      }
    }
    // On ferme le fichier
    fichier.close();
  }
  else {
    cout << "Impossible d'ouvrir le fichier " << nomFichier << endl;
  }

  
}

std::ostream &operator<<(std::ostream &o, Carte const &C) { 
  //o << "(" << P.sommets[0]
  for (int i=0; i<C.parcelles.size(); i++) {
    C.parcelles[i]->printInfo();
    o << endl;
  }
  return o;
}
