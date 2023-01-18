#include "Parcelle_ZA.h"

Parcelle_ZA::Parcelle_ZA(int pNumero, std::string pProprietaire,
                         Polygone pForme, std::string pCultureType)
    : Parcelle(pNumero, pProprietaire, pForme), Constructible(0) {
  culture = pCultureType;
  setType();
}

Parcelle_ZA::Parcelle_ZA(Parcelle *pParcelle, std::string pCultureType)
    : Parcelle(pParcelle), Constructible(0) {
  culture = pCultureType;
  setType();
}

void Parcelle_ZA::setType(void) { type = parcelleTypes::ZA; }

void Parcelle_ZA::printInfo(void) const {
  std::cout << "Type : " << getStringType() << std::endl;
  std::cout << "Proprietaire : " << proprietaire << std::endl;
  std::cout << "Surface : " << surface << std::endl;
  std::cout << "Type de culture : " << culture << endl;
  std::cout << "Polygone : " << forme << std::endl;
}

float Parcelle_ZA::surfaceConstructible(void) const {
  float output = surface * 0.1;

  if (output <= 200) {
    return output;
  } else {
    return 200;
  }
}
// public : string getInfo() const override;
string Parcelle_ZA::getInfo() const {
  string output = "ZA ";
  output += to_string((int)getNumero());
  output += " ";
  output += getProprietaire();
  output += " ";
  output += culture;
  output += "\r";
  output += getForme().getString();
  return output;
}