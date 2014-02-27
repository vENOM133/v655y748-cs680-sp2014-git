/*
Author:    Scott J Dick
Program:   project.cpp
Written using g++ in Linux

The values used in this program are random values, I do not actually know how to make these chemicals
BARF is a real chemical, it is B(Ar(CF3)2)4

creates Chemical class, takes input from user, informs how long it will take to make,
   advises how far in advance you need to order chemicals
*/

#include <iostream>
#include <math.h>
#include <string>
#include <cctype>

#include "project.h"

int main(void){
//chemical variables used to create classes
   int chem1DelDay1[] = {3,300,1,3,5,0,0};
   int chem1DelDay2[] = {5,200,1,2,3,4,5};
   int chem2DelDay1[] = {1,500,2,0,0,0,0};
   int chem2DelDay2[] = {2,300,2,4,0,0,0};
   int chem2DelDay3[] = {4,100,1,2,4,5,0};

   Chemical chem1("Sulfuric Acid", "Sulphur", .5, chem1DelDay1, "De-Ionized water", .6, chem1DelDay2, 800);
   Chemical chem2("BARF", "Boron" , .1, chem2DelDay1, "Argon", .3, chem2DelDay2, "Trifluoromethyl", .6, chem2DelDay3, 600);
//main variables
   int iOpt, iHowMuch, iWL = 1;//iOpt is chem creation variable, iWL is while loop control variable

   while(iWL == 1){//loops for multiple calculations
      cout << "Would you like to make <1> " << chem1.getChemName() << " or <2> " << chem2.getChemName() << "?\n";
      cout << "Please enter 1 or 2: ";
      cin >> iOpt;
      if(iOpt == 1){//if 1, calculates for chem1
         cout << "How much " << chem1.getChemName() << " would you like to make? ";
         cin >> iHowMuch;
         chem1.calChem(iHowMuch);
      }else if(iOpt == 2){//if 2, calculates for chem2
         cout << "How much " << chem2.getChemName() << " would you like to make? ";
         cin >> iHowMuch;
         chem2.calChem(iHowMuch);
      }else//if not 1 or 2, advises not a valid option
         cout << "That is not a valid option.";
      cout << "\nWould you like to make another chemical?\nPress 1 for yes or any other number for no: ";
      cin >> iWL;//loop control
   }
}