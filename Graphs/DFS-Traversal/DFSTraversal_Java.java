// DFS TRAVERSAL IN GRAPH.


package assign5;

import java.util.Scanner;


class graph
{

int v;                  
int e;
int h;
int max=10;
int matrix[][]=new int[20][20];
int visited[]=new int[10];

Scanner s=new Scanner(System.in);
graph()
{
	v=0;
	e=0;
	h=0;
}
  
	
	void createMatrix()
	{
        int i,j;
        int v1,v2;
		System.out.println("Enter number of vertices");
		v=s.nextInt();
		System.out.println("Enter number of edges");
		e=s.nextInt();
		for(i=0;i<e;i++)
		{
				System.out.println("Enter Edges for vertices : ");
				v1=s.nextInt();
				v2=s.nextInt();
				matrix[v1][v2]=1;
				matrix[v2][v1]=1;
			
		}
	for(i=0;i<v;i++)
	{
		visited[i]=0;
	}
		System.out.println("Enter first house number");
		h=s.nextInt();
		System.out.println("DFS TRAVERSAL :");
	DFS(h);
	}	
	
	void DFS(int h1)
	{   

	   
			
			int i=0,j;
			
			System.out.print(h1+" ");
			visited[h1]=1;
			for(j=0;j<v;j++)
			{
				if(visited[j]==0 && matrix[h1][j]==1)
				{
					DFS(j);
				}
			}
			
			
	}
	
}

	

public class DFSTraversal_Java {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		graph g=new graph();
		
			g.createMatrix();
		

	}

}
