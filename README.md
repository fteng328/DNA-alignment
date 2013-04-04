
/******README for the sequence matching project*********/

DNA-alignment - fastmatch
=============
Implementing a fast DNA-aligment algorithm

Owen Tao 996826564
Fei Teng 996842751

please note: we used 1 slip day for this programming assignment
no bonus parts were achevied
/********************************************************/

PartA:(can run seperately on PartA.c)

The program calculates the kmers from 1st sequence and saves them in a (M-k+1)*k matrix. (This takes up to O(M*k) and O(M*k)space for large k.) Then each kmer is taken and searched up in the other sequence and any match exact match in the kmer is detected. (this will take O(n^2) running time, where n is upper bound length of both sequences) Upon detection of a match, the kmer is furthermore extented to both to the right or left, forming possibly longer-than-k kmer matches.(This is linear time) The starting point and end points of these kmer matches on both sequences are stored in a linked list for part B. 

Overall running time: (O(n^2))
Overall space : O(n*k)


PartB:(can run seperately on partb.c including avl.c avl.h)

The Anchor selection takes the input from the Maximal Match subproblem, which is a linked list of maximal match nodes consisting of start and endpoints of the matches in their respective strings. 
Part B implementation consists of two function calls, radix_sort and make_anchor. Radix_sort is an implementation of the radix
sorting algorithm consisting of repeated calls to the counting sort algorithm helper function. It sorts the linked list of maximal matches into an array containing the nodes by order of length of match. 
This sets up the next function for the greedy approach required by this project. Make_anchor makes use of the AVL-tree data structure in order to consistently insert and delete nodes.
The O(logn) insertion and deletion times of AVL trees allow easy access and efficient determination of maximal match consistency problems just by comparing the start points of consecutive matches.

As a result of the O(logn) AVL operation time over n interations through the length-sorted maximal match array, the running time of this section is O(nlogn).
This dominates the O(n) running time of the sorting algorithm (O(3n+10) of counting sort * O(7) of radix count => O(n)).
Lastly, the AVL tree library used can be found here: https://github.com/haiwen/seafile/blob/master/common/avl
Acknowledgements to Michael H Buselli and Wessel Dankers for the AVL library.

PartC:(can run sepreately on partC.c)

We compute the edit distance and store it in a M x N matrix.  The algorithm to calculate the edit distance stricly follows the assignment handout ie. max of distance score when we assign a penalty score of -1 to mismatch and 0 to match. ( This takes MxN space and running time is 3MxN, thus quadratic running time)

For backtracing, we can deduce what operation was taken at each of the indices of the original sequences by just looking at the distance matrix and modify our output sequence accordingly. This takes 2(N+M) memory for the new allocated string to store the aligned sequences and take O(n^2) time to look in every element in the distance matrix (this could be inproved such that we only look at the elements that are being pointed by the last element in the backtrace list)

Overall running time: (O(n^2))
Overall space : O(n^2)


