#include "Parcelle.h"

Parcelle::Parcelle(int pNumero, string pProprietaire, Polygone<int> pForme) {
  setNumero(pNumero);
  setProprietaire(pProprietaire);
  setForme(pForme);
}

Parcelle::Parcelle(Parcelle *pParcelle) {
  setNumero(pParcelle->getNumero());
  setProprietaire(pParcelle->getProprietaire());
  setForme(pParcelle->getForme());
}

// Getter
int Parcelle::getNumero() const { return numero; }
string Parcelle::getProprietaire() const { return proprietaire; }
float Parcelle::getSurface() const { return surface; }
Polygone<int> Parcelle::getForme() const { return forme; }
string Parcelle::getType() const { return type; }

// Setter
void Parcelle::setNumero(int pNumero) { numero = pNumero; }
void Parcelle::setProprietaire(string pProprietaire) {
  proprietaire = pProprietaire;
}
void Parcelle::setForme(Polygone<int> pForme) {
  forme = pForme;
  surface = calculSurface();
}
void Parcelle::setType(string pType) { type = pType; }

// Fonction
float Parcelle::calculSurface(void) {
  vector<Point2D<int>> points = forme.getSommets();

  float sum = 0;

  for (int i = 0; i < points.size() - 1; i++) {
    sum += points[i].getX() * points[i + 1].getY();
    sum -= points[i + 1].getX() * points[i].getY();
  }

  surface = sum / 2;
}
