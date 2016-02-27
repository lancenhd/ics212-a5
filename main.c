/*****************************************************************
//
// NAME: Lancen Daclison
//
// HOMEWORK: 5
//
// CLASS: ICS 212
//
// INSTRUCTOR: Ravi Narayan
//
// DATE: February 25, 2015
//
// FILE: main.c
//
// DESCRIPTION: This file contains the driver that calls read and write functions.
// 
//
//****************************************************************/

#include <stdio.h>  
#include <string.h>
#include "iofunctions.h"  


/*****************************************************************
//
// Function name: main  
//
// DESCRIPTION: A driver that calls the readfile and writefile functions to read a file and write out to a file. 
//
// Parameters: argc (int) : holds the size of the argument used to access and start this program. 
// 
//             argv(char): this accepts character arrays such as what you need to start the program. Example: ./filename                
// Return values: 0 : success
// -1 : the value was not found
//
//****************************************************************/
int main(int argc, char*argv[])  
{ 
 /*can only copy three things*/
  struct account peopleInfo[3]; 
  int * numcust;
  char name[25];
  int accountno;   
  float balance; 
  int counter;
  int customerNum = 3;  

  printf("Hello, I'm going to start reading files now.\n\n");
  printf("Info Read: \n");  
  readfile(peopleInfo, numcust, "People_Info.txt");
  
  for(counter = 0; counter < 3; counter++)
  {
      strcpy(name,peopleInfo[counter].name);
      accountno = peopleInfo[counter].accountno;
      balance = peopleInfo[counter].balance; 
      printf("Name = %s\n Account Number = %d\n Balance = %.2f\n\n", name, accountno, balance);
} 
writefile(peopleInfo,customerNum,"Output.txt"); 
printf("Printing to Output.txt!...\n"); 
}
