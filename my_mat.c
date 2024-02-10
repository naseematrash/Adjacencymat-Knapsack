#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"

int matrix[SIZE][SIZE];

void FloydWarshall(int arr[10][10]) {
    int i, j, k;
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            if (i == j) {
                matrix[i][i] = 0;
            } else if (arr[i][j] == 0) {
                matrix[i][j] = MAXVALUE;
            } else if (arr[i][j] != 0) {
                matrix[i][j] = arr[i][j];
            }
        }
    }

    for (k = 0; k < SIZE; k++) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (j != k && i != k && (matrix[i][k] != MAXVALUE && matrix[k][j] != MAXVALUE)) {
                    if (matrix[i][j] > (int) matrix[i][k] + matrix[k][j]) {
                        matrix[i][j] = (int) matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }
}

void A(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = arr[i][j];
        }
    }
    FloydWarshall(arr);
}

void B(int i, int j) {
    if (matrix[i][j] == MAXVALUE || matrix[i][j] == 0) {
        printf("False");
    } else {
        printf("True");
    }
    printf("\n");
}

void C(int i, int j) {

    if (matrix[i][j] == 0 || matrix[i][j] == MAXVALUE) {
        printf("-1");
    } else {
        printf("%d", matrix[i][j]);
    }
    printf("\n");
}
void D(){
    exit(0);
}






