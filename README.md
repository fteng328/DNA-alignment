DNA-alignment
=============

implementing a fast DNA-aligment algorithm





/*README for the sequence matching project*/
Owen Tao 996826564
Fei Teng 996842751

note: we used 1 slip day for this progarmming assignment

PartA:(can run seperately on PartA.c)

The program saves the kmers from 1 sequence and saves them in a (M-k+1)*k matrix. (This takes quadratic time and space for large k.) Then each kmer is taken and searched up in the other sequence and any match exact match in the kmer is detected. (O(n^2) running time) Upon detection of a match, the kmer is furthermore extented to both to the right or left, forming possibly longer-than-k kmer matches. The starting point and end points of these kmer matches on both sequences are stored in a linked list for part B.


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

PartC:
