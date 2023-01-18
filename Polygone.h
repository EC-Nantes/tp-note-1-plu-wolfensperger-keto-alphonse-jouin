#ifndef POLYGONE_H
#define POLYGONE_H

#include <vector>
#include "Point2D.h"

using namespace std;

//std::ostream &operator<<(std::ostream &, Polygone const &);

class Polygone {
  private:
    vector<Point2D<int>> sommets;

  public:
    //constructeurs :
    Polygone(void);
    Polygone(vector<Point2D<int>> listeSommets);
    Polygone(const Polygone &poly);
	
    //accesseurs en lecture :
    vector<Point2D<int>> getSommets() {return sommets;}
	
	  //accesseurs en écriture :
    void setSommets(vector<Point2D<int>> listeSommets) { this->sommets = listeSommets;}

    void addPoint(Point2D<int> sommet);
	  void translate(int dx, int dy);

    string getStringPolygon() const;

    friend std::ostream &operator<<(std::ostream &o, Polygone const &P);
};

#endif