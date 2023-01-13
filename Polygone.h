#include <vector>
#include "Point2D.h"

using namespace std;

class Polygone {
  private:
    vector<Point2D<int>> sommets;

  public:
    //constructeurs :
    Polygone(void);
    Polygone(int listeSommets);
    Polygone(const Polygone &poly);
	
    //accesseurs en lecture :
    vector<Point2D<int>> getSommets() {return sommets;}
	
	  //accesseurs en lecture :
    void setSommets(vector<Point2D<int>> listeSommets) { this->sommets = listeSommets; }

    void addPoint(Point2D<int> sommet);
	  void translate(int dx, int dy);
};