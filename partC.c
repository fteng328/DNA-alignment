///the distance aligner not only compute the edit distance 
//but also reconstruct the full set of operations required to transform the strings(and print the alignments)
//#define M 10
//#define N 10
#define STOP 0
#define LEFT 1
#define UP 2
#define DIAG 3

#define MATCHSCORE 0
#define MISMATCHSCORE 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// this algorithm should take as input not only strings, but also ranges within the two strings in which to do the alignment

/*********
compute the edit distance

reconstruct the full set of operations required to transform te trings and print the alignments

takein: string1, string2, ranges x1,x2,y1,y2

***********/
/***S will return 0 if 2 letters are the same and 1 if they are different**/
int substitution(char a,char b){
    if (a == b) return 0;
    else return 1;
}

int max(int a, int b, int c){

    if (a>=b)
        if (a>=c)
            return a;

    if (b>=a)
        if(b>=c)
            return b;

    if(c>=a)
        if (c>=b)
            return c;

}



/*backtrace(int i, int j,int k){
   if (k<M+N){ 
          if( i>0 && j>0 && (distance[i][j] == distance [i-1][j-1]) ){ // this suggest a match between the two sequence
             alignB[k] = alighA[k] = A[i] = B[j];
             i=i-1;
             j=j-1;


          if(i>0 && j>0 && (distance[i][j] == distance[i-1][j-1] -1) ) //this suggest a mismatch
             alighB[k]= B[j];
             alighA[k]= A[i];
             i=i-1;
             j=j-1;

          if(j>0 && (distance[i][j] == distance[i][j-1] -1) )   // this suggest a insertion
             alignA[k] = "-";
             alignB[k] = B[j];
             j=j-1 ;
          if(i>0 && (distance[i][j] == distance[i-1][j] -1))    // this suggest a deletion
             alignA[k] = A[i];
             alighB[k] = "-";
             i=i-1 ;
    }

    if(i=0 && j =0)
        break;


}*/

edit_distance(char * X,char * Y, int x1,int x2, int y1, int y2)//,int a,int b, int c, int d)
{  //this function calculates the edit distance between 2 strings

    int i,j,k;
    //int maxDist,minI,minJ;
    int del,ins,sub;
    //int dist;
    //initialization

    int M ;
    M= x2-x1+1;
    int N ;
    N= y2-y1+1;
	char *A = malloc(sizeof(char)*(M+1));
    char *B = malloc(sizeof(char)*(N+1));
    strncpy(A, &(X[x1]), M);
    strncpy(B, &(Y[y1]), N);
    //printf("point3\n");

    int distance[M][N];    //create a MxN matrix where D(i,j) stores the  edit distance between A1....AM to B1.....BN
    /*int trace[M][N];  // create a matrix to store the pointers for backtracing */

    char alignA[M+N]; // aligned sequence for A
    char alignB[M+N]; // aligned sequence for B
    //printf("point4\n");
    for(i=0;i<M;i++)    distance[i][0] = -i;
    for(j=0;j<N;j++)    distance[0][j] = -j;
	//printf("point5\n");
    /*for(i=0;i<M;i++)    trace[i][0] = 0;
    for(j=0;j<N;j++)    trace[0][j] = 0;*/
	/*printf("point6\n");
    maxDist=0;
    minI=0;
    minJ=0;
    */


    //fill in the matrix

    for(i=1;i<M;i++){ //each i = i...M
        for (j= 1;j<N;j++){//each j = 1....N

            /******/
            //distance[0][0] =
            //dist = 0;
            //trace[i][j] = STOP;

            /********/
			printf("point6.1:   j= %d, i = %d\n",j,i);    
            del = distance[i-1][j] - 1;  //deletion penalty is 1
            //printf("point6.3\n");
			ins = distance[i][j-1] - 1;  // insertion penalty is 1
			//printf("point6.5:   j= %d, i = %d\n",j,i);            
			sub = distance[i-1][j-1] - substitution(A[i-1],B[j-1]);  // substitution penalty is 1
			printf("comparing %c, and %c\n",A[i-1],B[j-1]);
            printf("del is: %d, ins is: %d, sub is %d\n",del,ins,sub);
            //printf("point6.8:   j= %d, i = %d\n",j,i);    
            distance[i][j] = max (del, ins, sub);  // D(i-1,j)-1: deletion    ;    D(i,j-1)-1 : insertion   ;  M(i-1,j-1)-S(A[i],B[j]): substitution
			//printf("point6.9:   j= %d, i = %d\n",j,i);    

            printf("what is distance? ---------- %d\n",distance[i][j]);

            // store the trace matrix based on the different operations we perform
            /*if (distance[i][j] == del)
                trace[i][j] = LEFT;   // LEFT for insertion; DOWN for deletion; DIAG for substitution   

            if (distance[i][j] == ins)
                trace[i][j] = UP;     //DOWN
              
            if (distance[i][j] == sub)
                trace[i][j] = DIAG;    //DIAG
            */
      }
    }

    /****print the trace graph****/
    /*for(i=0;i<M;i++){
        for(j=0;j<N;j++){

            printf("%.2i.",abs(trace[i][j]));
        }
        printf("\n");
    } */  
    printf("\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){

            printf("%.2i.",(distance[i][j]));
        }
        printf("\n");
    }
	//printf("point8\n");
    //printf("minI = %d,minJ=%d\n",minI,minJ);
    //printf("maxDist is: %d\n",maxDist);
    //now we create aligned sequence alignA and alignB (in reverse order)

    i = M-1;  //start from the top right ie. backtrace
    j = N-1;  
    k = 0; // this is the index for the aligned sequence

    printf("start!\n");

    //backtrace(i,j,k);
    while (k<M+N){ 
        if( i>0 && j>0 && (distance[i][j] == distance [i-1][j-1]) ){ // this suggest a match between the two sequence
            
             alignB[k] = B[j-1];
             alignA[k] = A[i-1]; 
             i=i-1;
             j=j-1;
              k++;
        }

        if(i>0 && j>0 && (distance[i][j] == distance[i-1][j-1] -1) ){ //this suggest a mismatch
             
             alignB[k]= B[j-1];
             alignA[k]= A[i-1];
             i=i-1;
             j=j-1;
             k++;
        }
        if(j>0 && (distance[i][j] == distance[i][j-1] -1) ) {  // this suggest a insertion
             
             alignA[k] = '-';
             alignB[k] = B[j-1];
             j=j-1 ;
              k++;

        }
        if(i>0 && (distance[i][j] == distance[i-1][j] -1)){    // this suggest a deletion
             
             alignA[k] = A[i-1];
             alignB[k] = '-';
             i=i-1 ;
              k++;
        }
        if(i==0 && j ==0)
            break;
    }

    
    /* print in reverse order */
    printf("printing!\n");

    for(i=k-1;i>=0;i--) printf("%c",alignB[i]);
    //printf("%s",alignB);
    printf("\n");
    //printf("%s",alignA);
    for(i=k-1;i>=0;i--) printf("%c",alignA[i]);
    printf("\n");


}




main(){
	
    //char Y[50] = "ATCGGTATC";
    //char X[50] = "ATGAATCGT";

    char Y[50] = "TRACEBACK";
	char X[50] = "BACKTRACK";
	printf("point1");
	printf("point2\n");
	edit_distance(X,Y,0,9,0,9);
	printf("done");
}

/*************
performance: time: O(MN) ,space: O(MN); backtrack: O(N+M)


*****************/
