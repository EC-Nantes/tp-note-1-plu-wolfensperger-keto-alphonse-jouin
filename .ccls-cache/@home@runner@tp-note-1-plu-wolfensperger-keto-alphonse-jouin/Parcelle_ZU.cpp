#include "Parcelle_ZU.h"

Parcelle_ZU::Parcelle_ZU(int pNumero, std::string pProprietaire,
                         Polygone pForme, float pConstructible, float pSurfaceConstruite)
    : Parcelle(pNumero, pProprietaire, pForme), Constructible(pConstructible, pSurfaceConstruite) {
  surfaceConstruite = pSurfaceConstruite;
  setType();
}

Parcelle_ZU::Parcelle_ZU(Parcelle *pParcelle, float pConstructible, float pSurfaceConstruite)
    : Parcelle(pParcelle), Constructible(pConstructible, pSurfaceConstruite) {
  surfaceConstruite = pSurfaceConstruite;
  setType();
}

void Parcelle_ZU::setType(void) { type = parcelleTypes::ZU; }

void Parcelle_ZU::printInfo(void) const {
  std::cout << "Type : " << getStringType() << std::endl;
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

string Parcelle_ZU::getInfo() const {
  string output = "ZU ";
  output += to_string((int)getNumero());
  output += " ";
  output += getProprietaire();
  output += " ";
  output += to_string((int)(pConstructible*100));
  output += " ";
  output += to_string((int)surfaceConstruite);
  output += "\r";
  output += getForme().getString();
  return output;
}