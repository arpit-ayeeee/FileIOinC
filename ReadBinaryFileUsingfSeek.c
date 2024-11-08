#include <stdio.h>
#include <stdlib.h>

struct threeNum
{
   int n1, n2, n3;
};

int main()
{
   int n;
   struct threeNum num;
   FILE *fptr;

    //Opens file in binary mdoe for read
   if ((fptr = fopen("C:\\program.bin","rb")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   // Moves the cursor to the end of the file
   //fseek takes pointer to file, position of record to be found, offset where to start
   fseek(fptr, -sizeof(struct threeNum), SEEK_END);

    //read the records in file in reverse order
   for(n = 1; n < 5; ++n)
   {
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2, num.n3);


        //This function moves the file pointer fptr backward by 2 * sizeof(struct threeNum) bytes from its current position. The arguments are:
        // fptr: The file pointer to move.
        // -2 * sizeof(struct threeNum): The number of bytes to move back.
        // SEEK_CUR: The reference point is the current file pointer position.

        fseek(fptr, -2*sizeof(struct threeNum), SEEK_CUR);

        //This makes the file pointer go back by two structure sizes. Since fread had moved it forward by one structure size,
        //fseek will place the file pointer one structure size behind where it started before the fread.
   }
   fclose(fptr);

   return 0;
}