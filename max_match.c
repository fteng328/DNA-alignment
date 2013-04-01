//part A of the programming assignment - finding maximal matches

#include <stdio.h>

#define M 10
#define N 10
#define k 5



// given two strings, index all the k-long strings( and their locations, and then use the k-long strings in the other to query this index.


// whenever a match is found, we extend it in both directions to the first mismatch and return a tupple indicating positions of this maximal match in both sequences.)



main(){

    char string2[N-1]="123456789";//[1,2,3,4,5,6,7,8,9];
    char string1[M-1]="abcdefghi";//=[11,12,13,123,4411,4,43,2,4,2,];
    char tempMatrix [M-1][k-1];
    int i=0;
    int j=0;
    
    while (i != M-1){
        while (j!=(k-1)){
        tempMatrix[i][j] = string2[i+j]; 
        printf("stroring!: i= %d, j=%d\n",i,j);
        j++;
        }
        j=0;
        i++;
        printf("done inner loop\n");
    }
    //printf("done filling the matrix");

    
    for (i=0;i<M;i++){
        for (j=0;j<k;j++)
            printf("%c,",tempMatrix[i][j]);
        printf("\n");
    }
    printf("done\n");  
    //printf("done printing the matrix");
}
