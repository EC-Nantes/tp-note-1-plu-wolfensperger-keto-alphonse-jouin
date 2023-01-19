#include "Carte.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Constructeur pour générer la carte à partir d'un fichier texte
Carte::Carte(const string &nomFichier) {
  // On crée un objet ifstream pour ouvrir le fichier en mode lecture
  ifstream fichier(nomFichier);
  string ligne;
  vector<Point2D<int>> points;

  // On vérifie si le fichier est ouvert
  if (fichier.is_open()) {
    // On lit les lignes dans le fichier un par un
    while (getline(fichier, ligne)) {

      // Decomposition de la ligne en differents elements
      stringstream sligne(ligne);
      string typeParcelle;
      sligne >> typeParcelle;
      string numProprietaire;
      sligne >> numProprietaire;
      string nomProprietaire;
      sligne >> nomProprietaire;

      getline(fichier, ligne);          // se rend à la ligne suivant
      stringstream sligne_coord(ligne); // decompose la ligne
      string point;
      Polygone poly;
      // Boucle pour parcourir tous les points de la parcelle
      while (sligne_coord >> point) { 
        // Localisation du ";" pour déduire les coordonnées x et y
        size_t index = point.find(";", 1);
        size_t index2 = point.size() - index - 2;
        int x = stoi(point.substr(1, index - 1));
        int y = stoi(point.substr(index + 1, index2));
        Point2D<int> p(x, y); // Creation d'un Point2D à partir des coordonnées
        poly.addPoint(p);     // ajouter le point au polygone
      }

      // Creation des objets de parcelle en fonction des informations lues dans le fichier
      if (typeParcelle == "ZU") {
        string pConstructible;
        sligne >> pConstructible;
        string surfaceConstruite;
        sligne >> surfaceConstruite;

        // constructeur
        this->parcelles.push_back(new Parcelle_ZU(
            stoi(numProprietaire), nomProprietaire, poly,
            stof(pConstructible) / 100, stof(surfaceConstruite)));
      } else if (typeParcelle == "ZAU") {
        string pConstructible;
        sligne >> pConstructible;

        // constructeur
        this->parcelles.push_back(new Parcelle_ZAU(stoi(numProprietaire),                 nomProprietaire, poly, stof(pConstructible) / 100));
      } else if (typeParcelle == "ZA") {
        string typeCulture;
        sligne >> typeCulture;

        // constructeur
        this->parcelles.push_back(new Parcelle_ZA(
            stoi(numProprietaire), nomProprietaire, poly, typeCulture));
      } else if (typeParcelle == "ZN") {
        // constructeur
        this->parcelles.push_back(
            new Parcelle_ZN(stoi(numProprietaire), nomProprietaire, poly));
      }
    }
    // On ferme le fichier
    fichier.close();
  } else {
    cout << "Impossible d'ouvrir le fichier " << nomFichier << endl;
  }
}

// Méthode pour sauvegarder la carte dans un fichier texte
void Carte::sauvegarde(const string &nomFichier) {
    // Ouverture du fichier en mode écriture
    ofstream fichier(nomFichier);
    // Vérification de l'ouverture du fichier
    if (fichier.is_open()) {
      // Boucle pour parcourir toutes les parcelles de la carte
      for (int i = 0; i < this->parcelles.size(); i++) {
        // Ecriture des informations de la parcelle dans le fichier
        fichier << this->parcelles[i]->getInfo() <<endl;
      }
        // Fermeture du fichier
        fichier.close();
    } else {
        // Afficher un message d'erreur si le fichier ne peut pas être ouvert
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
}

// surcharge de l'opérateur << pour afficher la carte
std::ostream &operator<<(std::ostream &o, Carte const &C) {
  for (int i = 0; i < C.parcelles.size(); i++) {
    C.parcelles[i]->printInfo();
    o << endl;
  }
  return o;
}
