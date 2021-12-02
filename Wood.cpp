#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

using namespace std;

#ifndef WOOD
#include "Wood.h"
#endif

Wood :: Wood(){
  setType("WOOD");
}

Wood :: Wood(string color,string streak,string shade, double length){
  setColor(color);
  setStreak(streak);
  setShade(shade);
  setLength(length);
}

void Wood :: setTraits(string color,string streak,string shade, double length){
  setColor(color);
  setStreak(streak);
  setShade(shade);
  setLength(length);
}

void Wood :: printTraits(){
  cout<<getColor()<<", ";
  cout<<getStreak()<<", ";
  cout<<getShade()<<", ";
  cout<<getLength()<<" inches long"<<endl;
}