#include "Parcelle_ZAU.h"

Parcelle_ZAU::Parcelle_ZAU(int pNumero, std::string pProprietaire,
                           Polygone pForme, float pConstructible)
    : Parcelle(pNumero, pProprietaire, pForme), Constructible(pConstructible) {
  setType();
}

Parcelle_ZAU::Parcelle_ZAU(Parcelle *pParcelle, float pConstructible)
    : Parcelle(pParcelle), Constructible(pConstructible) {
  setType();
}

void Parcelle_ZAU::setType(void) { type = parcelleTypes::ZAU; }

void Parcelle_ZAU::printInfo(void) const {
  std::cout << "Type : " << getStringType() << std::endl;
  std::cout << "Proprietaire : " << proprietaire << std::endl;
  std::cout << "Surface : " << surface << std::endl;
  std::cout << "% constructible : " << pConstructible * 100 << " %" << endl;
  std::cout << "Polygone : " << forme << std::endl;
}

float Parcelle_ZAU::surfaceConstructible(void) const {
  return surface * pConstructible;
}

string Parcelle_ZAU::getInfo() const {
  string output = "ZAU ";
  output += to_string((int)getNumero());
  output += " ";
  output += getProprietaire();
  output += " ";
  output += to_string((int)(pConstructible * 100));
  output += "\r";
  output += getForme().getString();
  return output;
}
