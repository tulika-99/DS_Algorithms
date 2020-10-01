

#include <iostream>

using namespace std;
 void tower(int n, char source, char destination, char aux) // A = source, B = aux, C = destination
 {
     
       if(n == 1)      //if there is only 1 disk then move directly from A->C
       { 
           cout<<"Move disk 1 from "<<source<<" to "<<destination<<endl;
           return;
       }
       tower(n-1, source, aux, destination);     // Move n-1 (here 3) disk from A->B
       cout<<"Move disk "<<n<< " from "<<source<<" to "<<destination<<endl;       // Move that one disk from A->C
       tower(n-1, aux,destination,source);    // Move n-1 (here 3) disk from B->C
      
   }
int main()
{
 tower(4,'A','C','B');  

    return 0;
}
