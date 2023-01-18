// Nos bibliothèques

#include <iostream>
#include <stdio.h>

#include "Point2D.h"
#include "Polygone.h"
#include "Parcelle.h"
#include "Carte.h"
using namespace std;

// Auteurs : F.ALPHONSE & C.JOUIN & Y.KETO & R.WOLFENSPERGER
// Promo : SEC2024

// Jeux d'essais pour présenter nos résultats

// Surcharge de l'opérateur et construction Point2D
void test_point() {
  cout << "----------------------"
       << "Test SURCHARGE POINT"
       << "----------------------" << endl;
  Point2D<double> Point1(2.0, 3.0);
  cout << "Affichage Point" << Point1 << endl;
  cout << "--------------------------------------------" << endl << endl;
}

void test_polygone() {
  cout << "-----------------------"
       << "Test SURCHARGE POLYGONE"
       << "--------- -------------" << endl;
  vector<Point2D<int>> points;
  points.push_back(Point2D<int>(2, 3));
  points.push_back(Point2D<int>(1, 5));
  points.push_back(Point2D<int>(3, 4));

  Polygone poly(points);

  Point2D<int> point4(4, 4);

  cout << "Polygone Avant ajout d'un point :" << endl << poly << endl;
  poly.addPoint(point4);

  cout << "Polygone Avant Translation :" << endl << poly << endl;

  poly.translate(12, 12);

  cout << "Polygone après Translation de x :(12) et y :(12) :" << endl << poly << endl;
  cout << "--------------------------------------------" << endl << endl;
}

/*void test_parcelle() {
  cout << "----------------------"
       << "Test Classe Parcelle"
       << "----------------------" << endl;
  //CRÉATION PARCELLE
  vector<Point2D<int>> points;
  points.push_back(Point2D<int>(2, 3));
  points.push_back(Point2D<int>(1, 5));
  points.push_back(Point2D<int>(3, 4));
  Polygone poly(points);
  
  int Numero = 3;
  char Proprietaire[10]="Michel"; 
  Parcelle P(Numero, Proprietaire, poly);
  //Initialisation non possible car c'est une classe abstraite
  cout << "Parcelle Numéro :" << P.getNumero() << endl;
  cout << "Parcelle Proprio :" << P.getProprietaire() << endl;
  P.calculSurface();
  cout << "Parcelle surface :" << P.getSurface() << endl;
  cout << "Parcelle type :" << P.getType() << endl;
}*/

void test_carte() {
  cout << "----------------------"
       << "Test Carte"
       << "----------------------" << endl;
  cout << "Affichage de la carte \n" << endl;
  Carte carte("tp4-fichiers/Parcelles_short.txt");
  cout << "Carte :" <<endl << carte << endl;
  carte.sauvegarde("tp4-fichiers/sauvegarde.txt");
}

// Test swap à faire

int main() {
  std::cout << "Hello, World!\n";
  // test_point();
  //test_polygone();
  test_carte();
  return 0;
}
