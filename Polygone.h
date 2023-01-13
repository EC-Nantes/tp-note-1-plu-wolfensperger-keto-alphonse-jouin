#include <vector>
#include "Point2D.h"

using namespace std;

class Polygone;

std::ostream &operator<<(std::ostream &, Polygone const &);

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

    friend std::ostream &operator<<(std::ostream &, Polygone const &);
};

std::ostream &operator<<(std::ostream &o, Polygone const &P) { 
  o << "(" << P.sommets[0];
  for(unsigned i=1; i<(P.sommets.size()); i++){
    o << "," << P.sommets[i];
  }
  o << ")" << endl;
  return o;
}