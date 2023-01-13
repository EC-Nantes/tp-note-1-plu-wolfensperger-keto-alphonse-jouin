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
#include <map>
#include <stdexcept>

using namespace std;

enum parcelleTypes { ZU, ZAU, ZA, ZN };
std::map<parcelleTypes, std::string> getTypeString{
    {std::make_pair(parcelleTypes::ZU, "Zone urbaine")},
    {std::make_pair(parcelleTypes::ZAU, "Zone à urbaniser")},
    {std::make_pair(parcelleTypes::ZA, "Zone agricole")},
    {std::make_pair(parcelleTypes::ZN, "Zone naturelle et forestière")}};

class Parcelle {

  // Paramètres
private:
  string type;
  int numero;
  string proprietaire;
  float surface;
  Polygone forme;
  int pConstructible;

  // Constructeur
public:
  Parcelle(int pNumero, string pProprietaire, Polygone pForme);

public:
  Parcelle(Parcelle *pParcelle);

  // Getter
public:
  int getNumero() const;

public:
  string getProprietaire() const;

public:
  float getSurface() const;

public:
  Polygone getForme() const;

public:
  string getType() const;

  // Setter
public:
  void setNumero(int pNumero);

public:
  void setProprietaire(string pProprietaire);

public:
  void setForme(Polygone pForme);

public:
  virtual void setType(string pType) const = 0;

public:
  float calculSurface(void);
};

#endif
// Parcelle_TEMPLATE_H
