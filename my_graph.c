#include <stdio.h>
#include "my_mat.h"

int main() {
    int matrix[SIZE][SIZE];
    char ch = ' ';

    while (ch != 'D') {
        scanf("%s", &ch);
        int i, j;
        switch (ch) {

            case 'A':
                for (i = 0; i < SIZE; ++i) {
                    for (j = 0; j < SIZE; ++j) {
                        scanf("%d", &matrix[i][j]);
                    }
                }
                A(matrix);
                break;

            case 'B':
                scanf("%d%d", &i, &j);
                B(i, j);
                break;

            case 'C':
                scanf("%d%d", &i, &j);
                C(i, j);
                break;

            case 'D':
                D();
                break;

            default:
                printf("Error: invalid input, Enter 'D' for exit.\n");
        }
    }
    return 0;
}

