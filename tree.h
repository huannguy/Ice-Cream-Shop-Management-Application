// *****************************************************************************
// Author:     Huan Nguyen
// Date:       05/17/2024
// Class:      CS 302
// Project:    Program Assignment #3
// File Name:  tree.h
// Purpose:    This file contains the interfaces for the Node234 and tree 
//             classes.
// *****************************************************************************

#include "hierarchy.h"
#include <memory>
#include <list>
#include <typeinfo>

using std::shared_ptr;
using std::unique_ptr;
using std::list;

//Interface for the 2-3-4 tree node.
class Node234
{
   public:
       Node234();                          //Constructor
       Node234(const Node234 & to_copy);   //Copy consntructor
       ~Node234();                       

       Node234 & operator=(const Node234 & to_copy);

       typedef unique_ptr<Dessert> data_ptr;
      
       int insert_data(data_ptr & to_add);
       bool is_full(void) const;
       bool is_leaf(void) const;

       int update_num_data_items(int to_update);
 
       int set_left(Node234 * new_left);
       int set_left_middle(Node234 * new_left_middle);
       int set_right_middle(Node234 * new_right_middle); 
       int set_right(Node234 * new_right); 

       Node234 * & get_left(void);
       Node234 * & get_left_middle(void);
       Node234 * & get_right_middle(void);
       Node234 * & get_right(void);
 
       data_ptr & get_data(int data_index);

   private:
       data_ptr data[3];
       Node234 * child[4];

       int num_data_items;
};


//Interface for the Tree class that will manage the collection of ice cream 
//dessert orders in a 2-3-4 tree.
class Tree
{
   public:
       Tree();                       //Constructor
       Tree(const Tree & to_copy);   //Copy constructor
       ~Tree();                      //Destructor

       //Overloaded assignment operator
       Tree & operator=(const Tree & src);

       typedef unique_ptr<Dessert> data_ptr;

       int insert(data_ptr & to_add);
       int find_order (int order_num) const;
       int display_all(void) const;
       int assess_total_sales(SalesStatistics & report) const;
       int remove_all(void);

  private:
       Node234 * root;

       int insert(Node234 * & root, data_ptr & to_add);
       int split_node(Node234 * & parent, Node234 * & child);
       int find_order (Node234 * root, int order_num) const;
       int display_all(Node234 * root) const;
       int assess_total_sales(Node234 * root, SalesStatistics & report) const;
       int deep_copy(Node234 * & dest_root, Node234 * src_root);
       int remove_all(Node234 * & root);

};

