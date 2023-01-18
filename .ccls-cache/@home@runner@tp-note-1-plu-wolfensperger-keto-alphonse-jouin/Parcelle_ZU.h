//============================================
//  Parcelle_ZU.h
//  TP4_NOTE
//
//  Created by Yanis Keto
//
//=============================================
#ifndef PARCELLE_ZU_H
#define PARCELLE_ZU_H

#include "Parcelle.h"
#include "Constructible.h"

class Parcelle_ZU : public Parcelle, public Constructible {
  private : float surfaceConstruite = 0;

  //Constructeur
  public :
  Parcelle_ZU(Parcelle *pParcelle, float pConstructible, float pSurfaceConstruite);
  Parcelle_ZU(int pNumero, string pProprietaire, Polygone pForme, float pConstructible, float pSurfaceConstruite);

  //Accesseurs
  public : void printInfo() const override;
  public : string getInfo() const override;

  //Fonctions vituelles
  private : void setType() override;
  private : float surfaceConstructible(void)
const override;

};

#endif