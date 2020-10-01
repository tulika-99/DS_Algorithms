#include <stdio.h>

int linear(int a[], int n, int call)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == call)
        {
            printf("Element %d found at index %d  \n\n\n\n", call, i);
            break;
        }
    }
    if (i == n)
        printf("Element not found in the array  \n\n\n\n");
}

int main()
{
    int a[100], n, i, call, first, last, middle;

    printf("Linear search is executed\n\n");
    printf("Enter the number of elements you wish to enter\n");
    scanf("%d", &n); //Elements need not be sorted
    printf("Enter the elements\n\n");
    for (i = 0; i < n; i++) //Scanning Elements
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search\n");
    scanf("%d", &call);
    linear(a, n, call); //Call to function

    return 0;
}
