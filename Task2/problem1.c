#include <stdio.h>
#include <stdlib.h>
int **createSquareMatrix(int n);
void TurnLeft(int **array, int n);
void TurnRight(int **array, int n);

int main()
{
    int n;
    printf("Enter the size of square matrix:");
    scanf("%d", &n);
    
    int **array = createSquareMatrix(n);
    if (array == NULL)
        return 1;
    TurnLeft(array, n);
    printf("\n");
    TurnRight(array, n);

    for (int i = 0; i < n;i++)
    {
        free(array[i]);
    }
    free(array);
    
    return 0;
}

int **createSquareMatrix(int n)
{   
    int **array = malloc(sizeof(int*) * n); // Dynamic memory management is important for memory space and speed
    if (array == NULL) // Check Errors
        return NULL;

    for (int i = 0; i < n;i++)
    {
        array[i] = malloc(sizeof(int) * n);
        if (array[i] == NULL)
        {
            for (int j = 0; j < i;j++)
                free(array[j]);
            free(array);
            return NULL;
        }
    }

    int count = 1;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            array[i][j] = count;
            count++;
        }
    }
    return array;
}

void TurnLeft(int **array, int n)
{
    int newarray[n][n];

    for (int i = 0; i < n;i++)
    {
        for (int j = n - 1; j >= 0;j--)
        {
            newarray[n - 1 - j][i] = array[i][j]; // is done to place each line in the column, starting from the left
        }
    }

    printf("The matrix rotated to the left\n");
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {

            printf("%d ", newarray[i][j]);
        }
        printf("\n");
    }
}

void TurnRight(int **array, int n)
{
    int newarray[n][n];

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            newarray[j][n-1-i] = array[i][j]; // is done to place each line in the column, starting from the right
        }
    }

    printf("The matrix rotated to the right\n");
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {

            printf("%d ", newarray[i][j]);
        }
        printf("\n");
    }
}