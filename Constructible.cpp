#include "Constructible.h"

Constructible::Constructible(float Constructible) {
  pConstructible = Constructible;
}

Constructible::Constructible(float Constructible, float pSurfaceConstruite) {
  pConstructible = Constructible;
  setSurfaceConstruite(pSurfaceConstruite);
}

void Constructible::setSurfaceConstruite(float pSurface) {
  surfaceConstruite = pSurface;
}

// Méthode pour construire sur une parcelle
void Constructible::construire(float pSurface, Parcelle &pParcelle) {
  if (surfaceDisponible(pSurface) && (pParcelle.type == parcelleTypes::ZU ||
                                      pParcelle.type == parcelleTypes::ZAU ||
                                      pParcelle.type == parcelleTypes::ZA)) {
    setSurfaceConstruite(surfaceConstruite + pSurface);
  }
}

// Méthode pour retourner la valeur de la surface disponible sur toute la surface constructible de la parcelle
bool Constructible::surfaceDisponible(float pSurface) {
  return surfaceConstructible() - surfaceConstruite > 0;
}