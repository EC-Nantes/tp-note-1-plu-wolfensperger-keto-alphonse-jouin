//============================================
//  Parcelle_ZAU.h
//  TP4_NOTE
//
//  Created by Yanis Keto
//
//=============================================
#ifndef PARCELLE_ZAU_H
#define PARCELLE_ZAU_H

#include "Parcelle.h"
#include "Constructible.h"

class Parcelle_ZAU : public Parcelle, public Constructible {
//Constructeur
  public :
  Parcelle_ZAU(Parcelle *pParcelle, float pConstructible);
  Parcelle_ZAU(int pNumero, string pProprietaire, Polygone pForme, float pConstructible);

  //Accesseurs
  public : void printInfo() const override;
  public : string getInfo() const override;

  //Fonctions vituelles
  private : void setType() override;
  private : float surfaceConstructible(void) const override;
};

#endif