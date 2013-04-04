#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

typedef struct node{
    int x1;
    int x2;
    int y1;
    int y2;
    struct node *next;
} node;

void count_sort(node ** bucket, int exp, int k) {
    
    int count[10] = {0};
  int i, old_count, size;
	node ** temp = malloc(sizeof(node*) * k);
    

    for(i = 0; i < k; i++) {                      // k supplied by maximal match function; out and bucket are k entries large
        size = bucket[i]->x2 - bucket[i]->x1;
		count[size/exp %10]++;
	}

    int total = 0;
	
    for(i = 0; i < 10; i++) {						//count_sort is intended to be used by radix_sort, as such it is hard-coded to only accept 10 unique identifiers
        old_count = count[i];
        count[i] = total;
        total += old_count;
    }

    for(i = 0; i < k; i++) {
		size = bucket[i]->x2 - bucket[i]->x1;
        temp[count[size/exp % 10]] = bucket[i];
        count[size/exp % 10]++;
    }
	
	for(i = 0; i < k; i++) {
		bucket[i] = temp[i];
	}


	free(temp);

    return;
}

node** radix_count(int k, node * list) {
    
	int exp = 1;
	int i = 0;
	node * p = list;

	node ** bucket = malloc(sizeof(node*) * k);

	while (p!=NULL) {					//stash all of the linked lists into an array for easy processing by count_sort;
		bucket[i] = p;
		i++;
		p = p->next;
	}

	for(i = 0; i < 7; i++) {			// upper-threshold is 9,999,999 long genome
		count_sort(bucket, exp, k);
		exp *= 10;
	}
	return bucket;
}

int compare_nodes(node * node1, node * node2) {   // comparison function required by AVL tree library
	if (node1->x1 < node2->x1)
		return -1;
	else if (node1->x1 > node2->x1)
		return 1;
	else return 0;
}

avl_tree_t * make_anchor(int k, node ** bucket) {			//make anchor chain function

	avl_tree_t *tree = avl_alloc_tree(&compare_nodes, NULL);
	avl_node_t *avl_node, *next_avl_node, *prev_avl_node;
	node *next_node, *prev_node, *cur_node;
	int i = k;

	for(i = k-1; i >= 0; i--) {
		avl_node = avl_insert(tree, bucket[i]);				//always insert first to determine relation to rest of nodes
		if(avl_node != NULL) {
			cur_node = (node*) avl_node->item;
			next_avl_node = (node*) avl_node->next;
			if(next_avl_node) {
				next_node = (node*) next_avl_node->item;	//evaluate if there is inconsistency; if so, delete
				if (next_node)
			   		if(next_node->y1 < cur_node->y1)
						avl_delete(tree,bucket[i]);
			}
			prev_avl_node = avl_node->prev;
			if(prev_avl_node) {
				prev_node = (node*) avl_node->prev->item;
				if (prev_node)
			   		if( prev_node->y1 > cur_node->y1)
						avl_delete(tree,bucket[i]);
			}
		}
	}

	return tree;
}



void main() {

	node p1,p2,p3,p4,p5;
	avl_tree_t *tree;
	int i;
	int k = 5;

	p1.x1 = 0;
	p1.x2 = 2;
	p1.y1 = 0;
	p1.y2 = 2;
	p1.next = &p2;
	p2.x1 = 4;
	p2.x2 = 7;
	p2.y1 = 4;
	p2.y2 = 7;
	p2.next = &p3;
	p3.x1 = 9;
	p3.x2 = 12;
	p3.y1 = 8;
	p3.y2 = 11;
	p3.next = &p4;
	p4.x1 = 0;
	p4.x2 = 1;
	p4.y1 = 10;
	p4.y2 = 11;
	p4.next = &p5;
	p5.x1 = 4;
	p5.x2 = 5;
	p5.y1 = 5;
	p5.y2 = 6;
	p5.next = NULL;

	node ** bucket = malloc(sizeof(node*)*5);
	bucket [0] = &p1;
	bucket [1] = &p2;
	bucket [2] = &p3;
	bucket [3] = &p4;
	bucket [4] = &p5;


	count_sort(bucket, 1, k);
	printf("count_sort one's digit pass: ");
	for(i = 0; i < k; i++)
		printf("%d ", (bucket[i]->x2-bucket[i]->x1));

	printf("\n");

	count_sort(bucket, 10, k);
	printf("count_sort ten's digit pass: ");
	for(i = 0; i < k; i++)
		printf("%d ", (bucket[i]->x2-bucket[i]->x1));

	printf("\n");

	bucket = radix_count(k, &p1);			//important : sorter by Length of max matches
	printf("radix_sort sorted: ");
	for(i = 0; i < k; i++)
		printf("%d ", (bucket[i]->x2-bucket[i]->x1));

	printf("\n");

	tree = make_anchor(k, bucket); //important : makes the anchor tree.
	
	i = avl_count(tree);
	printf("number of nodes in tree:%d\n",i);

	free(bucket);

	return;
}

        
