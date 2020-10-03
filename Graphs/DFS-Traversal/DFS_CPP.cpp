#include<iostream.h>
#include<stdlib.h>
#define MAX 20
typedef struct Q
{
	int data[MAX];
	int R, F;
}Q;

int A[MAX][MAX];
int visited[MAX];
int vertices;

void DFS(int p)
{

	cout <<"\t"<< p;

	visited[p] = 1;
	for(int i=0;i<vertices;i++)
	{
	  if(A[p][i]==1 &&(!visited[i]))
	  {
	   DFS(i);
	  }
	}
}
void insert(int vi, int vj)
{
  A[vi][vj]=1;
  A[vj][vi]=1;
}
void readgraph()
{
	int i, vi, vj, no_of_edges;
	cout <<"\nEnter no. of vertices :";
	cin >>vertices;


	cout <<"\nEnter no of edges :";
	cin >> no_of_edges;
	for (i = 0;i < no_of_edges;i++)
	{
		cout <<"\nEnter an edge (u,v)  :";
		cin >> vi >> vj;
		insert(vi, vj);
		insert(vj, vi);
	}
}
  
                      
int main()
{
	int n;
	cout <<"ENTER VALUES"<< endl;
	readgraph();
	cout <<"\n----DFS----"<< endl;
	cout <<"Starting Node No. : ";
	cin >> n;
	DFS(n);
	return 0;
}


