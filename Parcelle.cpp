#include "Parcelle.h"

Parcelle::Parcelle(int pNumero, string pProprietaire, Polygone pForme) {
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
Polygone Parcelle::getForme() const { return forme; }
string Parcelle::getStringType() const {
  string output;

  switch (type) {
  case ZU:
    output = "Zone urbaine";
    break;
  case ZAU:
    output = "Zone à urbaniser";
    break;
  case ZA:
    output = "Zone agricole";
    break;
  case ZN:
    output = "Zone naturelle et forestière";
    break;
  }

  return output;
}

// Setter
void Parcelle::setNumero(int pNumero) { numero = pNumero; }
void Parcelle::setProprietaire(string pProprietaire) {
  proprietaire = pProprietaire;
}
void Parcelle::setForme(Polygone pForme) {
  forme = pForme;
  surface = calculSurface();
}

// Méthode calcul de la surface de la parcelle
float Parcelle::calculSurface(void) {
  vector<Point2D<int>> points = forme.getSommets();
  float surface_v = 0;

  float sum = 0;

  for (int i = 0; i < points.size() - 1; i++) {
    sum += points[i].getX() * points[i + 1].getY();
    sum -= points[i + 1].getX() * points[i].getY();
  }
  surface_v = sum / 2;
  try {
    if (sum > 0) {
      surface_v = sum;
    } else {
      throw string("Surface incorrecte");
      surface_v = 0;
    }
  } catch (string const &err_msg) {
    cerr << "Exception : " << err_msg << endl;
  }
  return surface_v;
}

parcelleTypes Parcelle::getType() { return type; }