#include "Parcelle_ZN.h"

Parcelle_ZN::Parcelle_ZN(int pNumero, std::string pProprietaire,
                         Polygone pForme)
    : Parcelle(pNumero, pProprietaire, pForme), Constructible(0) {
  setType();
}

Parcelle_ZN::Parcelle_ZN(Parcelle *pParcelle)
    : Parcelle(pParcelle), Constructible(0) {
  setType();
}

void Parcelle_ZN::setType(void) { type = parcelleTypes::ZN; }

void Parcelle_ZN::printInfo(void) const {
  std::cout << "Type : " << getStringType() << std::endl;
  std::cout << "Proprietaire : " << proprietaire << std::endl;
  std::cout << "Surface : " << surface << std::endl;
  std::cout << "Polygone : " << forme << std::endl;
}

float Parcelle_ZN::surfaceConstructible(void) const { return 0; }

string Parcelle_ZN::getInfo() const {
  string output = "ZN ";
  output += to_string((int)getNumero());
  output += " ";
  output += getProprietaire();
  output += "\r";
  output += getForme().getStringPolygon();
  return output;
}