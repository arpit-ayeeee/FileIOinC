#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr; //pointer to file

   // fopen is used to create/open file based on the mode given in second parameter
   // w opens the file in wriite mode if doesnt exist the creates one
   fptr = fopen("D:\\SystemDesign\\FileIOinC\\testFile.text","w");

   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }

   printf("Enter num: ");
   scanf("%d",&num);

    //fprintf is used to write to a text file
   fprintf(fptr,"%d",num);

   //fclose is used to close a file
   fclose(fptr);

   return 0;
}