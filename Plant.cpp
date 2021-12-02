#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

using namespace std;

#ifndef PLANT
#include "Plant.h"
#endif

Plant :: Plant(){
  setType("PLANT");
}

Plant :: Plant(string color,string shape,double length){
  setColor(color);
  setShape(shape);
  setLength(length);
}

void Plant :: setTraits(string color,string shape,double length){
  setColor(color);
  setShape(shape);
  setLength(length);
}

void Plant :: printTraits(){
  cout<<getColor()<<", ";
  cout<<getShape()<<", ";
  cout<<getLength()<<" inches long"<<endl;
}