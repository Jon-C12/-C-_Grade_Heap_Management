#include <stdio.h>
#include <stdlib.h>

/* 
 * The main function takes in users grades when seperated with a newline, 
 * and allocates the grades on the heap dynamically. The program 
 * initially allocates space for 5 grade and expands when it is needed.
 * It then calculates the avergae of the grades entered, and provides
 * details like our heap usage, how much memory is allocated, and 
 * specifical memory addresses.
 */


int main() {
    int gradeCount = 0;
    int storage = 0;
    int allocCount = 0;
    int freeCount = 0;
    unsigned int totalAllocatedBytes = 0;
    double totalGrade = 0.0;
    double grade;
    double * grades = NULL; 

    //Prompting user.
    printf("Enter a list of grades below where each grade is separated by a newline character.\n");
    printf("After the last grade is entered, enter a negative value to end the list.\n");

    int continueReading = 1;
    while (continueReading) {
        scanf("%lf", &grade);
        if (grade < 0) {
            continueReading = 0; 
        } else {
	  //Allocating memory if needed.
            if (storage == 0) {
                storage = 5;
                grades = (double *)malloc(storage * sizeof(double));
		
                allocCount++; 
                totalAllocatedBytes += storage * sizeof(double); 
                printf("Allocated %ld bytes to the heap at %p.\n", storage * sizeof(double), (void *)grades);
            }
	    
	    //Store and update our entered grades in array.
            *(grades + gradeCount) = grade;
            totalGrade += grade;

            printf("Stored %.6f in the heap at %p.\n", grade, (void *)(grades + gradeCount));
            gradeCount++;

            if (gradeCount == storage) {
	      //Saving our current data and increasing storage.
                double * oldGrades = grades;
                int oldStorage = storage;
                storage += 5; 
                grades = (double *)malloc(storage * sizeof(double)); 
                if (grades == NULL) {
                    printf("Memory allocation failed!\n");
                    free(oldGrades); 
                    return 1;
                }

                allocCount++; 

		//Copying each grade to storage.
                for (int i = 0; i < gradeCount; i++) {
                    *(grades + i) = *(oldGrades + i);
                }

		//Print detailed statistics
                printf("Stored %d grades (%lu bytes) to the heap at %p.\n", gradeCount, oldStorage * sizeof(double), (void *)oldGrades);
		
                printf("Heap at %p is full.\n", (void *)oldGrades);

		//Updating total allocated bytes.
                totalAllocatedBytes += storage * sizeof(double);
		
                printf("Allocated %ld bytes to the heap at %p.\n", storage * sizeof(double), (void *)grades);
		
                printf("Copied %d grades from %p to %p.\n", gradeCount, (void *)oldGrades, (void *)grades);
		
                printf("Freed %ld bytes from the heap at %p.\n", oldStorage * sizeof(double), (void *)oldGrades);

		//Freeing memory.
                free(oldGrades);
                freeCount++; 
            }
        }
    }

    //Outputting results after all grades.
    if (gradeCount == 0) {
        printf("The average of 0 grades is 0.000000.\n");
        printf("total heap usage: %d allocs, %d frees, 0 bytes allocated\n", allocCount, freeCount);
    } else {
      //Calculating grade average.
        double gradeAverage = totalGrade / gradeCount;
        printf("The average of %d grades is %.6f.\n", gradeCount, gradeAverage);

	//Print comparison of each grade to the average.
        for (int i = 0; i < gradeCount; i++) {
            printf("%d. The grade of %.6f is ", i + 1, *(grades + i));
            if (*(grades + i) >= gradeAverage) {
                printf(">= the average.\n");
            } else {
                printf("< the average.\n");
            }
        }

        //Printing how much memory is freed.
        printf("Freed %ld bytes from the heap at %p.\n", storage * sizeof(double), (void *)grades);

	//Freeing our memory.
        free(grades);
        freeCount++;

	//Printing heap statisitcs.
        printf("total heap usage: %d allocs, %d frees, %u bytes allocated\n", allocCount, freeCount, totalAllocatedBytes);
    }
    return 0;
}

