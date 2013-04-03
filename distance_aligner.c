///the distance aligner not only compute the edit distance 
//but also reconstruct the full set of operations required to transform the strings(and print the alignments)



// this algorithm should take as input not only strings, but also ranges within the two strings in which to do the alignment

/*********
compute the edit distance

reconstruct the full set of operations required to transform te trings and print the alignments

takein: string1, string2, ranges x1,x2,y1,y2

***********/

edit_distance(char * A,char * B,int a,int b, int c, int d){  //this function calculates the edit distance between 2 strings
//create a MxN matrix where D(i,j) stores the  edit distance between A1....AM to B1.....BN

//initialization
int distance[M][N];
distance[i,0] = i;
distance[0,j] = j;

//recurrence relation

   for each i = i...M
        for each j = 1....N
            distance[i,j] = max (D(i-1,j)-1, D(i,j-1)-1,M(i-1,j-1)-S(A[i],B[j]))


        D()



}



int S(a,b){
if (a == b) return 0;
else return 1;
}


