//part A of the programming assignment - finding maximal matches

#include <stdio.h>

#define M 10
#define N 10
#define k 4

static int start1=0;
static int end1=0;
static int start2=0;
static int end2=0;

static char string2[N-1]="123abcdef";//[1,2,3,4,5,6,7,8,9];
static char string1[M-1]="abcdefghi";//=[11,12,13,123,4411,4,43,2,4,2,];


// given two strings, index all the k-long strings( and their locations, and then use the k-long strings in the other to query this index.


// whenever a match is found, we extend it in both directions to the first mismatch and return a tupple indicating positions of this maximal match in both sequences.)



main(){
    printf("start value is",start1,start2,end1,end2);
    
    char tempMatrix [M][k];
    int i=0;
    int j=0;int s =0;
    int flag = 0;
    
    printf("starting the loop\n");
    for (i=0;i<M-k;i++){
        
        for(j=0;j<=k-1;j++){
            
            tempMatrix[i][j] = string1[i+j];
            
        
        
        }
        
        printf("done inner loop\n");
    }


   
   
    //printf("done filling the matrix");
    for (i=0;i<M-k;i++){
        for (j=0;j<=k-1;j++)
            printf("%c",tempMatrix[i][j]);
        printf("\n");
    }
    printf("done\n"); 
    
    //printf("done printing the matrix");
    
    //extract a kmer from string1 and check with the k length subsquences in string2

    for(s=0;s<N-k;s++){
    printf("point1: s=%d,i=%d,j=%d,k=%d\n",s,i,j,k);
        for(i=0;i<N-k;i++){
    printf("point12: s=%d,i=%d,j=%d,k=%d\n",s,i,j,k);
            flag =0;
            for(j=0;j<=k-1;j++){
    printf("point123: s=%d,i=%d,j=%d,k=%d\n",s,i,j,k);
                if (tempMatrix[i][j] == string2[s+j]){
    printf("point1234: s=%d,i=%d,j=%d,k=%d\n",s,i,j,k);
                    flag = flag+1;
                    
                    if (flag == k-1){ // found a match
                        printf("found a match!!\n");
                        start2 = s;
                        end2 = s+k;
                        start1 = i;
                        end1 = i+k;
                       // extendleft(start1,start2);  //when we find a match with the k-long strings in string2 -> we should extend it in both directions to find max match
                       // extendright(end1,end2);

                        //the extendleft and extendright should call recursively until no extension possible

                        //now we want to store this tuple (x1,x2,y1,y2) in a linked list
                        printf("final value is x1:%d,y1:%d,x2:%d,y2:%d\n",start1,start2,end1,end2);
                    }
                    //else break;
                }
                
            }        
        }
    }

}

    

/*******
what happends when we find 2 match with the same length? or multiple match of the same length?

store all of them
*******/
extendright(a,b){
    if ((string1[a+1] ==string2[b+1])&& (a+1<= M-1)&& (b+1 <= N-1)){

        end1 =a+1;
        end2 = b+1;
        extendright(end1,end2);
    }

    return 0;

}

extendleft(a,b){
    if ((string1[a-1] ==string2[b-1]) && (a-1>=0) && (b-1 >=0)){

        start1 =a-1;
        start2 =b-1;
        extendleft(start1,start2);
    }
}
