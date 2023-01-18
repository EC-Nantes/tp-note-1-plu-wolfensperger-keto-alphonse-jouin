//============================================
//  Parcelle.h
//  TP4_NOTE
//
//  Created by Yanis Keto
//
//=============================================
#ifndef PARCELLE_H
#define PARCELLE_H

#include "Constructible.h"
#include "Polygone.h"
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

using namespace std;

class Constructible;

enum parcelleTypes { ZU, ZAU, ZA, ZN };
/*
std::map<parcelleTypes, std::string> getTypeString = {
    {std::make_pair(parcelleTypes::ZU, "Zone urbaine")},
    {std::make_pair(parcelleTypes::ZAU, "Zone à urbaniser")},
    {std::make_pair(parcelleTypes::ZA, "Zone agricole")},
    {std::make_pair(parcelleTypes::ZN, "Zone naturelle et forestière")}};
*/
class Parcelle {

  friend class Constructible;

  // Paramètres
protected:
  parcelleTypes type;
  int numero;
  string proprietaire;
  float surface;
  Polygone forme;

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
  virtual void setType() = 0;

public:
  float calculSurface(void);

public:
  virtual void printInfo() const = 0;
};

#endif
// Parcelle_TEMPLATE_H
