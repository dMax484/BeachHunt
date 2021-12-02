#ifndef SHELL
#define SHELL

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Shell : public Item{
  public:
    Shell();
    Shell(string color,string shape, double length, double height);
    void setTraits(string color,string shape,double length, double height);
    void printTraits();
};
#endif