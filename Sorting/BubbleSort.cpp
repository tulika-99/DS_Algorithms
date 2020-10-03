#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
template<class t>
class bsort
{
 public:
        t a[500];
		t n;
		void input();
		void display();
		void sort();
};
template <class t>
void bsort<t>::input()
{
 int i;
 cout<<"\nENTER THE NUMBER OF ELEMENTS  :";
 cin>>n;
 cout<<"\nENTER THE ELEMENTS OF THE ARRAY :";
 for(i=0;i<n;i++)
   cin>>a[i];
}
template<class t>
void bsort<t>::display()
{
 for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
}
template<class t>
void bsort<t>::sort()
{
 int i,j,temp;
 for(i=0;i<=n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(a[j]<a[i])
   {
    temp=a[i];
	a[i]=a[j];
	a[j]=temp;
	
   }
  }
 }
 cout<<"\nARRAY AFTER SORTING: ";
 display();
}
int main()
{
 
 int p;
 char ch='y';
 while(ch=='y' || ch=='Y')
 {
  bsort<int> b;
  b.input();
  cout<<"\nTHE ELEMENTS OF THE ARRAY: ";
  b.display();
  b.sort();
  cout<<"\nDO YOU WISH TO CONTINUE?(Y/N)";
  cin>>ch;
 }
 return 0;
}


