#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;  //pointer to the file descriptor

    //fopen is used to open a file in desired mode, r opens the file is read mode, if doesnt exist it return null
   if ((fptr = fopen("C:\\program.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

    //fcanf is used to read from a file
   fscanf(fptr,"%d", &num);

   printf("Value of n=%d", num);
   fclose(fptr);

   return 0;
}