#ifndef ITEM
#define ITEM

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//PARENT OBJECT -- ITEM
class Item {
  public:

    Item();//should contstruct each trait to be empty; traits will be determined by the child obj via polymorphism

    virtual void setTraits(); //polymorph stuff
    virtual void printTraits();

    void setType(string);
    string getType();

    void setColor(string);
    string getColor();

    void setLength(double);
    double getLength();

    void setHeight(double);
    double getHeight();

    void setShape(string);
    string getShape();

    void setShade(string);
    string getShade();

    void setStreak(string);
    string getStreak();

    void setShine(string);
    string getShine();

    void setOrigin(string);
    string getOrigin();

  protected:
    //Traits:
      string type;
      string color;
      double length;
      double height;
      string shape;
      string shade;
      string streak;
      string shine;
      string origin;
};
#endif