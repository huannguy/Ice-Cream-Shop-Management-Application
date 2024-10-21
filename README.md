Huan Nguyen 
huannguy@pdx.edu

The .cpp files can be compiled by typing "make" on the command line.
The files are compiled with g++ *.cpp -std=c++17 -g -Wall

The program can be run by typing ./a.out on the command line.

The Ice Cream Shop Manager is an application intended to manages montly Ice
cream sales and track sales and the frequency of purchases for different ice 
cream flavors.

The Ice Cream Shop Manager supports six main operations:
1. Place an order
2. Look up a previous order
3. View all orders
4. View end-of-month report
5. Clear order log
6. Quit

"Place an order" lets the user add an ice cream dessert order to the order log
"Look up a previous order" searches for a particular order in the order log via
a specified order number. "View all order" displays all orders in the order log.
"View end-of-month report" will display the total sales at the end of the month
and the frequency of purchases for each flavor and clears the order log.
"Clear order log" will clear the order log. "Quit" will end the program.

There are five ice cream flavors that guests can choose from: 
chocolate, vanilla bean, strawberry, peaches and cream, and cookies and cream.

There are three ice cream dessert types: ice cream cone, ice cream cake,
and ice cream sandwich.

For the ice cream cone, guests may select from two cone types: sugar cone and
waffle cone which cost $1.25 and $2.50 respectively, and request up to three 
total scoops with each additional scoop after the first costing 15 cents extra
per scoop. Flavors may not be mixed with the scoops.

For the ice cream cake, guests may select from three cake sizes: small, medium, 
and large which cost $10, $15, and $20 respectively. Guests may select from 
three cake design types: simple, themed, and elaborate. Themed and elaborate
cakes costs an additional $2.50 and $5.00 fee.

For the ice cream sandwich, guests may select from three cookie types: 
chocolate chip, gingerbread, and cinnamon, which costs $1.50, $2.50, and
$3.00 respectively. Additionally, guests may specify their desired ratio
50%, 75%, or 100%, none of which entail an additional fee.

The program contains an inheritance of hierarchy consisting of four classes:
a class called Dessert and its three immediate derived classes: IceCreamCone,
IceCreamCake, and IceCreamSandwich. 

Additionally, the program supports dynamic binding and RTTI.The Dessert class is 
an abstract base class as it contains a pure virtual function. As a result, it 
is not possible to create an object of type Dessert. The derived classes are not 
abstract classes because the base class's pure virtual function is implemented 
in all three. 

The dynamically bound methods in the Dessert class are display_dessert_info(),
display_order_info(), calculate_price(), place_order(), and view_order(). All
these methods have been overidden in the derived classes. 

Each derived class contains two methods that are not declared virtual in the
Dessert class. These functions can be called through a base class pointer 
through downcasting, which should be done with the dynamic_cast operator.


