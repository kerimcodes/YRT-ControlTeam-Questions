#include <stdio.h>

void sort(int *arr,int n);
void takeaverage(int *arr, int n);

int main()
{
    int array[8] = {0};

    for (int i = 0; i < 8;i++)
    {
        printf("Enter the %d. grades\n",i+1);
        scanf("%d", &array[i]);
        if (array[i] > 100)
        {
            printf("invalid exam grades!");
            return 1;
        }
    }

    sort(array, 8);
    printf("The sorted grades: ");
    for (int i = 0; i < 8;i++)
    {
        printf("%d ", array[i]);
    }
        
    takeaverage(array, 8);

}

void sort(int *arr,int n)
{
    for (int i = 0; i < n;i++)
    {
        int min = arr[i];
        int index = i;
        for (int j = i; j < n;j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }

        int tmp = arr[i];
        arr[i] = min;
        arr[index] = tmp;
    }
}

void takeaverage(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n;i++)
    {
        sum += arr[i];
    }
    float average = (float)sum / n;

    printf("The average is %0.2f\n",average);
}