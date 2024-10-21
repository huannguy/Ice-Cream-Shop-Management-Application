// *****************************************************************************
// Author:     Huan Nguyen
// Date:       05/15/2024
// Class:      CS 302
// Project:    Program Assignment #3
// File Name:  main.cpp
// Purpose:    This file contains the application that will manage ice cream
//             sales.
// *****************************************************************************

#include "menu.h"

using namespace std;

int main()
{
   cout << fixed << setprecision(2) << showpoint;

   Menu ice_cream_store;

   cout << "\nWelcome to the Ice Cream Sales Manager!" << endl;

   while (ice_cream_store.manage_ice_cream_shop() != 6);

   cout << "\nThank you for using the Ice Cream Sales Manager." 
        << "\nWe hope you found the application serviceable! " << endl;

   return 0;
}

