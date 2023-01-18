//============================================
//  Parcelle_ZN.h
//  TP4_NOTE
//
//  Created by Yanis Keto
//
//=============================================
#ifndef PARCELLE_ZN_H
#define PARCELLE_ZN_H

#include "Parcelle.h"
#include "Constructible.h"

class Parcelle_ZN : public Parcelle, public Constructible{
//Constructeur
  public :
  Parcelle_ZN(Parcelle *pParcelle);
  Parcelle_ZN(int pNumero, string pProprietaire, Polygone pForme);

  //Accesseurs
  public : void printInfo() const override;
  public : string getInfo() const override;

  //Fonctions vituelles
  private : void setType() override;
  private : float surfaceConstructible(void) const override;
};

#endif