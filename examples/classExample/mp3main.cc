//
// mp3main.cc
// 
// Author: Barrett
// Date  : 1/10/2013
//
// Main program to try out the mp3 class
//   and to show various other C/C++ stuff


// Include system header files before yours
#include <string>   // C++ string class
#include <iostream> // C++ keyboard and screen i/o
#include <vector>   // One of the C++ STL classes
#include <fstream>  // C++ file i/o
#include <string.h> // C strings - not the same as <string>
#include <stdlib.h> // C standard library

// Include once
#ifndef MP3_H
#include "mp3.h"
#endif

// Shortcut for the regular namespace
using namespace std;

// Precompiler constant: no semicolon
#define LENGTH 20

// C++ constant
const int FILESIZE = 100;

// Function prototype
int writeToFile( fstream&, mp3* );

// Main program
// Note the parameters:
// int argc: number of command line parameters, argc >= 1
// char** argv: array of char* strings containing the command line parameters

int main( int argc, char** argv ) {

   vector<mp3> list;  // STL list of mp3 objects
   mp3 entry1;        // One object
   mp3* entry2;       // Pointer to another object
   char name[LENGTH]; // Old style C string
   double size;       // File size
   fstream f;         // Output file

   // Set the data
   // Note: entry1 is an automatic variable, off the stack
   entry1.setTitle( "Urn Fog" );
   entry1.setFilesize( FILESIZE );

   // Enter entry1 on list; could also use insert( )
   list.push_back( entry1 );

   // Display it; could also use front() or back( )
   cout << list[0].toString( ) << endl;

   // Copy a literal into a C string
   //   - note the last parameter is one less than name's length
   // Other C string functions:
   // strcmp( a, b ) returns 0 if equal, negative if a < b,
   //    positive if a > b
   // strlen( a ) returns length of a
   strncpy( name, "Monkey Rides a Dog", LENGTH-1 );

   // This puts a char* into a string object
   //   Could have instead done: str = name;
   //   To get it out, use str.c_str(), as in
   //   strncpy( name, str.c_str(), str.length() );
   string str(name);

   // Ask for the file size
   cout << "Enter the file size: ";
   cin  >> size;

   // Create a new mp3 with overloaded constructor
   // Note: entry2 is a pointer to an mp3, so memory must
   //    be allocated for it off the heap
   //    - but it's NOT null beforehand
   entry2 = new mp3( str, size );
   
   // Write entry2 stuff to a file
   if ( writeToFile( f, entry2 ) == -1 ) {
      cout << "File write failed" << endl;
   }

   return 0;

} // main( )

int writeToFile( fstream& f, mp3* mymp ) {

   // For practice, open an output file
   // Options:
   //    fstream::out             for write, kills existing file
   //    fstream::in              for read-only
   //    fstream::in | ios::out   for read/write
   //    fstream::binary          for binary access
   f.open("testfile", fstream::out);

   // Always check that the file opened correctly
   if ( !f ) {
      // f.open( ) failed
      cout << "testfile failed on open" << endl;
      return -1;
   } else {
      // C++ file output using getters from mp3 class
      f << "Title = " << mymp->getFilesize( ) << endl;
      f << "Size  = " << mymp->getTitle( ) << endl;
      f.close( );
   }
   
   return 0;
}
