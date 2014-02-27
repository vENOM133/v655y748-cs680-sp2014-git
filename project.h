#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <math.h>
#include <string>
#include <cctype>

using namespace std;

class Chemical
{
   string sChemName, sInChemName1, sInChemName2, sInChemName3;//contains chemical name and input chemical names
   float fInChemRatio1, fInChemRatio2, fInChemRatio3;//stores ratio for input chemicals(how much needed per gallon of output chemical)
   int iDaysDelivered1[7], iDaysDelivered2[7], iDaysDelivered3[7], iMadePerDay, iNumOfChems;
/* iDaysDelivered 1/2/3: stores delivery days for input chemicals as follows:
	how many deliveries per week(1-5), gallons per delivery, numerical values for each delivery day(1=Monday, 2=Tuesday, etc.)
	unused spots are blank
   iMadePerDay: how much of chemical can be made per day in gallons
   iNumOfChems: how many input chemicals needed, 2 or 3 for current build
*/

public:
   Chemical(string chemName, string inChem1, float inRat1, int daysDel1[], string inChem2, float inRat2, int daysDel2[], int madePerDay);//constructor for 2 input chemicals
   Chemical(string chemName, string inChem1, float inRat1, int daysDel1[], string inChem2, float inRat2, int daysDel2[], string inChem3, float inRat3, int daysDel3[], int madePerDay);//constructor for 3 input chemicals

   string getChemName(void){//returns the name of the chemical being produced
      return sChemName;
   }

   void calChem(int howMuch){//supply with amount wanted, calculates days to make and how far in advance to order chemicals
      int iHowManyDays, iChem1Needed, iChem2Needed, iChem3Needed;//days to make, amount of input chems needed
      int iChem1Days, iChem1Weeks = 0;//days/weeks to get needed input chems
      int iChem2Days, iChem2Weeks = 0;
      int iChem3Days, iChem3Weeks = 0;
      int iHowMuch = howMuch;

      iHowManyDays = ceil((float)iHowMuch / (float)iMadePerDay);//calculates days to make, rounds up
      iChem1Needed = ceil((float)iHowMuch * fInChemRatio1);//calculates chemicals needed, rounds up
      iChem2Needed = ceil((float)iHowMuch * fInChemRatio2);
      cout << string(100, '\n');//clears screen
      cout << "\nIt will take " << iHowManyDays << " days to make " << iHowMuch << " gallons/pounds of " << sChemName << ".\n";
      iChem1Days = ceil((float)iChem1Needed / (float)iDaysDelivered1[1]);//calculates deliveries needed
      while(iChem1Days >= iDaysDelivered1[0]){//figures weeks needed
         iChem1Weeks++;
         iChem1Days -= iDaysDelivered1[0];
      }
      iChem1Days = ceil((float)iChem1Days * (5 / (float)iDaysDelivered1[0]));//converts remaining deliveries needed to days
      iChem2Days = ceil((float)iChem2Needed / (float)iDaysDelivered2[1]);
      while(iChem2Days >= iDaysDelivered2[0]){
         iChem2Weeks++;
         iChem2Days -= iDaysDelivered2[0];
      }
      iChem2Days = ceil((float)iChem2Days * (5 / (float)iDaysDelivered2[0]));
      cout << "You will need to order " << iChem1Needed << " gallons/pounds of " << sInChemName1 << "\n\t" << iChem1Weeks << " weeks and " << iChem1Days << " days in advance.\n";
      cout << "You will need to order " << iChem2Needed << " gallons/pounds of " << sInChemName2 << "\n\t" << iChem2Weeks << " weeks and " << iChem2Days << " days in advance.\n";
      if(iNumOfChems == 3){
         iChem3Needed = ceil((float)iHowMuch * fInChemRatio3);
         iChem3Days = ceil((float)iChem3Needed / (float)iDaysDelivered3[1]);
         while(iChem3Days >= iDaysDelivered3[0]){
            iChem3Weeks++;
            iChem3Days -= iDaysDelivered3[0];
         }
         iChem3Days = ceil((float)iChem3Days * (5 / (float)iDaysDelivered3[0]));
         cout << "You will need to order " << iChem3Needed << " gallons/pounds of " << sInChemName3 << "\n\t" << iChem3Weeks << " weeks and " << iChem3Days << " days in advance.\n";
      }
   }
};

Chemical::Chemical(string chemName, string inChem1, float inRat1, int daysDel1[], string inChem2, float inRat2, int daysDel2[], int madePerDay){//constructor for 2 input chemicals
   sChemName = chemName;
   sInChemName1 = inChem1;
   sInChemName2 = inChem2;
   sInChemName3 = "empty";
   fInChemRatio1 = inRat1;
   fInChemRatio2 = inRat2;
   fInChemRatio3 = 0;
   for(int i = 0; i < 7; i++){//stores input array values into class array
      iDaysDelivered1[i] = daysDel1[i];
   }
   for(int i = 0; i < 7; i++){//stores input array values into class array
      iDaysDelivered2[i] = daysDel2[i];
   }
   for(int i = 0; i < 7; i++){//stores input array values into class array
      iDaysDelivered3[i] = 0;
   }
   iMadePerDay = madePerDay;
   iNumOfChems = 2;
}

Chemical::Chemical(string chemName, string inChem1, float inRat1, int daysDel1[], string inChem2, float inRat2, int daysDel2[], string inChem3, float inRat3, int daysDel3[], int madePerDay){//constructor for 3 input chemicals
   sChemName = chemName;
   sInChemName1 = inChem1;
   sInChemName2 = inChem2;
   sInChemName3 = inChem3;
   fInChemRatio1 = inRat1;
   fInChemRatio2 = inRat2;
   fInChemRatio3 = inRat3;
   for(int i = 0; i < 7; i++){//stores input array values into class array
      iDaysDelivered1[i] = daysDel1[i];
   }
   for(int i = 0; i < 7; i++){//stores input array values into class array
      iDaysDelivered2[i] = daysDel2[i];
   }
   for(int i = 0; i < 7; i++){//stores input array values into class array
      iDaysDelivered3[i] = daysDel3[i];
   }
   iMadePerDay = madePerDay;
   iNumOfChems = 3;
}

#endif