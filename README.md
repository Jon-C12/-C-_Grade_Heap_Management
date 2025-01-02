This project requires designing and implementing a C program that leverages dynamic memory management to process and analyze a stream of grades inputted by the user or redirected from a file. The program will demonstrate knowledge of heap memory, pointers, and dynamic memory allocation and deallocation by dynamically storing grades on the heap as they are entered. The input process continues until a sentinel value (a negative number) is encountered, which signals the end of input. The sentinel value itself will not be stored or included in calculations.

The program must calculate the average of all valid grades and determine which grades are greater than or equal to the average and which are below it. To ensure proper memory management, the program will allocate an initial block of memory on the heap for five grades and expand it as necessary to accommodate additional input, using dynamic memory allocation techniques. If no valid grades are inputted (i.e., the first value is a sentinel), the program will output an appropriate message without allocating any heap memory.

The implementation will include a memory map printed at various stages of execution, showing how the heap is used and providing insight into dynamic memory usage. The program must also employ best practices to avoid memory leaks, using tools such as valgrind to verify proper deallocation of all allocated memory. This project enhances understanding of the heap, pointers, arrays, and dynamic memory management while reinforcing fundamental programming concepts such as loops, conditionals, and function usage.

Test Cases:

./proj2.out
Enter a list of grades below where each grade is separated by a newline character.
After the last grade is entered, enter a negative value to end the list.
-2.5
The average of 0 grades is 0.000000.
total heap usage: 0 allocs, 0 frees, 0 bytes allocated

./proj2.out
Enter a list of grades below where each grade is separated by a newline character.
After the last grade is entered, enter a negative value to end the list.
97.5
Allocated 40 bytes to the heap at 0x8d8010.
Stored 97.500000 in the heap at 0x8d8010.
-12.5
The average of 1 grades is 97.500000.
1. The grade of 97.500000 is >= the average.
Freed 40 bytes from the heap at 0x8d8010.
total heap usage: 1 allocs, 1 frees, 40 bytes allocated

./proj2.out
Enter a list of grades below where each grade is separated by a newline character.
After the last grade is entered, enter a negative value to end the list.
85.4
Allocated 40 bytes to the heap at 0xb94010.
Stored 85.400000 in the heap at 0xb94010.
28.5
Stored 28.500000 in the heap at 0xb94018.
98.75
Stored 98.750000 in the heap at 0xb94020.
100.0
Stored 100.000000 in the heap at 0xb94028.
0
Stored 0.000000 in the heap at 0xb94030.
Stored 5 grades (40 bytes) to the heap at 0xb94010.
Heap at 0xb94010 is full.
Allocated 80 bytes to the heap at 0xb94040.
Copied 5 grades from 0xb94010 to 0xb94040.
Freed 40 bytes from the heap at 0xb94010.
-2
The average of 5 grades is 62.530000.
1. The grade of 85.400000 is >= the average.
4
2. The grade of 28.500000 is < the average.
3. The grade of 98.750000 is >= the average.
4. The grade of 100.000000 is >= the average.
5. The grade of 0.000000 is < the average.
Freed 80 bytes from the heap at 0xb94040.
total heap usage: 2 allocs, 2 frees, 120 bytes allocated

./proj2.out
Enter a list of grades below where each grade is separated by a newline character.
After the last grade is entered, enter a negative value to end the list.
78
Allocated 40 bytes to the heap at 0x1c82010.
Stored 78.000000 in the heap at 0x1c82010.
99
Stored 99.000000 in the heap at 0x1c82018.
100
Stored 100.000000 in the heap at 0x1c82020.
-1
The average of 3 grades is 92.333333.
1. The grade of 78.000000 is < the average.
2. The grade of 99.000000 is >= the average.
3. The grade of 100.000000 is >= the average.
Freed 40 bytes from the heap at 0x1c82010.
total heap usage: 1 allocs, 1 frees, 40 bytes allocated

./proj2.out
Enter a list of grades below where each grade is separated by a newline character.
After the last grade is entered, enter a negative value to end the list.
92.3
Allocated 40 bytes to the heap at 0x104c010.
Stored 92.300000 in the heap at 0x104c010.
88.7
Stored 88.700000 in the heap at 0x104c018.
56
Stored 56.000000 in the heap at 0x104c020.
78
Stored 78.000000 in the heap at 0x104c028.
45.7
Stored 45.700000 in the heap at 0x104c030.
Stored 5 grades (40 bytes) to the heap at 0x104c010.
Heap at 0x104c010 is full.
Allocated 80 bytes to the heap at 0x104c040.
Copied 5 grades from 0x104c010 to 0x104c040.
Freed 40 bytes from the heap at 0x104c010.
100.00
Stored 100.000000 in the heap at 0x104c068.
-5.6
The average of 6 grades is 76.783333.
1. The grade of 92.300000 is >= the average.
2. The grade of 88.700000 is >= the average.
3. The grade of 56.000000 is < the average.
4. The grade of 78.000000 is >= the average.
5. The grade of 45.700000 is < the average.
6. The grade of 100.000000 is >= the average.
Freed 80 bytes from the heap at 0x104c040.
total heap usage: 2 allocs, 2 frees, 120 bytes allocated

./proj2.out
Enter a list of grades below where each grade is separated by a newline character.
5

After the last grade is entered, enter a negative value to end the list.
99.2
Allocated 40 bytes to the heap at 0x85a010.
Stored 99.200000 in the heap at 0x85a010.
88.3
Stored 88.300000 in the heap at 0x85a018.
45.3
Stored 45.300000 in the heap at 0x85a020.
0
Stored 0.000000 in the heap at 0x85a028.
0
Stored 0.000000 in the heap at 0x85a030.
Stored 5 grades (40 bytes) to the heap at 0x85a010.
Heap at 0x85a010 is full.
Allocated 80 bytes to the heap at 0x85a040.
Copied 5 grades from 0x85a010 to 0x85a040.
Freed 40 bytes from the heap at 0x85a010.
72.5
Stored 72.500000 in the heap at 0x85a068.
98.3
Stored 98.300000 in the heap at 0x85a070.
44.5
Stored 44.500000 in the heap at 0x85a078.
0
Stored 0.000000 in the heap at 0x85a080.
0
Stored 0.000000 in the heap at 0x85a088.
Stored 10 grades (80 bytes) to the heap at 0x85a040.
Heap at 0x85a040 is full.
Allocated 120 bytes to the heap at 0x85a0a0.
Copied 10 grades from 0x85a040 to 0x85a0a0.
Freed 80 bytes from the heap at 0x85a040.
43.7
Stored 43.700000 in the heap at 0x85a0f0.
56.3
Stored 56.300000 in the heap at 0x85a0f8.
0
Stored 0.000000 in the heap at 0x85a100.
-2
The average of 13 grades is 42.161538.
1. The grade of 99.200000 is >= the average.
2. The grade of 88.300000 is >= the average.
3. The grade of 45.300000 is >= the average.
4. The grade of 0.000000 is < the average.
5. The grade of 0.000000 is < the average.
6. The grade of 72.500000 is >= the average.
7. The grade of 98.300000 is >= the average.
8. The grade of 44.500000 is >= the average.
9. The grade of 0.000000 is < the average.
10. The grade of 0.000000 is < the average.
11. The grade of 43.700000 is >= the average.
12. The grade of 56.300000 is >= the average.
13. The grade of 0.000000 is < the average.
Freed 120 bytes from the heap at 0x85a0a0.
total heap usage: 3 allocs, 3 frees, 240 bytes allocated

