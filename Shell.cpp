#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

using namespace std;

#ifndef SHELL
#include "Shell.h"
#endif

Shell :: Shell(){
  setType("SHELL");
}

Shell :: Shell(string color,string shape, double length, double height){
  setColor(color);
  setShape(shape);
  setLength(length);
  setHeight(height);
}

void Shell :: setTraits(string color,string shape, double length, double height){
  setColor(color);
  setShape(shape);
  setLength(length);
  setHeight(height);
}

void Shell :: printTraits(){
  cout<<getColor()<<", ";
  cout<<getShape()<<", ";
  cout<<getLength()<<" inches long, ";
  cout<<getHeight()<<" inches high"<<endl;
}