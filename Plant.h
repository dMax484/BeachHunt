#ifndef PLANT
#define PLANT

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Plant : public Item{
  public:
    Plant();
    Plant(string color,string shape,double length);
    void setTraits(string color,string shape,double length);
    void printTraits();
};
#endif