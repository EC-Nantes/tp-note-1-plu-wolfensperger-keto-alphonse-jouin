#include "Parcelle_ZU.h"

Parcelle_ZU::Parcelle_ZU(int pNumero, std::string pProprietaire,
                         Polygone pForme, float pConstructible, float pSurfaceConstruite)
    : Parcelle(pNumero, pProprietaire, pForme), Constructible(pConstructible, pSurfaceConstruite) {
  surfaceConstruite = pSurfaceConstruite;
}

Parcelle_ZU::Parcelle_ZU(Parcelle *pParcelle, float pConstructible, float pSurfaceConstruite)
    : Parcelle(pParcelle), Constructible(pConstructible, pSurfaceConstruite) {
  surfaceConstruite = pSurfaceConstruite;
}

void Parcelle_ZU::setType(void) { type = parcelleTypes::ZU; }

void Parcelle_ZU::printInfo(void) const {
  std::cout << "Type : " << getType() << std::endl;
  std::cout << "Proprietaire : " << proprietaire << std::endl;
  std::cout << "Surface : " << surface << std::endl;
  std::cout << "% constructible : " << pConstructible * 100 << " %"
            << std::endl;
  std::cout << "Surface construite : " << surfaceConstruite << std::endl;
  std::cout << "Surface à construire : " << surfaceConstructible() << std::endl;
  std::cout << "Polygone : " << forme << std::endl;
}

float Parcelle_ZU::surfaceConstructible(void) const {
  return surface * pConstructible - surfaceConstruite;
}