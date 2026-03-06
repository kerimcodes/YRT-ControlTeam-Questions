#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int **createİmagesMatrix(int M, int N);
int **createFilterMatrix(int k);
int **applyConvolution(int **imageMatrix, int imagematrixRow, int imageMatrixColumn, int **filterMatrix, int filterMatrixSize);
void printMatrix(int **matrix, int row, int column);
void deleteMatrix(int **matrix, int row);

int main()
{
    srand(time(NULL));
    int M, N, k;
    printf("Enter the row image matrix:");
    scanf("%d", &M);
    printf("Enter the column of image Matrix:");
    scanf("%d", &N);
    printf("Enter the size of filter matrix:");
    scanf("%d", &k);
    if (M < k || N < k)
        return 1;

    int **imageMatrix = createİmagesMatrix(M, N);
    int **filterMatrix = createFilterMatrix(k);
    if (imageMatrix == NULL || filterMatrix == NULL)
        return 1;

    int **filteredMatrix = applyConvolution(imageMatrix, M, N, filterMatrix, k);
    if (filteredMatrix == NULL)
        return 1;

    const int row = (M - k + 1);
    const int column = (N - k + 1);

    printf("image matrix:\n");
    printMatrix(imageMatrix, M, N);
    printf("Filter Matrix:\n");
    printMatrix(filterMatrix, k, k);
    printf("Filtered Matrix:\n");
    printMatrix(filteredMatrix, row, column);

    deleteMatrix(imageMatrix, M);
    deleteMatrix(filterMatrix, k);
    deleteMatrix(filteredMatrix, row);

    return 0;
}

int **applyConvolution(int **imageMatrix,int imagematrixRow,int imageMatrixColumn,int **filterMatrix,int filterMatrixSize)
{   
    const int row = (imagematrixRow - filterMatrixSize + 1); // Simplifying the code by using constant values
    const int column = (imageMatrixColumn - filterMatrixSize + 1);
    int **filteredMatrix = malloc(sizeof(int *) * row); 
    if (filteredMatrix == NULL)
        return NULL;

    for (int i = 0; i < row;i++)
    {
        filteredMatrix[i] = malloc(sizeof(int) * column);
        if (filteredMatrix == NULL)
        {
            deleteMatrix(filteredMatrix, i);
            return NULL;
        }
    }

    // summation for the denominator
    int sumofFilterMatrix = 0;
    for (int i = 0; i < filterMatrixSize;i++)  
    {
        for (int j = 0; j < filterMatrixSize;j++)
        {
            sumofFilterMatrix += filterMatrix[i][j];
        }
    }
    // for zero division error 
    if (sumofFilterMatrix == 0)
        return NULL;
    // convolution process
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            int filterSum = 0;
            for (int k = 0; k < filterMatrixSize; k++)
            {
                for (int z = 0; z < filterMatrixSize; z++)
                {
                    filterSum += filterMatrix[k][z] * imageMatrix[i+k][j+z];
                }
            }
            filteredMatrix[i][j] = filterSum / sumofFilterMatrix;
        }
    }
    return filteredMatrix;
}

int **createİmagesMatrix(int M,int N)
{
    int **imagematrix = malloc(sizeof(int *) * M);
    if (imagematrix == NULL)
        return NULL;
    for (int i = 0; i < M;i++)
    {
        imagematrix[i] = malloc(sizeof(int) * N);
        if (imagematrix[i] == NULL)
        {
            deleteMatrix(imagematrix, i);
            return NULL;
        }
    }

    for (int i = 0; i < M;i++)
    {
        for (int j = 0; j < N;j++)
        {
            imagematrix[i][j] = rand() % 10;
        }
    }
    return imagematrix;
}

int **createFilterMatrix(int k)
{
    int **filterMatrix = malloc(sizeof(int *) * k);
    if (filterMatrix == NULL)
        return NULL;

    for (int i = 0; i < k;i++)
    {
        filterMatrix[i] = malloc(sizeof(int) * k);
        if (filterMatrix == NULL)
        {
            deleteMatrix(filterMatrix, i);
            return NULL;
        }
    }

    for (int i = 0; i < k;i++)
    {
        for (int j = 0; j < k;j++)
        {
            filterMatrix[i][j] = rand() % 10;
        }
    }
    return filterMatrix;
}

void printMatrix(int **matrix, int row, int column)
{   
    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < column;j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void deleteMatrix(int **matrix, int row)
{   
    for (int i = 0; i < row;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    printf("Deleted the matrix\n");
}