//
//  point_template.h
//  TP4_NOTE
//
//  Created by Frederic ALPHONSE on 13/01/2023.
//
//
#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class Point2D;

// Surcharge de l'opérateur
template <typename T>
std::ostream &operator<<(std::ostream &, Point2D<T> const &);

template <typename T> class Point2D {
private:
  T x;
  T y;

public:
  // constructeurs :
  Point2D(void);
  Point2D(T x = 0, T y = 0);
  Point2D(Point2D<T> const &p);

  // accesseurs en lecture :
  T getX() const;
  T getY() const;

  // accesseurs en lecture :
  void setX(T x);
  void setY(T y);

  void translate(T dx, T dy);
  friend std::ostream &operator<< <T>(std::ostream &, Point2D const &);
};

template <typename T> Point2D<T>::Point2D(T x, T y) {
  this->x = x;
  this->y = y;
}

template <typename T> Point2D<T>::Point2D(const Point2D<T> &p) {
  this->x = p.x;
  this->y = p.y;
}

template <typename T> void Point2D<T>::translate(T dx, T dy) {
  this->x += dx;
  this->y += dy;
}

// Accesseurs en lecture :
template <typename T> T Point2D<T>::getX() const { return this->x; }

template <typename T> T Point2D<T>::getY() const { return this->y; }

// Accesseurs en ecriture :
template <typename T> void Point2D<T>::setX(T x) { this->x = x; }

template <typename T> void Point2D<T>::setY(T y) { this->y = y; }

// Surcharge de l'opérateur cout pour afficher directement les caractéristique
// du point
template <typename T>
std::ostream &operator<<(std::ostream &o, Point2D<T> const &P) {
  o << "(" << P.getX() << "," << P.getY() << ")";
  return o;
}

#endif
// POINT2D_TEMPLATE_H