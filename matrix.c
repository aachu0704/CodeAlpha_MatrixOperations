
#include <stdio.h>

#define MAX 10

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    int i, j;

    printf("\nMatrix Addition:\n");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX],
                      int r1, int c1, int c2) {
    int i, j, k, sum;

    printf("\nMatrix Multiplication:\n");

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            sum = 0;

            for (k = 0; k < c1; k++) {
                sum += a[i][k] * b[k][j];
            }

            printf("%d ", sum);
        }
        printf("\n");
    }
}

void transposeMatrix(int a[MAX][MAX], int r, int c) {
    int i, j;

    printf("\nTranspose of First Matrix:\n");

    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2;
    int i, j, choice;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0 ||
        r1 > MAX || c1 > MAX || r2 > MAX || c2 > MAX) {
        printf("Invalid matrix dimensions!\n");
        return 0;
    }

    printf("\nEnter first matrix elements:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter second matrix elements:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    do {
        printf("\n--- MATRIX OPERATIONS ---\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (r1 == r2 && c1 == c2)
                    addMatrices(a, b, r1, c1);
                else
                    printf("Addition not possible!\n");
                break;

            case 2:
                if (c1 == r2)
                    multiplyMatrices(a, b, r1, c1, c2);
                else
                    printf("Multiplication not possible!\n");
                break;

            case 3:
                transposeMatrix(a, r1, c1);
                break;

            case 4:
                printf("Exiting program!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
