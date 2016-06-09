# Sort one million number
------------------------------------

# Problem: 
Write a program in any programming language of your preference to sort 1
million of signed 32-bit integers using 3 MB of memory.

# Description:
This program's job is sort 1 million of signed 32-bit intergers using 3MB of memory. It reads from standard input and write to standard output (input/output format will be described below). 
This program is compiled by gcc 5.2.1 and is tested in Ubuntu 15.06. It could be compiled by other compiler and run in other OS.

# Input/Output format:
Input and output contain 1 million lines. Each line contains 1 signed 32-bit intergers number.

# Requirements:
- GCC 5.2.1 or newer.

# How to  build and run:
To manually build and run this project, you must have all requirments installed.

1. Run `gcc -o sort sort.c` in this project folder.
2. Run `./sort` to run this project.

# Why I choose quicksort:
Even in the worst case, time complexity of Quicksort is O(n^2) but this case is rarely. In real world, Quicksort usually runs faster than other efficient sorting algorithm (Heapsort and Merge sort). A good reason for this is because it is relatively cache-efficient.

In worst case, space complexity of Quicksort is O(logn). But when I test this program with some input, it only consumes about 2700 kbytes, very far from limit of 3072 kbytes so it isn't a big problem.
