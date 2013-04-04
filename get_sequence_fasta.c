
#include<stdio.h>
int main(){
//store kmer size
k= argv[3];

char mystring1 [10000000000];
char mystring2 [10000000000];

FILE* fp = fopen(argv[1], "r");  // open the fasta file
if (fp == NULL) perror ("Error opening file");
   else {
     if ( fgets (mystring1 , 10000000000 , fp) != NULL )
       puts (mystring1);
     fclose (fp);
   }

FILE* pFILE = fopen(argv[2], "r");  // open the fasta file
if (pFile == NULL) perror ("Error opening file");
   else {
     if ( fgets (mystring2 , 10000000000 , pFile) != NULL )
       puts (mystring2);
     fclose (pFile);
   }


}
