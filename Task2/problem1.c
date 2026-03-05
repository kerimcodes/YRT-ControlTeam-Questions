#include <stdio.h>
#include <stdlib.h>
void TurnLeft(int **array, int n);
void TurnRight(int **array, int n);

int main()
{
    int n;
    printf("Enter the size of square matrix:");
    scanf("%d", &n);

    int **array = malloc(sizeof(int*) * n);
    if (array == NULL)
        return 1;

    for (int i = 0; i < n;i++)
    {
        array[i] = malloc(sizeof(int) * n);
        if (array[i] == NULL)
        {
            for (int j = 0; j < i;j++)
                free(array[j]);
            free(array);
            return 1;
        }
    }
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            printf("Enter the %d. row %d. column element:",i,j);
            scanf("%d", &array[i][j]);
        }
    }
    TurnLeft(array, n);
    TurnRight(array, n);

    for (int i = 0; i < n;i++)
    {
        free(array[i]);
    }
    free(array);
    
    return 0;
}

void TurnLeft(int **array, int n)
{
    int newarray[n][n];

    for (int i = 0; i < n;i++)
    {
        for (int j = n - 1; j >= 0;j--)
        {
            newarray[n - 1 - j][i] = array[i][j];
        }
    }

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
            newarray[j][n-1-i] = array[i][j];
        }
    }

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {

            printf("%d ", newarray[i][j]);
        }
        printf("\n");
    }
}

