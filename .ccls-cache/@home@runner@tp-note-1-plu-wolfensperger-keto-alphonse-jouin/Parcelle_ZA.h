//============================================
//  Parcelle_ZA.h
//  TP4_NOTE
//
//  Created by Yanis Keto
//
//=============================================
#ifndef PARCELLE_ZA_H
#define PARCELLE_ZA_H

#include "Constructible.h"
#include "Parcelle.h"
#include <iostream>

class Parcelle_ZA : public Parcelle, public Constructible {
  //Proprietés
  private : string culture;

  //Constructeur
  public :
  Parcelle_ZA(Parcelle *pParcelle, string pCultureType);
  Parcelle_ZA(int pNumero, string pProprietaire, Polygone pForme, string pCultureType);

  //Accesseurs
  public : void printInfo() const override;

  //Fonctions vituelles
  private : void setType() override;
  private : float surfaceConstructible(void) const override;
  
};

#endif