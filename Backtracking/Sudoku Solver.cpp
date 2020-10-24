/* Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (mat[][]). The task to print a solved Sudoku.
For simplicity you may assume that there will be only one unique solution. */

#include <iostream>
using namespace std;

// Checks if Row is safe for placing the number
bool isRowSafe(int arr[][9],int row, int num)
{
    for(int i=0;i<9;i++)
    {
        if(arr[row][i]==num)
        return false;
    }
    return true;
}

// Checks if Row is safe for placing the number
bool isColSafe(int arr[][9],int col, int num)
{
    for(int i=0;i<9;i++)
    {
        if(arr[i][col]==num)
        return false;
    }
    return true;
}

// Checks if Row is safe for placing the number
bool isBoxSafe(int arr[][9],int row,int col, int num)
{
    int rowS = row - row%3;
    int colS = col - col%3;
    for(int i=rowS;i<rowS+3;i++)
    {
        for(int j=colS;j<colS+3;j++)
        {
            if(arr[i][j]==num)
            return false;
        }
    }
    return true;
}

// Main safe check caller function
bool isSafe(int arr[][9],int row, int col, int num)
{
    if(!isRowSafe(arr,row,num))
        return false;
    if(!isColSafe(arr,col,num))
        return false;
    if(!isBoxSafe(arr,row,col,num))
        return false;
    
    return true;
}

// Main function that solve sudoku
bool SudokuSolver(int arr[][9])
{
    int row = -1;
    int col = -1;
    bool isEmpty = false;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
        {
            if(arr[i][j] == 0)
            {
                isEmpty = true;
                row=i;
                col=j;
                break;
            }
        }
        if(isEmpty)
        break;
    }
    if(!isEmpty)
    return true;
    
    for(int i=1; i<=9; i++)
    {
        if(isSafe(arr , row, col, i))
        {
            arr[row][col] = i;
            if(SudokuSolver(arr))
                return true;
            arr[row][col]=0;
        }
    }
    return false;
}

// Driver function
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int arr[9][9];
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        cin>>arr[i][j];
	    }
	    SudokuSolver(arr);
	    for(int i=0;i<9;i++)
	    for(int j=0;j<9;j++)
	    cout<<arr[i][j]<<" ";
	    cout<<endl;
	}
	return 0;
}
