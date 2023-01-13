#include <vector>
#include "Polygone.h"

using namespace std;

Polygone::Polygone(void){}

Polygone::Polygone(int listeSommets){
	this->sommets. = listeSommets;
}

Polygone::Polygone(const Polygone &poly){
  this->sommets = poly.sommets;
}

void Polygone::addPoint(Point2D<int> sommet) {
    this->sommets.push_back(sommet);
}

void Polygone::translate(int dx, int dy) {
  for(unsigned i=0; i<(this->sommets.size()); i++){
    this->sommets[i].translate(dx, dy);
  }
}