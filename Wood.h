#ifndef WOOD
#define WOOD

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Wood : public Item{
  public:
    Wood();
    Wood(string color,string streak,string shade, double length);
    void setTraits(string color,string streak,string shade, double length);
    void printTraits();
};
#endif