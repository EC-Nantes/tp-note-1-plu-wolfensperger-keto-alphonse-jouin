//============================================
//  Parcelle.h
//  TP4_NOTE
//
//  Created by Yanis Keto
//
//=============================================
#ifndef CONSTRUCTIBLE_H
#define CONSTRUCTIBLE_H

#include "Parcelle.h"

class Parcelle;

class Constructible {
protected:
  float pConstructible = 0;
  float surfaceConstruite = 0;

public:
  Constructible(float Constructible);
  Constructible(float Constructible, float pSurfaceConstruite);

public:
  virtual float surfaceConstructible(void) const = 0;

public:
  void setSurfaceConstruite(float pSurface);

public:
  void construire(float pSurface, Parcelle &pParcelle);

public:
  bool surfaceDisponible(float pSurface);
};

#endif