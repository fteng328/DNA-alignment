///the distance aligner not only compute the edit distance 
//but also reconstruct the full set of operations required to transform the strings(and print the alignments)
#define M 100
#define N 100
#define LEFT 1;
#define DOWN 2;
#define DIAG 3;

// this algorithm should take as input not only strings, but also ranges within the two strings in which to do the alignment

/*********
compute the edit distance

reconstruct the full set of operations required to transform te trings and print the alignments

takein: string1, string2, ranges x1,x2,y1,y2

***********/



edit_distance(char * A,char * B)//,int a,int b, int c, int d)
{  //this function calculates the edit distance between 2 strings

    int i,j,k;
    int minDistance,minI,minJ;
    int del,ins,sub;
    //initialization
    int distance[M][N];    //create a MxN matrix where D(i,j) stores the  edit distance between A1....AM to B1.....BN
    int trace[M][N]  // create a matrix to store the pointers for backtracing 

    char alignA[M+N]; // aligned sequence for A
    char alignB[M+N]; // aligned sequence for B
    
    for(i=0;i<M;i++)    distance[i,0] = 0;
    for(j=0;j<N;j++)    distance[0,j] = 0;

    for(i=0;i<M;i++)    trace[i,0] = 0;
    for(j=0;j<N;j++)    trace[0,j] = 0;

    minDist=0;
    minI=0;
    minJ=0



    //fill in the matrix

    for(i=0;i<M;i++){ //each i = i...M
        for (j= 0;i<N;j++){//each j = 1....N
            del = distance(i-1,j)-1;  //deletion
            ins = distance(i,j-1)-1;  // insertion
            sub = distance(i-1,j-1)-Sub(A[i],B[j])  // substitution
            distance[i,j] = max (del, ins, sub);  // D(i-1,j)-1: deletion    ;    D(i,j-1)-1 : insertion   ;  M(i-1,j-1)-S(A[i],B[j]): substitution


               // store the trace matrix based on the different operation we perform
            if (distance[i,j] = del)
                trace(i,j)= (LEFT);   // LEFT for insertion; DOWN for deletion; DIAG for substitution   

            if (distance[i,j] = ins)
                trace(i,j)= (DOWN);
              "gatggtccgatcaatctacgatcggggctctaaatatatatatatacgctacgatcg"
            if (distance[i,j] = sub)
                trace(i,j)= (DIAG);

            if(distance[i,j]<minDist) { /* keep track of where the minimum score is */
                minDist=distance[i,j];
	            minI=i;
	            minJ=j;
	        }

      }
    }

    //now we create aligned sequence alignA and alignB (in reverse order)

    i = M;  //start from the top right ie. backtrace
    j = N;  
    k = 0; // this is the index for the aligned sequence

    /* unaligned ends */

    while(i>minI) {
    alignB[k]='-';
    alignA[k]=A[i-1];"gatggtccgatcaatctacgatcggggctctaaatatatatatatacgctacgatcg"
    i--;
    k++;
    }

    while(j>minJ) {
    alignB[k]=B[j-1];
    alignA[k]='-';
    j--;
    k++;
    }

    /*matched or unmatched sequence*/
    while(trace[i][j] != 0) {

        if(trace[i][j] == DIAG) {
	        alignB[k]=B[j-1];
	        alignA[k]=A[i-1];
	        i--;
	        j--;
	        k++;
        }
        else if(trace[i][j] == LEFT) {
	        alignB[k]=B[j-1];
	        alignA[k]='-';
	        j--;
	        k++;
        }
        else if(trace[i][j] == UP) {
	        alignB[k]='-';
	        alignA[k]=A[i-1];
	        i--;
	        k++;
        }

    }

    /* unaligned beginning */

    while(i>0) {
        alignB[k]='-';
        alignA[k]=A[i-1];
        i--;
        k++;
    }

    while(j>0) {
        alignB[k]=B[j-1];
        alignA[k]='-';
        j--;
        k++;
    }

    /* print in reverse order */

    for(i=k-1;i>=0;i--) printf("%c",alignB[i]);
    printf("\n");
    for(i=k-1;i>=0;i--) printf("%c",alignA[i]);
    printf("\n");


}


/***S will return 0 if 2 letters are the same and 1 if they are different**/
int Sub(char a,char b){
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
            return b;


}

main(){
  char Y[N-1] = "gatggtccgatcaatctacgatcggggctctaaatatatatatatacgctacgatcg";
  char X[M-1] = "gatggtccgatcaatctacgatcggaactctatatatagatatctacgctacgatcg";
edit_distance(X,Y,)

}

/*************
performance: time: O(MN) ,space: O(MN); backtrack: O(N+M)


************/
