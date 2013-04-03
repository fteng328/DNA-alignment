///the distance aligner not only compute the edit distance 
//but also reconstruct the full set of operations required to transform the strings(and print the alignments)



// this algorithm should take as input not only strings, but also ranges within the two strings in which to do the alignment

/*********
compute the edit distance

reconstruct the full set of operations required to transform te trings and print the alignments

takein: string1, string2, ranges x1,x2,y1,y2

***********/

edit_distance(char * A,char * B,int a,int b, int c, int d){  //this function calculates the edit distance between 2 strings

    int i,k;
    //initialization
    int distance[M][N];    //create a MxN matrix where D(i,j) stores the  edit distance between A1....AM to B1.....BN
    for(i=0;i<M;i++)    
        distance[i,0] = 0;
    for(j=0;j<N;j++)    
        distance[0,j] = 0;

    //fill in the matrix

    for(i=0;i<M;i++) //each i = i...M
        for (j= 0;i<N;j++)//each j = 1....N
            distance[i,j] = max (D(i-1,j)-1, D(i,j-1)-1,M(i-1,j-1)-S(A[i],B[j]))


    //backtracing to get the alignment between 2 strings


    



}


/***S will return 0 if 2 letters are the same and 1 if they are different**/
int S(char a,char b){
if (a == b) return 0;
else return 1;
}


