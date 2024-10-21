// *****************************************************************************
// Author:     Huan Nguyen
// Date:       05/24/2024
// Class:      CS 302
// Project:    Program Assignment #3
// File Name:  menu.cpp
// Purpose:    This file contains the implementation details for the methods
//             defined in the menu class.
// *****************************************************************************

#include "menu.h"
#include "exceptions.h"

using namespace std;

//Constructor
Menu::Menu() : order_log(), report(), order_num(0)
{}


// *****************************************************************************
// Function to get the user's selected operation choice.
//
// param: none
//
// The function returns the user's selected operation choice.
// *****************************************************************************
int Menu::read_operation_choice(void) const
{
   int operation_choice {0};

   //Displays the available ice cream dessert types.
   cout << "\nAvailable Actions:"
        << "\n1. Place an order"
        << "\n2. Look up a previous order"
        << "\n3. View all orders"
        << "\n4. View end-of-month report"
        << "\n5. Clear order log"
        << "\n6. Quit"     
        << endl; 

   cout << "\nWhat would you like to do? (Enter 1-6): ";
   cin >> operation_choice;

   //Clears the input stream if a non-int type value was entered.
   while (cin.fail())
   {
       //Clears the error state.
       cin.clear();

       //Clears the invalid input.
       cin.ignore(numeric_limits<streamsize>::max(), '\n');

       cerr << "\nInvalid input type. Please enter an integer: ";
       cin >> operation_choice;
   }
    
   return operation_choice;

}

// *****************************************************************************
// Function to manage the ice cream shop operations.
//
// param: none
//
// The function returns the user's operation choice.
// *****************************************************************************
int Menu::manage_ice_cream_shop(void)
{
   //Reads in the user's operation choice.
   int operation_choice {read_operation_choice()};
   int search_result {0};
   int order_id {0};

   //Switch block to coordinate operations on the order log.
   switch (operation_choice)
   {
       //Adds a new ice cream dessert order to the order log.
       case 1:
           if (record_order() == 2)
               cout << "\nThe order has been placed." << endl;

           break;

       //Searches for a particular ice creamd dessert order
       //in the order log.
       case 2:
           cout << "\nEnter an order number to search up: ";
           cin >> order_id;

           search_result = order_log.find_order(order_id);

           if (search_result == -1)
               cerr << "\nThe order log is empty." << endl;
   
           else if (search_result == 0)
               cerr << "\nThe order could not be found." << endl;

           break;

       //Displays all ice cream dessert orders in the order log.
       case 3:
           if (!order_log.display_all()) 
               cerr << "\nThe order log is already empty." << endl;

           break;

       //Displays the end of the month report and clears the order
       //log for the following month.
       case 4:

           if (!order_log.assess_total_sales(report)) 
               cerr << "\nZero sales were made this month :(" << endl;

           else
           {
               report.display_statistics();
               report.reset();
               order_log.remove_all();
               order_num = 0;

               cout << "\nThe order log has now been cleared for "
                    << "\nthe next month." << endl;
           }

           break;

      
        
       case 5:
           if (!order_log.remove_all())
               cerr << "\nThe order log is already empty." << endl;

           else
           {
               cout << "\nThe order log has been cleared." << endl;
               report.reset();
               order_num = 0;
           }
           
  
           break;

       //Quit
       case 6:
           break;

       default:
           cerr << "\nInvalid operation choice selected. Please try again."
                << endl;

           //Clears the input stream if a non-int type value was entered.
           if (cin.fail())
           {
               //Clears the error state.
               cin.clear();

               //Clears the invalid input.
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }

           break;
   }

   return operation_choice; 
}



// *****************************************************************************
// Function to record the user's ice cream dessert order into the order log.
//
// param: none
//
// The function returns 0 if the user selects an invalid ice cream dessert type.
// Otherwise, the function returns 1.
// *****************************************************************************
int Menu::record_order(void) 
{
   int dessert_choice {0};   //Variable to hold the user's dessert type choice.
   bool valid_dessert_type {true};
   Dessert * dessert_ptr {nullptr};
   int result {0};
 
   //Displays the available ice cream dessert types.
   cout << "\nAvailable Ice Cream Dessert Types:"
            << "\n1. Ice Cream Cone"
            << "\n2. Ice Cream Cake"
            << "\n3. Ice Cream Sandwich"
            << endl;

   cout << "\nChoose a dessert type: ";
   cin >> dessert_choice;

   switch (dessert_choice)
   {
       case 1:
           {
               cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~"
                    << "Ice Cream Cone"
                    << "~~~~~~~~~~~~~~~~~~~~~~~~~"
                    << endl;

               //Assigns dessert_ptr to point to an object of type 
               //IceCreamCone.
               dessert_ptr = new IceCreamCone;
               dessert_ptr->display_dessert_info();

               while (!dessert_ptr->choose_flavor());

               //Downcasts dessert_ptr, which is of type Dessert, to a pointer 
               //of type IceCreamCone.
               IceCreamCone * cone_ptr = dynamic_cast<IceCreamCone *>(dessert_ptr);  

               if (cone_ptr)
               {
                   //Gets the user's desired cone type and number of scoops.
                   while (!cone_ptr->read_cone_type());
                   while (!cone_ptr->read_num_scoops());
               }
           }
 
           break;
              
       case 2:
           {
               cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~"
                    << "Ice Cream Cake"
                    << "~~~~~~~~~~~~~~~~~~~~~~~~~"
                    << endl;

               //Assigns dessert_ptr to point to an object of type 
               //IceCreamCake.
               dessert_ptr = new IceCreamCake;
               dessert_ptr->display_dessert_info();

               while(!dessert_ptr->choose_flavor());

               //Downcasts dessert_ptr, which is of type Dessert, to a pointer 
               //of type IceCreanCake.
               IceCreamCake * cake_ptr = dynamic_cast<IceCreamCake *>(dessert_ptr);
  
               if (cake_ptr)
               {
                   //Gets the user's desired cake size and design type.
                   while (!cake_ptr->read_cake_size());
                   while (!cake_ptr->read_design_type());
               }
           }

           break;

       case 3:
           {
               cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~"
                    << "Ice Cream Sandwich"
                    << "~~~~~~~~~~~~~~~~~~~~~~~~~"
                    << endl;

               //Assigns dessert_ptr to point to an object of type 
               //IceCreamSandwich.
               dessert_ptr = new IceCreamSandwich;
               dessert_ptr->display_dessert_info();

               while (!dessert_ptr->choose_flavor());

               //Downcasts dessert_ptr, which is of type Dessert, to a pointer 
               //of type IceCreanCake.
               IceCreamSandwich * sandwich_ptr = dynamic_cast<IceCreamSandwich *>(dessert_ptr);

               if (sandwich_ptr)
               {
                   //Gets the user's desired cookie type and filling ratio
                   //for the ice cream sandwich order.
                   while (!sandwich_ptr->read_cookie_type());
                   while (!sandwich_ptr->read_filling_ratio());
               }
           }

           break;

       default:
           valid_dessert_type = false;

           cerr << "\nInvalid flavor selected. Please try again" << endl;  

           //Clears the input stream if a non-int type value was entered.
           if (cin.fail())
           {
               //Clears the error state.
               cin.clear();

               //Clears the invalid input.
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }

           break;
   }

   //Returns 0 to the calling routine iff the user selected an invalid dessert type...
   if (!valid_dessert_type)
       return 0;

   //Attemps to place the order.
   try
   {
       result = dessert_ptr->place_order(order_num + 1);

       if (result == 0)
       {
           delete dessert_ptr;
           cout << "\nThe order has been discarded." << endl;
       }
            
       //If the user chooses to confirm the order... 
       else if (result == 1)
       {
           ++order_num;

           //Creates a unique pointer.
           unique_ptr<Dessert> new_order;

           //Assigns new_order to point to the same Dessert object as dessert_ptr.
           new_order.reset(dessert_ptr);   

           //Adds the order to the order log.
           int level = order_log.insert(new_order);

           cout << "\nThe data item was added at level #" << level << endl;
       }
   }

   catch (MISSING_INFO)
   {
       delete dessert_ptr;
       cerr << "\nThe order cannot be placed due to missing information." << endl;
   }

   return result;
}
