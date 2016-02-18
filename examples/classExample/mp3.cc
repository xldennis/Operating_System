
// class mp3
//   Implementation of the mp3 class for
//     (very) simple modeling of mp3 files
//
// Author: Barrett
// Date  : 1/10/2013
//


// Include system header files before yours
// String class
#include <string>
// C i/o class - for sprintf( )
#include <stdio.h>

// Include mp3 definition exactly once
#ifndef MP3_H
#include "mp3.h"
#endif

// Default constructor
mp3::mp3() {
   title = "";
   filesize = 0.0;
} // mp3( )

// Overloaded constructor
mp3::mp3( string aTitle, double aFilesize ) {

   // Set the mp3 file name
   title = aTitle; // or: this->title = aTitle;

   // Safe set for file size
   if ( aFilesize > 0.0 ){
      filesize = aFilesize;
   } else {
      filesize = 0.0;
   } // if

} // mp3( )

// Getters
string mp3::getTitle( ) {
   return title;
} // getTitle( )

double mp3::getFilesize( ) {
   return filesize;
}

//Setters
void   mp3::setTitle( string aTitle ) {
   title = aTitle;
} // setTitle( )

void   mp3::setFilesize( double aFilesize ) {
   if ( aFilesize > 0.0 ){
      filesize = aFilesize;
   } else {
      filesize = 0.0;
   }
} // setFilesize( )

// Conver to string
string mp3::toString( ) {

   char s1[20], s2[20]; // C strings

   // Stupid C tricks
   // It's just as stupid in C++
   // Formatted print to a C string
   sprintf(s1, "%f", filesize);
   sprintf(s2, "%f", computeDownloadTime());
   
   // Convert to string objects
   string str1(s1);
   string str2(s2);

   // Construct the whole string
   string str = "Title: \t" + title + 
                "\nFilesize: \t" + str1 +
                "\nApproximate download time (at 3 MB/sec): " +
                str2 + "\n";
   return str;
} // toString( )

// Private computation of download time
double mp3::computeDownloadTime( ) {
   return( filesize/mp3::DOWNLOADTIME ); 
} // computeDownloadTime( )

