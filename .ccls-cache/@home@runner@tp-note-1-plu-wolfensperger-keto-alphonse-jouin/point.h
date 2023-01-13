//
//  point_template.h
//  TP3_Template
//
//  Created by Frederic ALPHONSE on 28/11/2022.
//
//
#ifndef POINT_H
#define POINT_H

#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class pointT;

//Surcharge de l'opérateur
template <typename T>
std::ostream& operator<<(std::ostream &, pointT<T> const&);

template <typename T>
class Point2D {
  private:
    T x;
    T y;

  public:
	  //constructeurs :
    Point2D();
    Point2D(T x, T y);
	  Point2D(Point2D<T> p);
	
    //accesseurs en lecture :
    T getX() { return x; }
    T getY() { return y; }
	
	 //accesseurs en lecture :
    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }

	  void translate(T dx, T dy);
};

#endif
//POINT_TEMPLATE_H