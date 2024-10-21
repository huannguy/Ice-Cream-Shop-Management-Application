// *****************************************************************************
// Author:     Huan Nguyen
// Date:       05/24/2024
// Class:      CS 302
// Project:    Program Assignment #3
// File Name:  menu.h
// Purpose:    This file contains the interface for the Menu class.
// *****************************************************************************

#include "tree.h"

//Interface for the Menu class that will manage operations for an ice cream
//shop.
class Menu
{
   public:
         
       Menu();    //Constructor
 
       int read_operation_choice(void) const;
       int manage_ice_cream_shop(void);
       int record_order(void); 

   private:
       Tree order_log;
       SalesStatistics report;
       int order_num;
};

