#ifndef ITEM
#include "Item.h"
#endif

#include <iostream>
#include <string>
using namespace std;

Item :: Item(){ //constructor sets each trait to empty
  setType("");
  setColor("");
  setLength(0);
  setHeight(0);
  setShape("");
  setShade("");
  setStreak("");
  setShine("");
  setOrigin("");  
}

void Item :: setTraits(){
  cout<<"this shouldn't happen";
}

void Item :: printTraits(){
  cout<<"this shouldn't happen";
}

//set and gets for the item's attributes
void Item :: setType(string t){
  this->type = t;
}
string Item :: getType(){
  return this->type;
}
void Item :: setColor(string c){
  this->color = c;
}
string Item :: getColor(){
  return this->color;
}
void Item :: setLength(double l){
  this->length = l;
}
double Item :: getLength(){
  return this->length;
}
void Item :: setHeight(double h){
  this->height = h;
}
double Item :: getHeight(){
  return this->height;
}
void Item :: setShape(string s){
  this->shape = s;
}
string Item :: getShape(){
  return this->shape;
}
void Item :: setShade(string s){
  this->shade = s;
}
string Item :: getShade(){
  return this->shade;
}
void Item :: setStreak(string s){
  this->streak = s;
}
string Item :: getStreak(){
  return this->streak;
}
void Item :: setShine(string s){
  this->shine = s;
}
string Item :: getShine(){
  return this->shine;
}
void Item :: setOrigin(string o){
  this->origin = o;
}
string Item :: getOrigin(){
  return this->origin;
}