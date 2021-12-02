#include <iostream>
#include <vector>
#include <string>
#include "Item.h"

using namespace std;

#ifndef GLASS
#include "Glass.h"
#endif

Glass :: Glass(){
  setType("GLASS");
}

Glass :: Glass(string shine,string color,string origin,double length){
  setShine(shine);
  setColor(color);
  setOrigin(origin);
  setLength(length);
}

void Glass :: setTraits(string shine,string color,string origin,double length){
  setShine(shine);
  setColor(color);
  setOrigin(origin);
  setLength(length);
}

void Glass :: printTraits(){
  cout<<getShine()<<",";
  cout<<getColor()<<",";
  cout<<getOrigin()<<",";
  cout<<getLength()<<" inches long"<<endl;
}