#ifndef GLASS
#define GLASS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Glass : public Item{
  public:
    Glass();
    Glass(string shine,string color,string origin,double length); //constructor: shine, color, origin, length
    void setTraits(string shine,string color,string origin,double length);
    void printTraits();
};
#endif