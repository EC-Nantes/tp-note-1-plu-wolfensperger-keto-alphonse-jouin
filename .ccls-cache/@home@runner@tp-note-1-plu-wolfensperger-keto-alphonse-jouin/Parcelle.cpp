#include "Parcelle.h"

Parcelle::Parcelle(int pNumero, string pProprietaire, Polygone<int> pForme) {
  nu    
}

Parcelle::Parcelle(Parcelle *parcelle) {}

// Getter
int Parcelle::getNumero() const { return numero; }
string Parcelle::getProprietaire() const { return proprietaire; }
float Parcelle::getSurface() const { return surface; }
Polygone<int> Parcelle::getForme() const { return forme; }
string Parcelle::getType() const { return type; }

// Setter
void Parcelle::setNumero(int pNumero) { numero = pNumero; }
void Parcelle::setProprietaire(string pProprietaire) { proprietaire = pProprietaire; }
void Parcelle::setForme(Polygone<int> pForme) { forme = pForme }
void Parcelle::setType(string pType) {type = pType; }