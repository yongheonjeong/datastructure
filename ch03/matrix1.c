#include <stdio.h>
#include <stdlib.h> // malloc 함수를 사용하기 위해 필요

#define ROWS 3
#define COLS 3

// 행렬 전치함수
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]) {
    for(int r = 0; r < ROWS; r++)
        for(int c = 0; c < COLS; c++)
            B[c][r] = A[r][c];
}

void matrix_print(int A[ROWS][COLS]) {
    puts("==============");
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            printf("%d ", A[r][c]);
        }
        printf("\n");
    }
    puts("==============");
}

void matrix_print2(int (*A)[COLS]) {
    puts("==============");
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            printf("%d ", A[r][c]);
        }
        printf("\n");
    }
    puts("==============");
}

int (*add_matrix(int A[ROWS][COLS], int B[ROWS][COLS]))[COLS] {
    int (*C)[COLS] = malloc(sizeof(int) * ROWS * COLS);
    
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            C[r][c] = A[r][c] + B[r][c];
        }
    }

    return C;
}

int main(void) {
    int array1[ROWS][COLS] = {
        {2, 3, 0},
        {8, 9, 1},
        {7, 0, 5}
    };

    int array2[ROWS][COLS];

    matrix_transpose(array1, array2);
    matrix_print(array1);
    matrix_print(array2);
    
    int (*arr3)[COLS] = add_matrix(array1, array2);
    
    matrix_print2(arr3);
    
    free(arr3); // 동적 할당 해제

    return 0;
}
