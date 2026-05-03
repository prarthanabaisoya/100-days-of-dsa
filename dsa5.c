#include <stdio.h>
int main()
{
    int r1, r2, c1, c2;
    printf("Enter the value of rows and columns\n");
    scanf("%d%d", &r1, &c1);
    int matrix[r1][c1];
    printf("Enter the elements of matrix\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    int t[c1][r1];
    printf("Transpose of the matrix is\n");
    for (int i = 0; i < c1; i++)
    {
        for (int j = 0; j < r1; j++)
        {
            t[i][j] = matrix[j][i];
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
}