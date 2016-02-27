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
// FILE: iofunctions.c
//
// DESCRIPTION: This file contains the driver that calls read and write functions.
// 
//
//****************************************************************/

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include "iofunctions.h" 

/*****************************************************************
//
// Function name: readfile 
//
// DESCRIPTION: Reads the information inside a file using a while loop. 
//
// Parameters: accarray(struct account[]) : This is the a structure to hold the account of each person.  
// 
//             numcust(int*): This is the number of customers 
//
//             filename(char[]): This is used to hold the name of a file.  
// 
// Return values: 0 : success
// -1 : the value was not found
//
//****************************************************************/

 int readfile( struct account accarray[], int* numcust, char filename[])
{
   /* variables */

    FILE *inputFile; 
    char line[25]; 
    char name[25]={"\0"}; 
    int accountNum;
    float money ;  
    
    inputFile = fopen("People_Info.txt", "r"); 
    if(inputFile == NULL)
    {  
       fprintf(stderr, "Sorry, I cannot open this file. Also it's empty.\n");
       exit(1);   
    } 
    

/*outer loop is to check if file is not null*/
     while(!feof(inputFile))
     {
       /*while file has something*/
       /*can only copy 3 things */ 
        while(fscanf(inputFile,"%s %d %f", name,&accountNum,&money)== 3)
        {
           strcpy(accarray->name,name);  
           accarray->accountno = accountNum;
           accarray->balance = money; 
           accarray = accarray + 1; 

          /*  printf("name = %s number = %d balance = %f\n", name, accountNum, money); */   
         } 
                
      } 

      fclose(inputFile); 
      return 0;

}



/*****************************************************************
//
// Function name: writefile 
//
// DESCRIPTION: Writes out to a file. Ideally should print out the final revisions of a file and overwrites the file. However, this just prints out whatever is in the file. 
// 
//
// Parameters: accarray(struct account[]) : This is the a structure to hold the account of each person.  
// 
//             numcust(int): This is the number of customers 
//
//             filename(char[]): This is used to hold the name of a file.  
// 
// Return values: 0 : success
// -1 : the value was not found
//
//****************************************************************/
void writefile(struct account accarray[], int numcust, char filename[]) 
{ 
  FILE *outputFile;
  int  counter;    

 outputFile = fopen("OutputFile.txt", "w");  

  if(outputFile == NULL)
  {  
       fprintf(stderr, "Sorry, I cannot open this file. Also it's empty.\n");
  }  
 
     while(counter < numcust)
     {
         fprintf(outputFile, "%s %d% f\n", accarray[counter].name, accarray[counter].accountno,accarray[counter].balance);
         counter++;
        /* printf("name = %s number = %d balance = %f\n", name, accountNum, money);  */ 
      } 
       
   fclose(outputFile);                


}

