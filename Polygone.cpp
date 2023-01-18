#include <vector>
#include "Polygone.h"

using namespace std;

Polygone::Polygone(void){}

Polygone::Polygone(vector<Point2D<int>> listeSommets){
	this->sommets = listeSommets;
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

string Polygone::getString() const {
  string output;
  for(int i = 0; i < sommets.size(); i++){
    output += "[";
    output += to_string(sommets[i].getX());
    output += ";";
    output += to_string(sommets[i].getY());
    output += "] ";
  }
  return output;
}

std::ostream &operator<<(std::ostream &o, Polygone const &P) { 
  o << "(" << P.sommets[0];
  for(unsigned i=1; i<(P.sommets.size()); i++){
    o << "," << P.sommets[i];
  }
  o << ")" << endl;
  return o;
}
