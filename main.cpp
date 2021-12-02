//Beach Hunt - November 2021
//Group 6 - Douglas Maxwell, Luke McElligott, Oleksii Dukhovenko
//This program allows the user to VIEW, ADD, and SEARCH for items that they have collected on the beautiful beaches of lake Erie
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

#ifndef ITEM
#include "Item.h"
#endif
#ifndef GLASS
#include "Glass.h"
#endif
#ifndef PLANT
#include "Plant.h"
#endif
#ifndef SHELL
#include "Shell.h"
#endif
#ifndef WOOD
#include "Wood.h"
#endif

//function to initialze items from file
void initializeItems(vector <Item*> &ItemList, string);
//Function to print item based on the item type that is passed
void viewItem(vector <Item*> ItemList, string);
//function to split string and return the parsed string at the position that is passed
string splitString(string,int);
//function to search Item List 
void search(char UserIn_Search,vector <Item*> ItemList, bool &searchFlag);
//function check if string is a number
bool is_number(const std::string& s);
//function quickhand for print long line of *
void printLine();

//constant strings for enter orders when adding new items
const string EnterOrderGlass = "shine,color,origin,length",EnterOrderPlant = "color,shape,length",EnterOrderShell = "color,shape,length,height",EnterOrderWood = "color,streak,shade,length";

int main() {

  vector <Item*> ItemList; //Vector of pointers; Allows for polymorphism
  Glass* tempG;
  Plant* tempP;
  Shell* tempS;
  Wood* tempW;

  string file = "InitialItems.txt";
  initializeItems(ItemList,file);

  //***************************************
  //*MEGA DO-WHILE LOOP FOR USER INTERFACE*
  //***************************************
  char UserIn_MainMenu;
  do{
    //OPTIONS: 1.VIEW ITEMS 2.ADD ITEMS 3.SEARCH ITEMS 4.QUIT
    printLine();
    cout<<"**** MAIN MENU ****"<<endl;
    cout << "Please choose an option: " << endl <<endl;
    cout << "1. VIEW ITEMS" << endl;
    cout << "2. ADD ITEMS" << endl;
    cout << "3. SEARCH ITEMS" << endl;
    cout << "4. QUIT" << endl;
    cout<< ">> ";cin >> UserIn_MainMenu;
    printLine();

    //RUN PROCCESS FOR EACH OPTION

    //VIEW ITEMS
    if (UserIn_MainMenu == '1'){
      char UserIn_View, MM_option;
      do{
        //OPTIONS: 1.VIEW ALL 2. VIEW GLASS 3. VIEW PLANT 4. VIEW SHELL 5. VIEW WOOD
        cout << "Please choose a viewing option: " << endl;
        cout << "1. VIEW ALL ITEMS" << endl;
        cout << "2. VIEW GLASS ITEMS" << endl;
        cout << "3. VIEW PLANT ITEMS" << endl;
        cout << "4. VIEW SHELL ITEMS" << endl;
        cout << "5. VIEW WOOD ITEMS" << endl;
        cout<< ">> ";cin >> UserIn_View;
        printLine();
        //VIEW ALL
        if (UserIn_View == '1'){
          viewItem(ItemList,"GLASS");
          viewItem(ItemList,"PLANT");
          viewItem(ItemList,"SHELL");
          viewItem(ItemList,"WOOD");
        }
        //VIEW GLASS
        else if (UserIn_View == '2'){
          viewItem(ItemList,"GLASS");
        }
        //VIEW PLANT
        else if (UserIn_View == '3'){
          viewItem(ItemList,"PLANT");
        }
        //VIEW SHELL
        else if (UserIn_View == '4'){
          viewItem(ItemList,"SHELL");
        }
        //VIEW WOOD
        else if (UserIn_View == '5'){
          viewItem(ItemList,"WOOD");
        }
        cout<<endl<<"Return to Main Menu? (y/n): "; cin>>MM_option;
      }while(MM_option != 'y');
    }
    //ADD ITEMS
    else if(UserIn_MainMenu == '2'){
      bool mainflag=false;
      do{
        char UserIn_AddType;
        string UserIn_AddString, EnterOrder, delim=",";
        bool flag=false;
        do{
          cout<<"Choose your Item Type to add (1-5): " << endl;
          cout << "1. GLASS" << endl;
          cout << "2. PLANT" << endl;
          cout << "3. SHELL" << endl;
          cout << "4. WOOD" << endl;
          cout << "5. RETURN TO MAIN MENU" << endl;
          cout<< ">> ";cin>>UserIn_AddType;
          if (UserIn_AddType=='1'){
            flag=true;
            EnterOrder=EnterOrderGlass;
          }
          else if(UserIn_AddType=='2'){
            flag=true;
            EnterOrder=EnterOrderPlant;
          }
          else if(UserIn_AddType=='3'){
            flag=true;
            EnterOrder=EnterOrderShell;
          }
          else if(UserIn_AddType=='4'){
            flag=true;
            EnterOrder=EnterOrderWood;
          }
          else if(UserIn_AddType=='5'){
            mainflag=true;
            flag=true;
          }
          else
            cout<<"Please enter a valid number"<<endl;
        } while (!flag);
        if (mainflag)
          break;
        printLine();
        cout<<"Enter the attributes as follows: "<<endl<<"\t"<<EnterOrder<<endl;
        cout<< ">> ";cin>>UserIn_AddString;
        //use splitString function to read string individualy and separate into values
        string val1=splitString(UserIn_AddString,0);
        string val2=splitString(UserIn_AddString,1);
        string val3=splitString(UserIn_AddString,2);
        string val4=splitString(UserIn_AddString,3);
        if (UserIn_AddType=='1'){
          while (!is_number(val4)){
            cout<<"Invalid legnth. Please enter a new length:"<<endl;
            cout<<">> ";cin>>val4;
          }
          tempG = new Glass;
          tempG->setTraits(val1,val2,val3,stod(val4)); //convert last param to double
          ItemList.push_back(tempG);
          cout<<endl<<"\"GLASS\" item successfully added to database."<<endl<<endl;
        }
        else if(UserIn_AddType=='2'){
          while (!is_number(val3)){
            cout<<"Invalid legnth. Please enter a new length:"<<endl;
            cout<<">> ";cin>>val3;
          }
          tempP = new Plant;
          tempP->setTraits(val1,val2,stod(val3));
          ItemList.push_back(tempP);
          cout<<endl<<"\"PLANT\" item successfully added to database."<<endl<<endl;
        }
        else if(UserIn_AddType=='3'){
          while (!is_number(val3)){
          cout<<"Invalid legnth. Please enter a new length:"<<endl;
          cout<<">> ";cin>>val3;
          }
          while (!is_number(val4)){
          cout<<"Invalid height. Please enter a new height:"<<endl;
          cout<<">> ";cin>>val4;
          }
          tempS = new Shell;
          tempS->setTraits(val1,val2,stod(val3),stod(val4));
          ItemList.push_back(tempS);
          cout<<endl<<"\"SHELL\" item successfully added to database."<<endl<<endl;
        }
        else if(UserIn_AddType=='4'){
          while (!is_number(val4)){
          cout<<"Invalid legnth. Please enter a new length:"<<endl;
          cout<<">> ";cin>>val4;
          }
          tempW = new Wood;
          tempW->setTraits(val1,val2,val3,stod(val4));
          ItemList.push_back(tempW);
          cout<<endl<<"\"WOOD\" item successfully added to database."<<endl<<endl;
        }
      }while (!mainflag);
    }
    //SEARCH ITEMS
    else if(UserIn_MainMenu == '3'){
      bool searchFlag = false;
      char UserIn_Search;
      string searchColor; //used when searching for color
      double minLength; //used when searching for length
      double maxLength; //used when searching for length
      do {
        cout << "Please choose an attribute to use in your search:" << endl;
        cout << "1. COLOR" << endl;
        cout << "2. LENGTH" << endl;
        cout << "3. COLOR & LENGTH" << endl;
        cout << "4. RETURN TO MAIN MENU" << endl;
        cout<< ">> ";cin >> UserIn_Search;

        search(UserIn_Search, ItemList, searchFlag); //call search function until flag updates

      } while (!searchFlag);
    }

  } while (UserIn_MainMenu != '4');
  //**************
  //END MEGA LOOP*
  //**************
  cout<<"Goodbye...";
  return 0;
}

void initializeItems(vector <Item*> &ItemList, string file){
  Glass* tempG;
  Plant* tempP;
  Shell* tempS;
  Wood* tempW;
  ifstream InitialFile;
  string v1,v2,v3,v4;
  InitialFile.open(file);
  if (InitialFile.is_open()) {
    int i=0;
    for(i=1;i<6;i++){
      tempS = new Shell;
      InitialFile >> v1 >> v2 >> v3 >> v4;
      tempS->setTraits(v1,v2,stod(v3),stod(v4));
      ItemList.push_back(tempS);
    }
    for(i=6;i<9;i++){
      tempW = new Wood;
      InitialFile >> v1 >> v2 >> v3 >> v4;
      tempW->setTraits(v1,v2,v3,stod(v4));
      ItemList.push_back(tempW);
    }
    for(i=9;i<11;i++){
      tempG = new Glass;
      InitialFile >> v1 >> v2 >> v3 >> v4;
      tempG->setTraits(v1,v2,v3,stod(v4));
      ItemList.push_back(tempG);
    }
    for(i=11;i<17;i++){
      tempP = new Plant;
      InitialFile >> v1 >> v2 >> v3;
      tempP->setTraits(v1,v2,stod(v3));
      ItemList.push_back(tempP);
    }
  }
  InitialFile.close();
}
//Function to view items within type using ItemList vector and given item name
void viewItem(vector <Item*> ItemList, string item){
  cout<<item<<" ITEMS: "<<endl;
  int count=1;
  for (int i=0;i<ItemList.size();i++){
    if (ItemList.at(i)->getType() == item){
      cout<<"\t"<<count<<". ";
      ItemList.at(i)->printTraits();
      cout<<endl;
      count++;
    }
  }
}
string splitString(string userin,int i){
  string delim=",",s;
  s.append(userin);
  s.append(",");
  vector <string> ret{};
  size_t pos = 0;
  while ((pos = s.find(delim)) != string::npos) {
    ret.push_back(s.substr(0,pos));
    s.erase(0, pos + delim.length());
  }
  return ret[i];
}
void search(char UserIn_Search,vector <Item*> ItemList, bool &searchFlag){
  string searchColor;
  double minLength,maxLength;
  if (UserIn_Search=='1'){
    cout << endl << "Please enter the color you would like to search for:" << endl;
    cout<< ">> ";cin >> searchColor;
    //maybe do this or make a function that gets called
    cout<<endl<<"Items Found for \""<<searchColor<<"\": "<<endl;
    int cnt=1;
    for (int i = 0; i < ItemList.size(); i++){
      if (ItemList.at(i)->getColor()==searchColor){
        cout<<"\t"<<cnt<<". "<<ItemList.at(i)->getType()<<" ITEM: ";
        ItemList.at(i)->printTraits();
        cnt++;
      }
      //use the input to search the vector for the color
    }
    if (cnt==1)
      cout<<"\t NONE"<<endl;
  }
  else if (UserIn_Search == '2'){
    cout <<endl<< "Please enter the minimum length:" << endl;
    cout<< ">> ";cin >> minLength;
    cout << "Please enter the maximum length:" << endl;
    cout<< ">> ";cin >> maxLength;

    //maybe do this or make a function that gets called
    cout<<endl<<"Items Found for \""<<minLength<<" inches to "<<maxLength<<" inches\": "<<endl;
    int cnt=1;
    for (int i=0;i<ItemList.size();i++){
      if (ItemList.at(i)->getLength()>=minLength && ItemList.at(i)->getLength()<=maxLength){
        cout<<"\t"<<cnt<<". "<<ItemList.at(i)->getType()<<" ITEM: ";
        ItemList.at(i)->printTraits();
        cnt++;
      }
    }
    if (cnt==1)
      cout<<"\t NONE"<<endl;
  }
  else if (UserIn_Search == '3'){
    cout <<endl<< "Please enter the color you would like to search for:" << endl;
    cout<< ">> ";cin >> searchColor;
    cout << "Please enter the minimum length:" << endl;
    cout<< ">> ";cin >> minLength;
    cout << "Please enter the maximum length:" << endl;
    cout<< ">> ";cin >> maxLength;

    cout<<endl<<"Items Found for \""<<searchColor<<", "<<minLength<<" inches to "<<maxLength<<" inches\": "<<endl;
    int cnt=1;
    for (int i=0;i<ItemList.size();i++){
      if (ItemList.at(i)->getLength()>=minLength && ItemList.at(i)->getLength()<=maxLength && ItemList.at(i)->getColor()==searchColor){
        cout<<"\t"<<cnt<<". "<<ItemList.at(i)->getType()<<" ITEM: ";
        ItemList.at(i)->printTraits();
        cnt++;
      }
    }
    if (cnt==1)
      cout<<"\t NONE"<<endl;
  }
  else if(UserIn_Search=='4')
    searchFlag=true;
  else
    cout << "Please enter a valid number" << endl;
  cout<<endl;
}
bool is_number(const std::string& s){
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0'; //&& val != HUGE_VAL;
}
void printLine(){
  cout<<endl<<"************************************************"<<endl<<endl;
}