#include "Parcelle_ZAU.h"

Parcelle_ZAU::Parcelle_ZAU(int pNumero, std::string pProprietaire,
                           Polygone pForme, float pConstructible)
    : Parcelle(pNumero, pProprietaire, pForme), Constructible(pConstructible) {}

Parcelle_ZAU::Parcelle_ZAU(Parcelle *pParcelle, float pConstructible)
    : Parcelle(pParcelle), Constructible(pConstructible) {}

void Parcelle_ZAU::setType(void) { type = parcelleTypes::ZAU; }

void Parcelle_ZAU::printInfo(void) const {
  std::cout << "Type : " << getType() << std::endl;
  std::cout << "Proprietaire : " << proprietaire << std::endl;
  std::cout << "Surface : " << surface << std::endl;
  std::cout << "% constructible : " << pConstructible << " %" << endl;
  std::cout << "Polygone : " << forme << std::endl;
}

float Parcelle_ZAU::surfaceConstructible(void) const {
  return surface * pConstructible;
}