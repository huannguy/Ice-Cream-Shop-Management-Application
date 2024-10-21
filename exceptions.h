// *****************************************************************************
// Author:     Huan Nguyen
// Date:       05/15/2024
// Class:      CS 302
// Project:    Program Assignment #3
// File Name:  exceptions.h
// Purpose:    This file contains the interfaces for various structs that
//             represent different exceptions that might arise.
// *****************************************************************************

#include <string>
using std::string;

//Interface for a struct to represent a missing information exception.
struct MISSING_INFO
{
   string error_msg {"Error: The item cannot be displayed due to "
                     "missing information."};
};


//Interface for a struct to represent an out of bounds exception.
struct OUT_OF_BOUNDS
{
   string error_msg {"Error: The specified index is out of the valid range."};
};



