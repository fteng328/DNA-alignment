//part A of the programming assignment - finding maximal matches
#include <stdlib.h>
#include <stdio.h>

#define M 10
#define N 10
#define k 3



struct node{
    int x1;
    int x2;
    int y1;
    int y2;
    struct node *next;

}*head;


static int start1=0;
static int end1=0;
static int start2=0;
static int end2=0;

static char string2[N]="abc0abcdef";//[0,1,2,3,4,5,6,7,8,9];
static char string1[M]="abcdefghij";//=[11,12,13,123,4411,4,43,2,4,2,];


// given two strings, index all the k-long strings( and their locations, and then use the k-long strings in the other to query this index.


// whenever a match is found, we extend it in both directions to the first mismatch and return a tupple indicating positions of this maximal match in both sequences.)


/******HELPER FUNCTIONS**********/

extendright(int a,int b){
    if ((string1[a+1] == string2[b+1]) && (a+1<= M-1) && (b+1 <= N-1)){

        end1 = a+1;
        end2 = b+1;
        extendright(end1,end2);
    }

    return 0;

}

extendleft(int a,int b){
    if ((string1[a-1] ==string2[b-1]) && (a-1>=0) && (b-1 >=0)){

        start1 =a-1;
        start2 =b-1;
        extendleft(start1,start2);
    }
}


void append(int a,int b, int c, int d)
{
    struct node *temp,*right;
    printf("im heser\n");
    temp= (struct node *)malloc(sizeof(struct node));
    printf("im 1\n");
    temp->x1=a;
    temp->x2=b;
printf("im 2\n");
    temp->y1=c;
printf("im 5\n");
    temp->y2=d;
    right=(struct node *)head;
printf("im 7\n");
    while(right->next != NULL)
printf("im 7.6\n");
    right=right->next;
printf("im 7.7\n");
    right->next =temp;
printf("im 8\n");
    right=temp;
    right->next=NULL;
}
    
void display(/*struct node *r*/)
{
    struct node * r;
    r=head;
    if(r==NULL)
    {
    return;
    }
    while(r!=NULL)
    {
    printf("x1:%d,x2:%d,y1:%d,y2:%d ",r->x1,r->x2,r->y1,r->y2);
    r=r->next;
    }
    printf("\n");
}

void add( int a,int b, int c, int d )
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->x1=a;
    temp->x2=b;
    temp->y1=c;
    temp->y2=d;
    if (head== NULL)
    {
    head=temp;
    head->next=NULL;
    }
    else
    {
    temp->next=head;
    head=temp;
    }
}

/******************/






main(){
    printf("start value is",start1,start2,end1,end2);
   // struct node *n;
    char tempMatrix [M-k+1][k];
    int i=0;
    int j=0;int s =0;
    int flag = 0;
    
   // printf("starting the loop\n");
    for (i=0;i<M-k+1;i++){
        
        for(j=0;j<k;j++){
            
            tempMatrix[i][j] = string1[i+j];
            
        
        
        }
        
       // printf("done inner loop\n");
    }

   
    for (i=0;i<M-k+1;i++){
        for (j=0;j<k;j++)
            printf("%c",tempMatrix[i][j]);
        printf("\n");
    }
    
    //extract a kmer from string1 and check with the k length subsquences in string2

    for(s=0;s<N-k+1;s++){
        for(i=0;i<N-k+1;i++){
            flag =0;
            for(j=0;j<=k-1;j++){
                if (tempMatrix[i][j] == string2[s+j]){
  //  printf("looking at %c",string2[s+j]);
                    flag = flag+1;
                    
                    if (flag == k){ // found a match

                        start2 = s;
                        end2 = s+k-1;
                        start1 = i;
                        end1 = i+k-1;
                        extendleft(start1,start2); //when we find a match with the k-long strings in string2 -> we should extend it in both directions to find max match
                        extendright(end1,end2);

                        //the extendleft and extendright should call recursively until no extension possible

                        //now we want to store this tuple (x1,x2,y1,y2) in a linked list

                        add(start1,end1,start2,end2); //storing each tuple in a linked-list
                    }
                    //else break;
                }
                
            }
        }
    }
    printf("displaying L-list");
    display();
}
