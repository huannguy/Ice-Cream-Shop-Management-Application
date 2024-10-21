// *****************************************************************************
// Author:     Huan Nguyen
// Date:       05/15/2024
// Class:      CS 302
// Project:    Program Assignment #3
// File Name:  hierarchy.h
// Purpose:    This file contains the interfaces for the Dessert, IceCreamCone,
//             IceCreamCake, and IceCreamSandwich classes, which together form
//             the inheritance hierarchy for the application, and the 
//             SalesStatistics class that will track the total monthly sales 
//             and the frequency of purchases for each flavor.
// *****************************************************************************

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <cstring>
#include <limits>

using std::ostream;
using std::string;

const float EXTRA_SCOOP_FEE {0.15};
const float SUGAR_CONE_PRICE {1.25};
const float WAFFLE_CONE_PRICE {2.50};

//Constants to set the base prices of different cake sizes.
const float SMALL_CAKE_PRICE {10.00};
const float MEDIUM_CAKE_PRICE {15.00};
const float LARGE_CAKE_PRICE {20.00};

//Constants to set the prices of the themed and elaborate cake designs.
const float THEMED_CAKE_PRICE {2.50};
const float ELABORATE_CAKE_PRICE {5.00};

//Constants to set the prices of the ice cream sandwich cookie types.
const float CHOCOLATE_CHIP_PRICE {1.50};
const float GINGERBREAD_PRICE {2.50};
const float CINNAMON_PRICE {3.00};

//Interface for the Dessert class, which will serve as the base class of
//the inheritance hierarchy. 
class Dessert
{
   public:
       Dessert();             //Constructor
       virtual ~Dessert();    //Destructor

       friend bool operator<(const Dessert &, const Dessert &);
       friend bool operator<(int order_num, const Dessert &);

       friend bool operator==(const Dessert &, int order_num);
       friend bool operator==(int order_num, const Dessert &);

       int choose_flavor(void);
       int checkout(const string & dessert, int order_num, float total_price);
       bool retrieve_flavor(string & to_retrieve) const;

       virtual void display_dessert_info(void) const = 0;   //Pure virtual function.
       virtual void display_order_info(void) const;
       virtual float calculate_price(void) const;
       virtual int place_order(int order_num);
       virtual int view_order(void) const;
    
   protected:
       string flavor;
       string dessert_type;
       int order_id;
       float price;

       int display_flavor(void) const;
};


//Interface for the IceCreamCone class, which provide functionalities for
//handling the order placement, price calculation, and customization of an ice
//cream cone.
class IceCreamCone : public Dessert
{
   public:
       IceCreamCone();    //Constructor
       ~IceCreamCone();   //Destructor

       void display_dessert_info(void) const;
       void display_order_info(void) const;
       float calculate_price(void) const; 
       int place_order(int order_num);
       int view_order(void) const;

       int read_num_scoops(void);
       int read_cone_type(void);

   protected:
       string cone_type;
       int num_scoops;
};


//Interface for the IceCreamCake class, which provide functionalities for
//handling the order placement, price calculation, and customization of an ice
//cream cake.
class IceCreamCake : public Dessert
{
   public:
       IceCreamCake();    //Constructor
       ~IceCreamCake();   //Destructor

       void display_dessert_info(void) const;
       void display_order_info(void) const;
       float calculate_price(void) const; 
       int view_order(void) const;
       int place_order(int order_num);

       int read_cake_size(void);
       int read_design_type(void);

   protected:
       string cake_size;
       string design_type;
};


//Interface for the IceCreamSandwich class, which provide functionalities for
//handling the order placement, price calculation, and customization of an ice
//cream sandwich.
class IceCreamSandwich : public Dessert
{
   public:
       IceCreamSandwich();    //Constructor
       ~IceCreamSandwich();   //Destructor

       void display_dessert_info(void) const;
       void display_order_info(void) const;
       float calculate_price(void) const; 
       int place_order(int order_num);
       int view_order(void) const;
       
       int read_cookie_type(void);
       int read_filling_ratio(void);

   protected:
       string cookie_type;
       int filling_ratio;
};


class SalesStatistics
{
   public:
       SalesStatistics();
       ~SalesStatistics();

       int update_total_sales(float to_add);
       int update_flavor_count(const string & flavor);
       int display_statistics(void) const;
       int reset(void);

   protected:
      float total_sales;
      int chocolate_count;
      int vanilla_bean_count;
      int strawberry_count;
      int peaches_cream_count;
      int cookies_cream_count;
};

void validate_yes_no_answer(char & yes_no_answer);
