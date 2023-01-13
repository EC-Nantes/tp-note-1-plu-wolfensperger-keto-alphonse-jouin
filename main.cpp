// Nos bibliothèques
#include "Point2D.h"
#include "Polygone.h"
         "
#include <iostream>
#include <stdio.h>
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

  cout << "Polygone Avant ajout d'un point :" << poly << endl;
  poly.addPoint(point4);

  cout << "Polygone Avant Translation :" << poly << endl;

  poly.translate(12, 12);

  cout << "Polygone après Translation de x :(12) et y :(12) :" << poly << endl;
  cout << "--------------------------------------------" << endl << endl;
}
/*
void test_rectangle() {
  cout << "----------------------"
       << "Test Function 3"
       << "----------------------" << endl;
  pointT<int> point1(2.0, 3.0);
  cout << "Point :" << point1 << endl;

  int largeur = 5;
  int hauteur = 3;

  rectangle<int, int> rectanglees(point1, largeur, hauteur);
  cout << "Après la construction d'un rectangle ( largeur = 5 et hauteur = 3): "
       << point1 << endl;

  cout << "Calcul du périmètre :" << rectanglees.perimetre() << endl;
  cout << "Calcul de la surface :" << rectanglees.surface() << endl;
  cout << "--------------------------------------------" << endl << endl;
}

void test_carre() {
  cout << "----------------------"
       << "Test Function 3"
       << "----------------------" << endl;
  pointT<int> point1(2.0, 3.0);
  cout << "Point :" << point1 << endl;

  int cote = 5;

  carre<int, int> carrees(point1, cote);
  cout << "Après la construction d'un carre ( cote = 5): " << point1 << endl;

  cout << "Calcul du périmètre carrée:" << carrees.perimetre() << endl;
  cout << "Calcul de la surface carrée:" << carrees.surface() << endl;
  cout << "--------------------------------------------" << endl << endl;
}*/

// Test swap à faire

int main() {
  std::cout << "Hello, World!\n";
  // test_point();
  test_polygone();
  return 0;
}
