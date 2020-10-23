#include<iostream>

using namespace std;

int main()
{
    int a[1000];
    int i, item, size, flag = 0;

    cout<<"Enter the number of elements: ";

    cin>>size;
    for(int i=0; i<size; i++)
    {
        cout<<"\nEnter element as "<<i+1<<" position: ";
        cin>>a[i];
    }

    cout<<"\nEnter the item you want to search: ";
    cin>>item;

    for(i=0; i<size; i++)
    {
        if(a[i] == item)
        {
            flag = 1;

            break;
        }
    }

    if(flag == 1)
    cout<<"\nItem Found at "<<i+1<<" position.";

    else 
    cout<<"Item is not available";
    
    return 0;
}