//============================================
//  Parcelle.h
//  TP4_NOTE
//
//  Created by Yanis Keto
//
//=============================================
#ifndef PARCELLE_H
#define PARCELLE_H

#include "Polygone.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class Parcelle {

  // Paramètres
private:
  string type;
  int numero;
  string proprietaire;
  float surface;
  Polygone<int> forme;
  int pConstructible;

  // Constructeur
  public : Parcelle(int pNumero, string pProprietaire, Polygone<int> pForme);
  public : Parcelle(Parcelle * parcelle);

  // Getter
  public : int getNumero() const;
  public : string getProprietaire() const;
  public : float getSurface() const;
  public : Polygone<int> getForme() const;
  public : string getType() const;

  // Setter
  public : void setNumero(int pNumero);
  public : void setProprietaire(string pProprietaire);
  public : void setForme(Polygone<int> pForme);
  public : void setType(string pType);
};

#endif
// Parcelle_TEMPLATE_H