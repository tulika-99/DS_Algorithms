#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
template<class t>
class isort
{
 public:
        t a[500];
		t n;
		void input();
		void display();
		void sort();
};
template <class t>
void isort<t>::input()
{
 int i;
 cout<<"\nENTER THE NUMBER OF ELEMENTS  :";
 cin>>n;
 cout<<"\nENTER THE ELEMENTS OF THE ARRAY :\n";
 for(i=1;i<=n;i++)
  cin>>a[i];
}
template<class t>
void isort<t>::display()
{
 for(int i=1;i<=n;i++)
  cout<<a[i]<<" ";
}
template<class t>
void isort<t>::sort()
{
 int i,j,key,count=0;
 for(j=2;j<=n;j++)
 {
  key=a[j];
  i=j-1;
  while(i>0 && a[i]>key)
  {
   a[i+1]=a[i];
   i--;
  }
  a[i+1]=key;
 }
 cout<<"\nSORTED ARRAY : ";
 display();
}
int main()
{

 int c;
 char ch='y';
 while(ch=='y' || ch=='Y')
 {
  isort<int> i;
  i.input();
  cout<<"\nELEMENTS OF THE ARRAY ";
  i.display();
  i.sort();
  cout<<"\nDo you wish to continue?(y/n)";
  cin>>ch;
 }
 return 0;
}

