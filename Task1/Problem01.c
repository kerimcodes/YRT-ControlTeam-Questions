#include <stdio.h>
#include <math.h>

void FindRoot(float a, float b, float c);

int main()
{
    float a, b, c;
    printf("Enter the three parameters of the equation:\n");
    if (scanf("%f %f %f",&a,&b,&c) != 3) // 3 values must be entered
    {
        printf("Invalid entry");
        return 1;
    }
    
    if (a == 0) // The equation must be second-degree
    {
        printf("This is not a second-degree equation.\n");
        return 1;
    }

    FindRoot(a, b, c);

    return 0;
}

void FindRoot(float a,float b,float c)
{
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
    {
        printf("There is no root");
    }
    
    else 
    {   
        // These are the formule for finding roots
        float first_root = (-b - sqrt(discriminant)) / (2 * a); 
        float second_root = (-b + sqrt(discriminant)) / (2 * a);

        printf("The first root: %2.f\n", first_root);
        printf("The second root: %2.f\n", second_root);
    }
}