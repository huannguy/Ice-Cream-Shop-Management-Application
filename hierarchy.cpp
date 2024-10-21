// *****************************************************************************
// Author:     Huan Nguyen
// Date:       05/1/2024
// Class:      CS 302
// Project:    Program Assignment #2
// File Name:  hierarchy.cpp
// Purpose:    This file contains the implementation details for the methods
//             declared in the Dessert, IceCreamCone, IceCreamCake, 
//             IceCreamSandwich, and SalesStatistics classes.
// *****************************************************************************

#include "hierarchy.h"
#include "exceptions.h"

using namespace std;

// *****************************************************************************
// Function to validate the user's answer to a yes/no question.
//
// yes_no_answer is passed the address of the variable containing the user's
// answer to a yes/no question.
//
// return: none
// *****************************************************************************
void validate_yes_no_answer(char & yes_no_answer)
{
    yes_no_answer = tolower(yes_no_answer);

    //Repeatedly prompts the user to enter 'y' for yes or
    //'n' for no until a valid answer is entered.
    while (yes_no_answer != 'y' && yes_no_answer != 'n')
    {
        cout << "\nInvalid answer entered.";
	    cout << "\nPlease enter 'y' for yes or 'n' for no: ";
	    cin >> yes_no_answer;
        cin.ignore(100, '\n');

	    yes_no_answer = tolower(yes_no_answer);
    }
}


// IMPLEMENTATION DETAILS FOR THE DESSERT CLASS

//Default Constructor
Dessert::Dessert() : flavor(), dessert_type(), order_id(0), price(0.0)
{}


//Destructor
Dessert::~Dessert()
{
   order_id = 0;
   price = 0.0;
}


// ****************************************************************************
// Function to overload the < operator for comparison between two Dessert
// objects.
//
// op1 is passed a reference to a Dessert object.
// op2 is passed a reference to a Dessert object.
//
// The function returns false if op1's order number is greater than or equal to
// op2's order number. Otherwise, the function returns true.
// ****************************************************************************
bool operator<(const Dessert & op1, const Dessert & op2)
{
   return op1.order_id < op2.order_id;
}


// ****************************************************************************
// Function to overload the < operator for comparison between a specified 
// order number and a Dessert object.
//
// order_number is passed a copy of the variable containing the specified order
// number.
// order is passed a reference to a Dessert object.
//
// The function returns false if the order number is greater than or equal to
// the Dessert object's order number. Otherwise, the function returns true.
// ****************************************************************************
bool operator<(int order_num, const Dessert & order)
{
   return order_num < order.order_id;
}


// ****************************************************************************
// Function to overload the == operator for comparison between a Dessert 
// object and a specified order number.
//
// order is passed a reference to a Dessert object.
// order_number is passed a copy of the variable containing the specified
// order number.
//
// The function returns false if the Dessert object's order number is not
// equal to the specified order number. Otherwise, the function returns true.
// ****************************************************************************
bool operator==(const Dessert & order, int order_number)
{
   return order.order_id == order_number; 
}


// ****************************************************************************
// Function to overload the == operator for comparison between a specified
// order number and an Dessert object.
//
// order is passed a reference to a Dessert object.
// order_number is passed a copy of the variable containign the specified
// order number.
//
// The function returns false if the Dessert object's order number is not
// equal to the specified order number. Otherwise, the function returns true.
// ****************************************************************************
bool operator==(int order_number, const Dessert & order)
{
   return order_number == order.order_id; 
}


// *****************************************************************************
// Function to select an ice cream flavor.
//
// param: none
//
// The function returns 0 if the user selects an invalid ice cream flavor.
// Otherwise, the function returns 1 if the user selects a valid ice cream
// flavor.
// *****************************************************************************
int Dessert::choose_flavor(void)
{
   //Variable to hold the user's selected ice cream flavor.
   int flavor_choice {0};

   //Displays the available ice cream flavors.
   cout << "\nAvailable Flavors: "
        << "\n1. Chocolate"
        << "\n2. Vanilla bean"
        << "\n3. Strawberry"
        << "\n4. Peaches and Cream"
        << "\n5. Cookies and Cream"
        << endl;

   cout << "\nPlease select an ice cream flavor (enter 1-5): ";
   cin >> flavor_choice;

   //Saves the user's selected ice cream flavor.
   switch (flavor_choice)
   {
       case 1:
           flavor = "chocolate"; 
           break;

       case 2:
           flavor = "vanilla bean"; 
           break;

       case 3:
           flavor = "strawberry"; 
           break;

       case 4:
           flavor = "peaches and cream"; 
           break;

       case 5:
           flavor = "cookies and cream";
           break;

       default:
           //Clears the input stream if a non-int type value was entered.
           if (cin.fail())
           {
               //Clears the error state.
               cin.clear();

               //Clears the invalid input.
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }

           //Displays an error message if the user enters something that is
           //1-5.
           cerr << "\nInvalid flavor selected. Please try again" << endl;

           break; 
   }
 
   if (flavor.empty())
       return 0;

   return 1;
}


// *****************************************************************************
// Function to set the total price of the order.
//
// dessert is passed a copy of the variable containing the ice cream dessert
// type.
//
// order_num is passed a copy of the variable containing the assigned number
// for the current order.
//
// total_price is passed a copy of the variable containing the final price
// of the order.
//
// The function returns 0 if total_price is a negative number. Otherwise, the 
// function returns 1 if the user selects a valid ice cream flavor.
// *****************************************************************************
int Dessert::checkout(const string & dessert, int order_num, float total_price)
{
   //Returns 0 to the calling routine if there is missing information.
   if (dessert.empty() || !order_num || total_price < 0)
       return 0;

   dessert_type = dessert; 
   order_id = order_num;
   price = total_price;

   return 1;
}


// *****************************************************************************
// Function to retrieve the flavor of the current Dessert object.
//
// param: none
//
// The function returns false if the flavor is blank. Otherwise, the function 
// returns true.
// *****************************************************************************
bool Dessert::retrieve_flavor(string & to_retrieve) const
{
    //Returns false to the calling routine if the flavor is blank.
   if (flavor.empty())
       return false;

   to_retrieve = flavor;

   return true;
}


// *****************************************************************************
// Function to display the selected ice cream flavor.
//
// param: none
//
// The function returns 1.
// *****************************************************************************
int Dessert::display_flavor(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

    //Returns 0 to the calling routine if the flavor was not specified.
    if (flavor.empty())
        throw missing_info;

     cout << "\nFlavor: " << flavor << endl;

     return 1;
}


// ****************************************************************************
// Function to display the information contained in the current Dessert object.
//
// param: none
//
// return: none
// ****************************************************************************
void Dessert::display_order_info(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   //Throws a missing_info exception if the current Dessert object contains
   //missing information.
   if (flavor.empty() ||dessert_type.empty() || !order_id || !price)
       throw missing_info;

   cout << "\n        Order Number #" << order_id
        << "\n---------------------------------"
        << "\nFlavor: " << flavor
        << "\nDessert_type: " << dessert_type
        << "\nPrice: $" << price;

   return;
}



float Dessert::calculate_price(void) const
{
   return 1;
}

int Dessert::place_order(int order_num)
{
   return 1;
}

int Dessert::view_order(void) const
{
   return 1;
}


// IMPLEMENTATION DETAILS FOR THE ICE CREAM CONE CLASS

//Default constructor
IceCreamCone::IceCreamCone() : cone_type(), num_scoops(0)
{}

//Destructor
IceCreamCone::~IceCreamCone()
{
   num_scoops = 0;
}


// *****************************************************************************
// Function to display information about the ice cream cone dessert.
//
// param: none
//
// return: none
// *****************************************************************************
void IceCreamCone::display_dessert_info(void) const
{
   cout << "\nThere are two types of cones available sugar and waffle."
        << "\nGuests may request up to two extra scoops per cone, for"
        << "\nan additional 15 cents per scoop. Flavors may not be mixed."
        << endl;
}


// ****************************************************************************
// Function to display the information contained in the current IceCreamCone 
// object.
// 
// param: none
//
// return: none
// ****************************************************************************
void IceCreamCone::display_order_info(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   Dessert::display_order_info();

   //Throws a missing_info exception if the current IceCreamCone object 
   //contains missing information.
   if (cone_type.empty() || !num_scoops)
       throw missing_info;

   cout << "\nCone type: " << cone_type
        << "\nNumber of scoops: " << num_scoops
        << endl;
          
   return;
}


// *****************************************************************************
// Function to calculate the price of the user's ice cream cone order
//
// param: none
//
// The function returns the calculated price of the ice cream cone order.
// *****************************************************************************
float IceCreamCone::calculate_price(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   //Returns 0 to the calling routine if either the ice cream cone type or
   //number of scoops were not specified.
   if (cone_type.empty() || !num_scoops)
       throw missing_info;

   //Variable to hold the price of the selected ice cream cone type.
   float cone_price {0.0};
   float total_price {0.0};

   if (cone_type == "sugar")
       cone_price = SUGAR_CONE_PRICE;

   else if (cone_type == "waffle")
       cone_price = WAFFLE_CONE_PRICE;

   total_price = (num_scoops - 1) * EXTRA_SCOOP_FEE + cone_price;

   return total_price;
}


// ****************************************************************************
// Function to display the user's ice cream cone order.
//
// param: none
//
// The function returns 0 if either the ice cream cone type or number of scoops
// were not specified. Otherwise, the function returns 1, indicating the 
// display was successful.
// ****************************************************************************
int IceCreamCone::view_order(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   //Throws a MISSING_INFO exception if either the cone type was not specified
   //or number of scoops is 0.
   if (cone_type.empty() || !num_scoops)
       throw missing_info;

   cout << "\n      Order Details      "
        << "\n-------------------------";

   display_flavor();
   cout << "Cone: " << cone_type 
        << "\nNumber of scoops: " << num_scoops;

   return 1;
}


// *****************************************************************************
// Function to place the user's ice cream cone order.
//
// order_num is passed a copy of the variable containing the assigned number
// for the current order.
//
// The function returns 0 if the user chooses to not confirm the order, or 1
// if the user chooses to confirm the order.
// *****************************************************************************
int IceCreamCone::place_order(int order_num) 
{ 
   view_order();

   float total_price {calculate_price()};
   char confirm_order {' '};

   //Displays the expected price of the ice cream cone.
   cout << "\nPrice: $" << total_price << endl;

   cout << "\nConfirm order? (y/n): ";
   cin >> confirm_order;
   cin.ignore(100, '\n');

   validate_yes_no_answer(confirm_order); 

   //Returns 1 to the calling routine if the user chooses to not confirm
   //their order at the moment.
   if (confirm_order == 'n')
       return 0;

   checkout("ice cream cone", order_num, total_price);

   return 1;
}


// *****************************************************************************
// Function to get the user's desired cone type.
//
// param: none
//
// The function returns 0 if the user selects an invalid cone type. Otherwise,
// the function returns 1 if the user selects a valid cone type.
// *****************************************************************************
int IceCreamCone::read_cone_type(void)
{
   int cone_choice {0};
 
   //Displays the available cone types and their prices.
   cout << "\n1. Sugar Cone: $" << SUGAR_CONE_PRICE
        << "\n2. Waffle Cone: $" << WAFFLE_CONE_PRICE
        << endl;

   cout << "\nPlease select a cone (Enter 1 or 2): ";
   cin >> cone_choice;

   //Saves the user's selected cone tyoe
   switch (cone_choice)
   {
       case 1:
           cone_type = "sugar";
           break;

       case 2:
           cone_type = "waffle";
           break;

       default:
           //Clears the input stream if a non-int type value was entered.
           if (cin.fail())
           {
               //Clears the error state.
               cin.clear();

               //Clears the invalid input.
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }

           //Displays an error message if the user enters something that is
           //not 1-2.
           cerr << "\nInvalid cone type selected. Please try again" << endl;

           break; 
   }

   if (cone_type.empty())
       return 0;

   return 1;
}


// *****************************************************************************
// Function to get the user's desired number of scoops.
//
// param: none
//
// The function returns 0 if the user enters a non-positive value or a value 
// greater than 3 for the number of scoops, or 1 if the user enters a valid value.
// *****************************************************************************
int IceCreamCone::read_num_scoops(void)
{
   cout << "\nHow many scoops would you like? (Enter 1-3): ";
   cin >> num_scoops;
 
   //While the input type read in is not an int...
   while (cin.fail())
   {
       //Clears the error state.
       cin.clear();

       //Clears the invalid input.
       cin.ignore(numeric_limits<streamsize>::max(), '\n');

       //Displays an error message if a non-int input type was read in.
       cout << "Invalid input type. Please enter an integer: ";
       cin >> num_scoops;
   } 

   cin.ignore(100, '\n'); 

   //If the user enters a value less than 1 or greater than 3...
   if (num_scoops < 1 || num_scoops > 3)
   {
       //Displays the following error message
       cerr << "\nInvalid number of scoops entered. Guests may only"
            << "\nrequest 1, 2, or 3 total scoops."
            << endl;

       //Resets num_scoops to its initial value.
       num_scoops = 0;

       //Returns 0 to the calling routine.
       return 0;
   }
      
   return 1;
}


// IMPLEMENTATION DETAILS FOR THE ICE CREAM CAKE CLASS

//Default constructor
IceCreamCake::IceCreamCake() : cake_size(), design_type()
{}

//Destructor
IceCreamCake::~IceCreamCake() 
{}


// ****************************************************************************
// Function to display the information in the current IceCreamCake object.
// 
// param: none
//
// return: none
// ****************************************************************************
void IceCreamCake::display_order_info(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   Dessert::display_order_info();

   //Throws a missing_info exception if the current IceCreamCone object 
   //contains missing information.
   if (cake_size.empty() || design_type.empty())
       throw missing_info;

   cout << "\nCake size: " << cake_size
        << "\nDesign type: " << design_type
        << endl;
          
   return;
}


// *****************************************************************************
// Function to display information about the ice cream cake dessert.
//
// param: none
//
// return: none
// *****************************************************************************
void IceCreamCake::display_dessert_info(void) const
{
   //Displays information about the ice cream cake dessert.
   cout << "\nGuests may pick from three types of cake sizes: small, medium,"
        << "\nand large and three types of cake designs: simple (default),"
        << "\nthemed, and elaborate."
        << endl;
}


// *****************************************************************************
// Function to calculate the price of the user's ice cream cake order.
//
// param: none
//
// The function returns the calculated price of the ice cream cake order.
// *****************************************************************************
float IceCreamCake::calculate_price(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   //Throws a MISSING_INFO exception if either the cake size or design
   //were not specified.
   if (cake_size.empty() || design_type.empty())
       throw missing_info;

   //Variable to hold the price of the selected cake size.
   float size_price {0.0};
   float design_price {0.0};
   float total_price {0.0};

   //Sets the base price of the cake based on the selected cake size.
   if (cake_size == "small")
       size_price = SMALL_CAKE_PRICE;

   else if (cake_size == "medium")
       size_price = MEDIUM_CAKE_PRICE;
  
   else if (cake_size == "large")
       size_price = LARGE_CAKE_PRICE;

   //Sets the design fee based on the selected design type.
   if (design_type == "themed")
       design_price = THEMED_CAKE_PRICE;

   else if (design_type == "elaborate")
       design_price = ELABORATE_CAKE_PRICE;

   total_price = size_price + design_price;

   return total_price;
}


// ****************************************************************************
// Function to display the user's ice cream cake order.
//
// param: none
//
// The function returns 1, indicating the display was successful.
// ****************************************************************************
int IceCreamCake::view_order(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   //Throws a MISSING_INFO exception if either the cake size or design
   //were not specified.
   if (cake_size.empty() || design_type.empty())
       throw missing_info;
 
   cout << "\n      Order Details      "
        << "\n-------------------------";

   display_flavor();
   cout << "Cake size: " << cake_size
        << "\nDesign type: " << design_type;

   return 1;
}


// *****************************************************************************
// Function to place the user's ice cream cake order.
//
// order_num is passed a copy of the variable containing the assigned number
// for the current order.
//
// The function returns 0 if the user chooses to not confirm the order, or 1 if 
// the user chooses to confirm the order.
// *****************************************************************************
int IceCreamCake::place_order(int order_num) 
{ 
   view_order();

   float total_price {calculate_price()};
   char confirm_order {' '};

   //Displays the expected price of the ice cream cone.
   cout << "\nPrice: $" << total_price << endl;

   cout << "\nConfirm order? (y/n): ";
   cin >> confirm_order;
   cin.ignore(100, '\n');

   validate_yes_no_answer(confirm_order); 

   //Returns 1 to the calling routine if the user chooses to not confirm
   //their order at the moment.
   if (confirm_order == 'n')
       return 0;
  
   //Records the price of the ice cream order.
   checkout("ice cream cake", order_num, total_price); 

   return 1;
}


// *****************************************************************************
// Function to get the user's desired cake size.
//
// param: none
//
// The function returns 0 if the user selects an invalid cake size. Otherwise,
// the function returns 1 if the user selects a valid cake size.
// *****************************************************************************
int IceCreamCake::read_cake_size(void)
{
   int size_choice {0};
 
   //Displays the available cake sizes and their prices.  
   cout << "\nAvailable cake sizes: "
        << "\n1. Small: $" << SMALL_CAKE_PRICE
        << "\n2. Medium: $" << MEDIUM_CAKE_PRICE
        << "\n3. Large: $" << LARGE_CAKE_PRICE
        << endl;

   cout << "\nPlease select a cake size:  (Enter 1, 2, or 3): ";
   cin >> size_choice;

   //Saves the user's selected cake size.
   switch (size_choice)
   {
       case 1:
           cake_size = "small";
           break;

       case 2:
           cake_size = "medium";
           break;

       case 3:
           cake_size = "large";
           break;

       default:
           //Clears the input stream if a non-int type value was entered.
           if (cin.fail())
           {
               //Clears the error state.
               cin.clear();

               //Clears the invalid input.
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }

           //Displays an error message if the user enters something that is
           //not 1-3.
           cerr << "\nInvalid size selected. Please try again" << endl;

           break; 
   }

   if (cake_size.empty())
       return 0;

   return 1;
}


// *****************************************************************************
// Function to get the user's desired cake design type.
//
// param: none
//
// The function returns 0 if the user selects an invalid cake design type. 
// Otherwise, the function returns 1 if the user selects a valid cake design
// type.
// *****************************************************************************
int IceCreamCake::read_design_type(void)
{
   int design_choice {0};
 
   //Displays information about the available cake design types.   
   cout << "\nThere are three available cake design types: simple, themed, and "
        << "\nelaborate. Simple is the default design. Themed and elaborate "
        << "\ncakes have an additional $" << THEMED_CAKE_PRICE << " and "
        << "$" << ELABORATE_CAKE_PRICE << " design fee respectively." 
        << endl;

   //Displays the available cake design types.
   cout << "\nAvailable cake design types: "
        << "\n1. Simple (default)"
        << "\n2. Themed"
        << "\n3. Elaborate"
        << endl;

   cout << "\nPlease select a cake design:  (Enter 1, 2, or 3): ";
   cin >> design_choice;

   //Saves the user's selected cake size.
   switch (design_choice)
   {
       case 1:
           design_type = "simple";
           break;

       case 2:
           design_type = "themed";
           break;

       case 3:
           design_type = "elaborate";
           break;

       default:
           //Clears the input stream if a non-int type value was entered.
           if (cin.fail())
           {
               //Clears the error state.
               cin.clear();

               //Clears the invalid input.
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }

           //Displays an error message if the user enters something that is
           //not 1-3.
           cerr << "\nInvalid size selected. Please try again" << endl;

           break; 
   }

   if (design_type.empty())
       return 0;

   return 1;
}


// IMPLEMENTATION DETAILS FOR THE ICE CREAM SANDWICH CLASS

//Default constructor
IceCreamSandwich::IceCreamSandwich() : cookie_type(), filling_ratio(0)
{}


//Destructor
IceCreamSandwich::~IceCreamSandwich() 
{
   filling_ratio = 0;
}


// *****************************************************************************
// Function to display information about the ice cream sandwich dessert.
//
// param: none
//
// return: none
// *****************************************************************************
void IceCreamSandwich::display_dessert_info(void) const
{
   //Displays information about the ice cream cake dessert.
   cout << "\nGuests may pick from three types of cookie types: chocalate chip,"
        << "\ngingerbread, and cinnamon nand three filling ratios: 50%, 75%,"
        << "\nand 100%" << endl;
}


// ****************************************************************************
// Function to display the information in the current IceCreamSandwich object.
// 
// param: none
//
// return: none
// ****************************************************************************
void IceCreamSandwich::display_order_info(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   Dessert::display_order_info();

   //Throws a missing_info exception if the current IceCreamCone object 
   //contains missing information.
   if (cookie_type.empty() || !filling_ratio)
       throw missing_info;

   cout << "\nCookie type: " << cookie_type
        << "\nFilling ratio: " << filling_ratio << "%"
        << endl;
          
   return;
}


// *****************************************************************************
// Function to calculate the price of the user's ice cream sandwich order.
//
// param: none
//
// The function returns the calculated price of the ice cream sandwich order.
// *****************************************************************************
float IceCreamSandwich::calculate_price(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   //Throws a MISSING_INFO exception if either the cake size or design
   //were not specified.
   if (cookie_type.empty() || !filling_ratio)
       throw missing_info;

   //Variable to hold the price of the selected cake size.
   float cookie_type_price {0.0};

   //Sets the total price of cookie order based on the selected cookie type. 
   if (cookie_type == "chocolate chip")
       cookie_type_price = CHOCOLATE_CHIP_PRICE;

   else if (cookie_type == "gingerbread")
       cookie_type_price = GINGERBREAD_PRICE;
  
   else if (cookie_type == "cinnamon")
       cookie_type_price = CINNAMON_PRICE;

   return cookie_type_price;
}


// ****************************************************************************
// Function to display the user's ice cream sandwich order.
//
// param: none
//
// The function returns 1, indicating the display was successful.
// ****************************************************************************
int IceCreamSandwich::view_order(void) const
{
   //Exception object representing a missing information condition.
   MISSING_INFO missing_info;

   //Throws a MISSING_INFO exception if either the cake size or design
   //were not specified.
   if (cookie_type.empty() || !filling_ratio)
       throw missing_info;
  
   cout << "\n      Order Details      "
        << "\n-------------------------";

   display_flavor();
   cout << "Cookie type: " << cookie_type
        << "\nFilling ratio: " << filling_ratio << "%";

   return 1;
}


// *****************************************************************************
// Function to place the user's ice cream sandwich order.
//
// order_num is passed a copy of the variable containing the assigned number
// for the current order.
//
// The function returns 0 if the user chooses to not confirm the order, or 1 if 
// the user chooses to confirm the order.
// *****************************************************************************
int IceCreamSandwich::place_order(int order_num) 
{ 
   view_order();

   float total_price {calculate_price()}; 
   char confirm_order {' '};

   //Displays the expected price of the ice cream cone.
   cout << "\nPrice: $" << total_price << endl;

   cout << "\nConfirm order? (y/n): ";
   cin >> confirm_order;
   cin.ignore(100, '\n');

   validate_yes_no_answer(confirm_order); 

   //Returns 1 to the calling routine if the user chooses to not confirm
   //their order at the moment.
   if (confirm_order == 'n')
       return 0;
 
   //Records the price of the ice cream order.
   checkout("ice cream sandwich", order_num, total_price); 

   return 1;
}


// *****************************************************************************
// Function to get the user's desired cookie type.
//
// param: none
//
// The function returns 0 if the user selects an invalid cake size. Otherwise,
// the function returns 1 if the user selects a valid cake size.
// *****************************************************************************
int IceCreamSandwich::read_cookie_type(void)
{
   int cookie_choice {0};
 
   //Displays the available cake sizes and their prices.  
   cout << "\nAvailable cookie types: "
        << "\n1. Chocalate chip  ($" << CHOCOLATE_CHIP_PRICE << ")"
        << "\n2. Gingerbread     ($" << GINGERBREAD_PRICE << ")"
        << "\n3. Cinnamon        ($" << CINNAMON_PRICE << ")"
        << endl;

   cout << "\nPlease select a cookie type:  (Enter 1, 2, or 3): ";
   cin >> cookie_choice;

   //Saves the user's selected cookie type.
   switch (cookie_choice)
   {
       case 1:
           cookie_type = "chocolate chip";
           break;

       case 2:
           cookie_type = "gingerbread";
           break;

       case 3:
           cookie_type = "cinnamon";
           break;

       default:
           //Clears the input stream if a non-int type value was entered.
           if (cin.fail())
           {
               //Clears the error state.
               cin.clear();

               //Clears the invalid input.
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }

           //Displays an error message if the user enters something that is
           //not 1-3.
           cerr << "\nInvalid cookie type selected. Please try again" << endl;

           break; 
   }

   if (cookie_type.empty())
       return 0;

   return 1;
}


// *****************************************************************************
// Function to get the user's desired ice cream filling ratio.
//
// param: none
//
// The function returns 0 if the user selects an invalid filling ratio. 
// Otherwise, the function returns 1 if the user selects a valid filling ratio.
// *****************************************************************************
int IceCreamSandwich::read_filling_ratio(void)
{
   int filling_ratio_choice {0};
 
   //Displays the available ice cream sandwich filling ratios.
   cout << "\nAvailable filling ratios: "
        << "\n1. 50%"
        << "\n2. 75%"
        << "\n3. 100%"
        << endl;

   cout << "\nPlease select a filling ratio:  (Enter 1, 2, or 3): ";
   cin >> filling_ratio_choice;

   //Saves the user's selected filling ratio.
   switch (filling_ratio_choice)
   {
       case 1:
           filling_ratio = 50;
           break;

       case 2:
           filling_ratio = 75;
           break;

       case 3:
           filling_ratio = 100;
           break;

       default:
           //Clears the input stream if a non-int type value was entered.
           if (cin.fail())
           {
               //Clears the error state.
               cin.clear();

               //Clears the invalid input.
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
           }

           //Displays an error message if the user enters something that is
           //not 1-3.
           cerr << "\nInvalid filling ratio selected. Please try again" << endl;

           break; 
   }

   if (!filling_ratio)
       return 0;

   return 1;
}


// IMPLEMENTATION DETAILS FOR THE SALES STATISTICS CLASS

//Default constructor
SalesStatistics::SalesStatistics() : total_sales(0.0), chocolate_count(0),
vanilla_bean_count(0), strawberry_count(0), peaches_cream_count(0), 
cookies_cream_count(0)
{}

//Destructor
SalesStatistics::~SalesStatistics()
{
   reset();
}


// *****************************************************************************
// Function to update the total sales amount.
//
// to_add is passed a copy of the variable containing an amount to add to the
// running total_sales.
//
// The function returns 0 if the to_add is a nonpositive value. Otherwise, the
// function returns 1.
// *****************************************************************************
int SalesStatistics::update_total_sales(float to_add)
{
   //Returns 0 to the calling routine if to_add is a nonpositive value.
   if (to_add < 1)
       return 0;

   total_sales += to_add;

   return 1;
}


// *****************************************************************************
// Function to increment the frequency count for a specified ice cream
// flavor.
//
// flavor is passed reference to the variable containing the flavor name.
//
// The function returns 0 if an invalid flavor was passed in. Otherwise, the
// function returns 1.
// *****************************************************************************
int SalesStatistics::update_flavor_count(const string & flavor)
{
   bool valid_flavor {true};

   //Increments the frequency count for the specified ice cream flavor.
   if (!strcasecmp(flavor.c_str(), "chocolate"))
       ++chocolate_count;

   else if (!strcasecmp(flavor.c_str(), "vanilla bean"))
       ++vanilla_bean_count;
    
   else if (!strcasecmp(flavor.c_str(), "strawberry"))
       ++strawberry_count;

   else if (!strcasecmp(flavor.c_str(), "peaches and cream"))
       ++peaches_cream_count;

   else if (!strcasecmp(flavor.c_str(), "cookies and cream"))
       ++cookies_cream_count;
      
   else
   {
       cerr << "\n" << flavor << " is not a valid flavor." << endl;
       valid_flavor = false;
   }

   //Returns 0 to the calling routine if an invalid flavor was passed in.
   if (!valid_flavor)
       return 0;

   return 1;
}


// *****************************************************************************
// Function to display the total monthly sales and the frequency of purchases
// for each ice cream flavor.
//
// paran: none
//
// The function returns 1.
// *****************************************************************************
int SalesStatistics::display_statistics(void) const
{
   //Displays the total monthly sales.
   cout << "\nTotal sales: $" << total_sales << endl;

   //Displays the frequency of purchases for each ice cream flavor.
   cout << "\n    Flavor frequency     "
        << "\n-------------------------"
        << "\nChocolate: " << chocolate_count
        << "\nVanilla bean: " << vanilla_bean_count
        << "\nStrawberry: " << strawberry_count
        << "\nPeaches and Cream: " << peaches_cream_count 
        << "\nCookies and Cream: " << cookies_cream_count
        << endl;

   return 1; 
}


// *****************************************************************************
// Function to reset the sales statistics to their zero equivalent values.
//
// param: none
//
// The function returns 1.
// *****************************************************************************
int SalesStatistics::reset(void)
{
   total_sales = 0.0;
   chocolate_count = 0; 
   vanilla_bean_count = 0; 
   strawberry_count = 0; 
   peaches_cream_count = 0; 
   cookies_cream_count = 0; 

   return 1;
}

