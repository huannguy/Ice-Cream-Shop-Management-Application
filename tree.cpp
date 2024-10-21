// *****************************************************************************
// Author:     Huan Nguyen
// Date:       05/18/2024
// Class:      CS 302
// Project:    Program Assignment #3
// File Name:  tree.cpp
// Purpose:    This file contains the implemetation details defined in the  
//             Node234 and Tree classes.
// *****************************************************************************

#include "tree.h"
#include "exceptions.h"

using namespace std;

// IMPLEMENTATION DETAILS FOR THE NODE234 class.

//Default constructor
Node234::Node234() : num_data_items(0)
{
   //Initializes all four child pointers to null.
   for (int i = 0; i < 4; ++i)
      child[i] = nullptr;
}


//Copy constructor
Node234::Node234(const Node234 & to_copy) : num_data_items(to_copy.num_data_items)
{
   //Aliases for the IceCreamCone, IceCreamCake, and IceCreamSandwich
   //classes.
   typedef IceCreamCone Cone;
   typedef IceCreamCake Cake;
   typedef IceCreamSandwich Sandwich;

   //Deep copies the data pointers.
   for (int i = 0; i < 3; ++i)
      if (to_copy.data[i])
      {
          //If to_copy.data[i] is pointing to an object of type IceCreamCone.
          if (typeid(*to_copy.data[i]) == typeid(IceCreamCone))
          {
              //Assign the current data[i] to point to an IceCreamCone
              //object and copies the data over.
              data[i] = make_unique<IceCreamCone>();

              //Copies the ice cream cone dessert order.
              static_cast<Cone &>(*data[i]) = static_cast<Cone &>(*to_copy.data[i]);
          }
          
          //If instead, to_copy.data[i] is pointing to an object of type 
          //IceCreamCake
          else if (typeid(*to_copy.data[i]) == typeid(IceCreamCake))
          { 
              //Assign the current data[i] to point to an IceCreamCake
              //object and copies the data over.
              data[i] = make_unique<IceCreamCake>();
              *data[i] = *to_copy.data[i];

              //Copies the ice cream cake order.
              static_cast<Cake &>(*data[i]) = static_cast<Cake &>(*to_copy.data[i]);
          }

          //If instead, to_copy.data[i] is pointing to an object of type 
          //IceCreamSandwich
          else if (typeid(*to_copy.data[i]) == typeid(IceCreamSandwich))
          { 
              //Assign the current data[i] to point to an IceCreamCake
              //object and copies the data over.
              data[i] = make_unique<IceCreamSandwich>();
              *data[i] = *to_copy.data[i];

              //Copies the ice cream sandwich dessert order.
              static_cast<Sandwich &>(*data[i]) = static_cast<Sandwich &>(*to_copy.data[i]);
          }
      }

   //Initializes all four child pointers to null.
   for (int i = 0; i < 4; ++i)
      child[i] = nullptr;

}


//Destructor
Node234::~Node234()
{
   //Traverses the array of child pointers.
   for (int i = 0; i < 4; ++i)
   {
       //If the child pointer currently being processed is null...
       if (child[i])  
       {
           //Deallocates the dynamic memory child[i] is pointing to. 
           delete child[i];
           child[i] = nullptr;
       } 
   }
}


// *****************************************************************************
// Function to overload the = operator for the Node234 class.
//
// to_copy is passed reference to the Node234 object to be copied.
//
// The function returns the current Node234 object by reference.
// *****************************************************************************
Node234 & Node234::operator=(const Node234 & to_copy)
{
   //Aliases for the IceCreamCone, IceCreamCake, and IceCreamSandwich
   //classes.
   typedef IceCreamCone Cone;
   typedef IceCreamCake Cake;
   typedef IceCreamSandwich Sandwich;

   if (this == &to_copy)
       return *this;

   //Deep copies the data pointers.
   for (int i = 0; i < 3; ++i)
      if (to_copy.data[i])
      {
          //If to_copy.data[i] is pointing to an object of type IceCreamCone.
          if (typeid(*to_copy.data[i]) == typeid(IceCreamCone))
          {
              //Assign the current data[i] to point to an IceCreamCone
              //object and copies the data over.
              data[i] = make_unique<IceCreamCone>();
              *data[i] = *to_copy.data[i];

              static_cast<Cone &>(*data[i]) = static_cast<Cone &>(*to_copy.data[i]);
          }
          
          //If instead, to_copy.data[i] is pointing to an object of type 
          //IceCreamCake
          else if (typeid(*to_copy.data[i]) == typeid(IceCreamCake))
          { 
              //Assign the current data[i] to point to an IceCreamCake
              //object and copies the data over.
              data[i] = make_unique<IceCreamCake>();
              

              //Copies the ice cream sandwich dessert order.
              static_cast<Cake &>(*data[i]) = static_cast<Cake &>(*to_copy.data[i]);
          }

          //If instead, to_copy.data[i] is pointing to an object of type 
          //IceCreamSandwich
          else if (typeid(*to_copy.data[i]) == typeid(IceCreamSandwich))
          { 
              //Assign the current data[i] to point to an IceCreamCake
              //object and copies the data over.
              data[i] = make_unique<IceCreamSandwich>();
              
              //Copies the ice cream sandwich dessert order.
              static_cast<Sandwich &>(*data[i]) = static_cast<Sandwich &>(*to_copy.data[i]);
          }
      }

   //Initializes all four child pointers to null.
   for (int i = 0; i < 4; ++i)
      child[i] = nullptr;
  
   num_data_items = to_copy.num_data_items;

   return *this;
}



// *****************************************************************************
// Function to handle inserting a new ice cream dessert order into the node.
//
// to_add is passed a reference of the unique pointer pointing to the ice cream
// dessert order to be added.
//
// The function returns 0 if the node already contains three data items. 
// Otherwise, the function returns 1.
// *****************************************************************************
int Node234::insert_data(unique_ptr<Dessert> & to_add)
{
   //Returns 0 to the calling return if there are three data items in the
   //node.
   if (num_data_items == 3)
       return 0;

   //Assigns the data[0] to point to the new ice cream dessert object as
   //zero data items in the node...
   if (!num_data_items)
       data[0] = move(to_add);

   //If there is already a data item in the node...
   else if (num_data_items == 1)
   {
       //If the new ice cream dessert object's order number is less than that
       //of the ice cream dessert object data[0] is pointing to.
       if (*to_add < *data[0])
       {
           data[1] = move(data[0]);
           data[0] = move(to_add);
       }
      
       //Assigns data[1] to point to the new ice cream dessert order if
       //its order number is larger than those of the previous objects.
       else
           data[1] = move(to_add);
   }

   //If there is already two data items in the node...
   else if (num_data_items == 2)
   {
       //If the new ice cream dessert object's order number is less than that
       //of the ice cream dessert object data[0] is pointing to...
       if (*to_add < *data[0])
       {
           data[2] = move(data[1]);
           data[1] = move(data[0]);
           data[0] = move(to_add);
       }

       //If the new ice cream dessert object's order number is less than that
       //of the ice cream dessert object data[1] is pointing to...
       else if (*to_add < *data[1])
       {
           data[2] = move(data[1]);
           data[1] = move(to_add);
       }
      
       //Assigns data[2] to point to the new ice dessert object if its order
       //number is larger than those of the previous objects. 
       else
           data[2] = move(to_add); 
   }

   ++num_data_items;  

   return 1;
}


// *****************************************************************************
// Function to check if the current node is full.
//
// param: none
//
// The function returns false if the number of data items in the node is not
// equal to three. Otherwise, the function returns true if the node has three
// data items.
// *****************************************************************************
bool Node234::is_full(void) const
{
   return num_data_items == 3;
}


// *****************************************************************************
// Function to check if the current node is a leaf.
//
// param: none
//
// The function returns false if at least one of the four child pointers is not
// null. Otherwise, the function returns true if all child pointers are null.
// *****************************************************************************
bool Node234::is_leaf(void) const
{
   return !child[0] && !child[1] && !child[2] && !child[3];
}


// *****************************************************************************
// Function to adjust the number of data items in the current node.
//
// to_update is passed a copy of the variable containing the new number of data 
// items.
//
// The function returns 0 if to_update is negative or is greater than 3. 
// Otherwise, the function returns 1.
// *****************************************************************************
int Node234::update_num_data_items(int to_update)
{
   //Returns 0 to the calling routine if either to_update is negative or
   //is greater than 3.
   if (to_update < 0 || to_update > 3)
       return 0;

   //Assigns num_data_items the value of to_update;
   num_data_items = to_update;

   return 1;
}


// *****************************************************************************
// Function to assign the node's left pointer to point to a new address.
//
// new_left is passed a copy of the pointer to an address.
//
// The function returns 1.
// *****************************************************************************
int Node234::set_left(Node234 * new_left)
{
   //Assigns the left pointer the value of new_left.
   child[0] = new_left;

   return 1;
}


// *****************************************************************************
// Function to assign the node's left-middle pointer to point to a new address.
//
// new_left_middle is passed a copy of the pointer to an address.
//
// The function returns 1.
// *****************************************************************************
int Node234::set_left_middle(Node234 * new_left_middle)
{
   //Assigns the left-middle pointer the value of new_left.
   child[1] = new_left_middle;

   return 1;
}


// *****************************************************************************
// Function to assign the node's right-middle pointer to point to a new address.
//
// new_right_middle is passed a copy of the pointer to an address.
//
// The function returns 1.
// *****************************************************************************
int Node234::set_right_middle(Node234 * new_right_middle)
{
   //Assigns the right-middle pointer the value of new_left.
   child[2] = new_right_middle;

   return 1;
}


// *****************************************************************************
// Function to assign the node's right pointer to point to a new address.
//
// new_right is passed a copy of the pointer to an address.
//
// The function returns 1.
// *****************************************************************************
int Node234::set_right(Node234 * new_right)
{
   //Assigns the right pointer the value of new_left.
   child[3] = new_right;

   return 1;
}


// *****************************************************************************
// Getter function to return a pointer reference to the node's left pointer.
//
// param: none
//
// The function returns a pointer reference to the node's left pointer.
// *****************************************************************************
Node234 * & Node234::get_left(void)
{
   return child[0];
}


// *****************************************************************************
// Getter function to return a pointer reference to the node's left-middle
// pointer.
//
// param: none
//
// The function returns a pointer reference to the node's left-middle pointer.
// *****************************************************************************
Node234 * & Node234::get_left_middle(void)
{ 
   return child[1];
}


// *****************************************************************************
// Getter function to return a pointer reference to the node's right-middle 
// pointer.
//
// param: none
//
// The function returns a pointer reference to the node's right-middle pointer.
// *****************************************************************************
Node234 * & Node234::get_right_middle(void)
{
   return child[2];
}


// *****************************************************************************
// Getter function to return a pointer reference to the node's right pointer.
//
// param: none
//
// The function returns a pointer reference to the node's right pointer.
// *****************************************************************************
Node234 * & Node234::get_right(void)
{
   return child[3];
}


// *****************************************************************************
// Getter function to return a unique pointer reference to a specific data 
// pointer.
//
// param: none
//
// The function returns a pointer reference to a specific data pointer.
// *****************************************************************************
unique_ptr<Dessert> & Node234::get_data(int data_index)
{
   OUT_OF_BOUNDS out_of_bounds;
 
   if (data_index < 0 || data_index > 2)
       throw out_of_bounds;

   return data[data_index];
}


// IMPLEMENTATION DETAILS FOR THE TREE class.

//Default constructor
Tree::Tree() : root(nullptr)
{}


//Copy constructor
Tree::Tree(const Tree & to_copy) : root(nullptr)
{
   if(to_copy.root)
      deep_copy(root, to_copy.root); 
}


//Destructor
Tree::~Tree()
{
   if (root)
   {
       remove_all(root);
       root = nullptr;
   }
}


// ****************************************************************************
// Function to overload the = operator for the Tree class.
// 
// src is passed a reference to the Tree object to be copied.
//
// The function returns an the current object by reference.
// ****************************************************************************
Tree & Tree::operator=(const Tree & src)
{
   //Returns the current Tree object if the Tree object to be copied is the
   //same as the current Tree object.
   if (this == &src)
       return *this;

   //If the 2-3-4 tree to be copied is not empty...
   if (src.root)
   {
      //Deallocates the current 2-3-4 tree if it is not empty.
      if (root)
          remove_all(root);

      //Performs a deep copy of the 2-3-4 tree to be copied.
      deep_copy(root, src.root);
   }

   return *this;
}


// ****************************************************************************
// Wrapper function to add an ice cream dessert order to the 2-3-4 tree.
// 
// to_add is passed a reference to the unique pointer to the Dessert object
// to be added.
//
// The function returns the level in the tree where the ice cream dessert order
// was added.
// ****************************************************************************
int Tree::insert(unique_ptr<Dessert> & to_add)
{
   //If the 2-3-4 tree is empty...
   if (!root)
   {
       //Creates a new node and inserts the data item into it.
       root = new Node234;
       root->insert_data(to_add);  

       return 1;
   }

   //If the root node is full...
   if (root->is_full())
   {
       //Creates a new node. 
       Node234 * new_node = new Node234;
 
       //Assigns the newly created node's left pointer to point to root node.
       new_node->set_left(root);

       //Assigns root to point to the newly created node.
       root = new_node;

       //Splits the node.
       split_node(new_node, new_node->get_left());
   }

   return insert(root, to_add);
}


// ****************************************************************************
// Wrapper function to find and display information about a specific ice cream 
// dessert order.
// 
// order_num is passed a copy of the variable containing a specified order 
// number.
//
// The function returns -1 if the 2-3-4 tree is empty, 0 if the desired ice
// cream dessert order could not be found, or 1 if the ice cream dessert
// order was found.
// ****************************************************************************
int Tree::find_order(int order_num) const
{
   //Returns -1 to the calling routine if the 2-3-4 tree is empty.
   if (!root)
       return -1;

   return find_order(root, order_num);
}


// ****************************************************************************
// Wrapper function to display all ice cream dessert orders in sorted order.
// 
// param: none
//
// The function returns 0 if the 2-3-4 tree is empty. Otherwise, the function
// returns the number of data items that were displayed..
// ****************************************************************************
int Tree::display_all(void) const
{
   //Returns 0 to the calling routine if the 2-3-4 tree is empty.
   if (!root)
       return 0;

   return display_all(root);
}


// ****************************************************************************
// Wrapper function to assess the the total sales amount and the frequency
// of purchases for each ice cream flavor.
// 
// report is passed a reference to the object that will track the total sales
// amount and the frequency of purchases for each ice cream flavor.
//
// The function returns the number of nodes in the tree,
// ****************************************************************************
int Tree::assess_total_sales(SalesStatistics & report) const
{
   //Returns 0 to the calling routine if the 2-3-4 tree is empty.
   if (!root)
       return 0;

   return assess_total_sales(root, report); 
}


// ****************************************************************************
// Wrapper function to remove all nodes in the 2-3-4 tree.
// 
// root is passed a reference to the pointer to the current node in the 2-3-4
// tree.
//
// The function returns the number of nodes removed.
// ****************************************************************************
int Tree::remove_all(void)
{
   //Returns 0 to the calling routine if the 2-3-4 tree is empty.
   if (!root)
       return 0;

   int count {remove_all(root)};

   root = nullptr;

   return count; 
}


// ****************************************************************************
// Recursive function to add an ice cream dessert order to the 2-3-4 tree.
// 
// root is passed a reference to the pointer to the current node being 
// prcoessed.
// to_add is passed a reference to the unique pointer to the Dessert object
// to be added.
//
// The function returns the level in the tree where the ice cream dessert order
// was added.
// ****************************************************************************
int Tree::insert(Node234 * & root, unique_ptr<Dessert> & to_add)
{ 
   //If the current node is a leaf...
   if (root->is_leaf())
   { 
       //Inserts the data item into the current node.
       root->insert_data(to_add);

       //Stops the recursive traversal of the current path and returns 1 to
       //the calling routine.
       return 1;
   }

   //Variable to track the level in the tree at which the data item 
   //is added.
   int level {0};

   //If the Dessert object's order number is less than that of the first 
   //Dessert object in the node...
   if (*to_add < *root->get_data(0)) 
   {
       //Splits the left child node if it is full.
       if (root->get_left())
           if (root->get_left()->is_full())
               split_node(root, root->get_left());

       //Traverses the left subtree.
       level = insert(root->get_left(), to_add);
   }

   //If the Dessert object's order number is less than that of the second
   //Dessert object in the node... 
   else if (!root->get_data(1))
   {
       //Splits the left-middle child node if it is full.
       if (root->get_left_middle())
           if (root->get_left_middle()->is_full())
               split_node(root, root->get_left_middle());

       if (!root->get_data(1) || *to_add < *root->get_data(1))
           level = insert(root->get_left_middle(), to_add);

       else 
           level = insert(root->get_right_middle(), to_add); 
   }

   //If the Dessert object's order number is less than that of the third
   //Dessert object in the node... 
   else if (!root->get_data(2))
   {
       //Splits the right-middle child node if it is full.
       if (root->get_right_middle())
           if (root->get_right_middle()->is_full())
               split_node(root, root->get_right_middle());

       if (!root->get_data(2) || *to_add < *root->get_data(2))
           level = insert(root->get_right_middle(), to_add);

       else 
           level = insert(root->get_right(), to_add); 
   }
 
   return level += 1;
}


// ****************************************************************************
// Function to push up the middle data item in a 2-3-4 node before splitting
// it.
// 
// parent is passed a reference to the pointer to a node in the 2-3-4 tree.
// child is passed a reference to the pointer to a node that is an immediate 
// child of the node parent is pointing to.
//
// The function returns the level in the tree where the ice cream dessert order
// was added.
// ****************************************************************************
int Tree::split_node(Node234 * & parent, Node234 * & child)
{
   //Pushes up the middle data item to the parent node.
   parent->insert_data(child->get_data(1));
  
   //Creates a new node. 
   Node234 * new_node = new Node234;

   //Moves the largest data item into the newly created node.
   new_node->insert_data(child->get_data(2));

   //Assigns the newly created node's left pointer to point to the
   //same node as the child node's right_middle pointer.
   new_node->set_left(child->get_right_middle());
   child->set_right_middle(nullptr);

   //Assigns the newly created node's left-middle pointer to point to the
   //same node as the child node's right pointer.
   new_node->set_left_middle(child->get_right());
   child->set_right(nullptr);

   //Updates the number of data items in the child node after the split.
   child->update_num_data_items(1);

   //Assigns the parent node's left-middle pointer to point to the
   //newly created node if child is pointing to the left child node of 
   //the parent node.
   if (parent->get_left() == child)
       parent->set_left_middle(new_node);

   //Assigns the parent node's right-middle pointer to point to the
   //newly created node if child is pointing to the left-middle child node of 
   //the parent node.
   else if (parent->get_left_middle() == child)
       parent->set_right_middle(new_node);

   //Assigns the parent node's right pointer to point to the
   //newly created node if child is pointing to the right-middle child node of 
   //the parent node.
   else if (parent->get_right_middle() == child)
       parent->set_right(new_node);

   //Assigns the parent node's right-middle pointer to point to the
   //newly created node if child is pointing to the right child node of 
   //the parent node.
   else
   {
       parent->set_right_middle(child);
       child = new_node;
   }
 
   return 1; 
}

// ****************************************************************************
// Recursive function to find and display information about a specific ice cream 
// dessert order.
// 
// order_num is passed a copy of the variable containing a specified order 
// number.
//
// The function returns 0 if the desired ice cream dessert order could not be 
// found, or 1 if the ice cream dessert order was found.
// ****************************************************************************
int Tree::find_order(Node234 * root, int order_num) const
{
   //Stops the recursive traversal of the current path down the tree and 
   //returns 0 to the calling routine if root is null.
   if (!root) 
       return 0;

   //If the order number of the first ice cream dessert order in the current
   //node matches the specified order number...
   if (*root->get_data(0) == order_num)
   {
       try
       {
           //Displays the details of the order.
           root->get_data(0)->display_order_info();
       }

       catch (MISSING_INFO exception)
       {
           //Displays the MISSING_INFO exception message.
           cout << "\n" << exception.error_msg << endl;
       }

       return 1;
   }

   //If there is a second ice cream dessert order in the current node 
   //and its order number matches the specified order number...
   if (root->get_data(1) && *root->get_data(1) == order_num)
   { 
       try
       {
           //Displays the details of the second ice cream dessert order.
           root->get_data(1)->display_order_info();
           //cout << "\n" << *root->get_data(1) << endl;
       }
    
       catch (MISSING_INFO exception)
       {
           //Displays the MISSING_INFO exception message. 
           cout << "\n" << exception.error_msg << endl;
       }

       return 1;
   }

   //If there is a third ice cream dessert order in the current node
   //and its order number matches the specified order number...
   if (root->get_data(2) && *root->get_data(2) == order_num)
   {
       try
       {
           //Displays the details of the third ice cream dessert order.
           root->get_data(2)->display_order_info();
           //cout << "\n" << *root->get_data(2) << endl;
       }

       catch (MISSING_INFO exception)
       {
           //Displays the MISSING_INFO exception message. 
           cout << "\n" << exception.error_msg << endl;
       }

       return 1;
   }

   int result {0};

   //Traverses the left subtree if the specified order number is less than
   //that of the first ice cream dessert order.
   if (order_num < *root->get_data(0))
       result = find_order(root->get_left(), order_num);
  
   //Traverses the left-middle subtree if either the current node
   //only contains a single data item or the specified order number is
   //less than of the second ice cream dessert order. 
   else if (!root->get_data(1) || order_num < *root->get_data(1))
       result = find_order(root->get_left_middle(), order_num); 

   //Traverses the right-middle subtree if either the current node
   //only contains two data items or the specified order number is
   //less than of the second ice cream dessert order. 
   else if (!root->get_data(2) || order_num < *root->get_data(2))
       result = find_order(root->get_right_middle(), order_num);

   //Traverses the right subtree if the specified order number is greater
   //than that of the third ice cream dessert order.
   else 
       result = find_order(root->get_right(), order_num);

   return result;   
}


// ****************************************************************************
// Recursive function to display all ice cream dessert orders in sorted order.
// 
// param: none
//
// The function returns 0 if the 2-3-4 tree is empty. Otherwise, the function
// returns the number of data items that were displayed..
// ****************************************************************************
int Tree::display_all(Node234 * root) const
{
   //Stops the recursive traversal of the current path down the tree if root is 
   //null and return 0 to the calling routine.
   if (!root)
       return 0;

   int count {0};

   count += display_all(root->get_left());

   try
   {
       //Displays the details of the frist ice cream dessert order.
       root->get_data(0)->display_order_info();
   }

   catch (MISSING_INFO exception)
   {
       //Displays the MISSING_INFO exception message.
       cout << "\n" << exception.error_msg << endl;
   }

   count += display_all(root->get_left_middle());

   //If the node contains a second ice cream dessert order...
   if (root->get_data(1))
   { 
       try
       {
           //Displays the details of the second ice cream dessert order.
           root->get_data(1)->display_order_info();
           //cout << "\n" << *root->get_data(1) << endl;
       }
    
       catch (MISSING_INFO exception)
       {
           //Displays the MISSING_INFO exception message. 
           cout << "\n" << exception.error_msg << endl;
       }
   }

   count += display_all(root->get_right_middle());

   //If the node contains a third ice cream dessert order...
   if (root->get_data(2))
   {
       try
       {
           //Displays the details of the third order.
           root->get_data(2)->display_order_info();
           //cout << "\n" << *root->get_data(2) << endl;
       }

       catch (MISSING_INFO exception)
       {
           //Displays the MISSING_INFO exception message.
           cout << "\n" << exception.error_msg << endl; 
       }
   }

   count += display_all(root->get_right());

   return count += 1;
}


// ****************************************************************************
// Recursive function to assess the the total sales amount and the frequency
// of purchases for each ice cream flavor.
// 
// root is passed a copy of the pointer to the current node in the 2-3-4 tree.
//
// report is passed a reference to the object that will track the total sales
// amount and the frequency of purchases for each ice cream flavor.
//
// The function returns the number of nodes in the tree,
// ****************************************************************************
int Tree::assess_total_sales(Node234 * root, SalesStatistics & report) const
{ 
   //Stops the recursive traversal of the current path down the tree if root is 
   //null and return 0 to the calling routine.
   if (!root)
       return 0;

   int count {0};       

   //Variables to hold the price and flavor of the ice cream dessert order being
   //assessed.
   float price {0.0};
   string flavor {" "};   

   //Traverses the left subtree.
   count += assess_total_sales(root->get_left(), report);

   //Records price and flavor of the first ice cream dessert order.
   price = root->get_data(0)->calculate_price();
   root->get_data(0)->retrieve_flavor(flavor);

   //Adds the ice cream dessert order's price to the total sales amount
   //and records its flavor.
   report.update_total_sales(price);
   report.update_flavor_count(flavor);

   //Traverses the left-middle subtree.
   count += assess_total_sales(root->get_left_middle(), report); 

   //If the node contains a second ice cream dessert order...
   if (root->get_data(1))
   {
      
      //Records price and flavor of the second ice cream dessert order.
      price = root->get_data(1)->calculate_price();
      root->get_data(1)->retrieve_flavor(flavor);

      //Adds the ice cream dessert order's price to the total sales amount
      //and records its flavor.
      report.update_total_sales(price);
      report.update_flavor_count(flavor);

   }

   //Traverses the right-middle subtree.
   count += assess_total_sales(root->get_right_middle(), report);

   //If the node contains a third ice cream dessert order.
   if (root->get_data(2))
   {
      //Records price and flavor of the third ice cream dessert order.
      price = root->get_data(2)->calculate_price();
      root->get_data(2)->retrieve_flavor(flavor);

      //Adds the ice cream dessert order's price to the total sales amount
      //and records its flavor.
      report.update_total_sales(price);
      report.update_flavor_count(flavor);

   }

   //Traverses the right subtree.
   count += assess_total_sales(root->get_right(), report);
  
   return count += 1;
}


// ****************************************************************************
// Recursive function to copy a 2-3-4 tree.
// 
// dest_root is passed a reference to the pointer to the current node in the
// current 2-3-4 tree.
//
// root is passed a copy of the pointer to the current node in the 2-3-4
// tree to be copied.
//
// The function returns the number of nodes copied.
// ****************************************************************************
int Tree::deep_copy(Node234 * & dest_root, Node234 * src_root)
{
   //Stops the recursive traversal of the current path down the tree if root is 
   //null and return 0 to the calling routine.
   if (!src_root)
       return 0;

   int count {0};

   //If dest_root is null... 
   if (!dest_root)
   {
       //Creates a new node, passing the current node in the 2-3-4 tree to
       //be copied.
       dest_root = new Node234(*src_root);
       ++count;       
   }   

   count += deep_copy(dest_root->get_left(), src_root->get_left());
   count += deep_copy(dest_root->get_left_middle(), src_root->get_left_middle()); 
   count += deep_copy(dest_root->get_right_middle(), src_root->get_right_middle());  
   count += deep_copy(dest_root->get_right(), src_root->get_right());

   return count;
}


// ****************************************************************************
// Recursive function to remove all nodes in the 2-3-4 tree.
// 
// root is passed a reference to the pointer to the current node in the 2-3-4
// tree.
//
// The function returns the number of nodes removed.
// ****************************************************************************
int Tree::remove_all(Node234 * & root)
{
   //Stops the recursive traversal of the current path down the tree if root is 
   //null and return 0 to the calling routine.
   if (!root)
       return 0;

   int count {0};

   //Traverses the left subtree. 
   count += remove_all(root->get_left());

   //Traverses the left-middle subtree.
   count += remove_all(root->get_left_middle());

   //Traverses the right-middle subtree
   count += remove_all(root->get_right_middle());

   //Traverses the right subtree.
   count += remove_all(root->get_right());
  
   //Deallocates the current node. 
   delete root;
   root = nullptr; 

   return count += 1;
}
