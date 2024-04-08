#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The * is a pointer to the variable to directly change that variable instead of makeing a copy of it
// This function is used for swapping 2 numbers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
};


int main() {

    int N;
    int startRow, startCol;
    printf("Razrabotil: Georgi Vasilev 361223025 \n ");
    printf("Da se sustavi programa za obrabotka na dvumerniq masiv A[N,N], kudeto dannite sa realni chisla v intervala [-1000,1000].Programata da otpechatva vhodnite danni, da obrazuva masiv C, chiito elementi da sa elementite ot masiv A, namirasht se izvun interval [R,C]");
    printf("\nEnter the matrix size: ");
    scanf("%d", &N);

    int matrix[N][N];

    // Generating different seed based on the current time for the random numbers
    srand(time(NULL));

    printf("Filing the matrix with random numbers ...\n");
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            // Formula for the range of random numbers(-1000,1000): (upper_bound - lower_bound + 1) + lower_bound
             matrix[r][c] = rand() % (1000 - (-1001)) + (-1000); 
        }
    }

    printf("Printed Matrix:\n");
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    printf("Enter the interval for rows: ");
    scanf("%d", &startRow);
    printf("Enter the interval for columns: ");
    scanf("%d", &startCol);

    // Validation for the interval
    if (startRow < 1 || startRow >= N || startCol < 1 || startCol >= N) {
        printf("Invalid interval!\n");
        return 1;
    }

    int index = (N -startRow) * (N - startCol);
    int A[index];
    int index_A = 0;

    // Adding the numbers from the interval to a new array A[]
    for (int r = 0; r < N; r++) {
        if (r >= startRow) { 
            for (int c = 0; c < N; c++) {
                if (c >= startCol) {
                    A[index_A] = matrix[r][c];
                    index_A++;
                }
            }
        }
    }

    // Bubble sort algoritm to sort the new array A[]
    for (int i = 0; i < index - 1; i++) {
        for (int j = 0; j < index - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
            }
        }
    }

    printf(" Sorted numbers within the interval:\n ");
    for (int i = 0; i < index; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");


    return 0;
}


