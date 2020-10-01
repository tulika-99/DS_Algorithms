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

int binary(int a[], int n, int call, int first, int last, int middle)
{
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;
    while (first <= last)
    {
        if (a[middle] < call)
            first = middle + 1;
        else if (a[middle] == call)
        {
            printf("Element %d is found at index %d  \n", call, middle);
            break;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first > last)
        printf("%d is not present in the array \n", call);
}

int main()
{
    int choice, a[100], n, i, call, first, last, middle;

    while (choice != 3)
    {

        printf("Enter the option between 1,2 and 3 to choose a searching method\n");
        printf("1: Linear search\n");
        printf("2: Binary search\n");
        printf("3: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
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
            break;
        case 2:
            printf("Binary search is executed\n\n");
            printf("Enter the number of elements you wish to enter\n");
            scanf("%d", &n); //Elements should be sorted
            printf("Enter the elements in a sorted order for Binary search\n\n");
            for (i = 0; i < n; i++) //Scanning Elements
            {
                scanf("%d", &a[i]);
            }
            printf("Enter the element to search\n");
            scanf("%d", &call);                      //Search element
            binary(a, n, call, first, last, middle); //Call to function
            break;
        case 3:
            printf("Exit\n\n\n\n");
            break;
        default:
            printf("This option does not exist\n");
            break;
        }
    }
    return 0;
}
