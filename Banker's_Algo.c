#include <stdio.h>
#include<stdlib.h>

int main(){
    int **allo,**max,**need,*available,n,r,flag=0,*check;
    printf("Enter the number of resource types:\n");
    scanf("%d",&r);
    printf("Enter the number of instances:\n");
    scanf("%d",&n);
    allo=(int**)malloc(n*sizeof(int*));
    max=(int**)malloc(n*sizeof(int*));
    need=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
    allo[i]=(int*)malloc(r*sizeof(int));
    need[i]=(int*)malloc(r*sizeof(int));
    max[i]=(int*)malloc(r*sizeof(int));
    }
    available=(int*)malloc(r*sizeof(int));
    check=(int*)malloc(n*sizeof(int));
    printf("Enter Allocation values:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++)
         scanf("%d",&allo[i][j]);
        printf("\n");
    }
    printf("Enter Maximum values:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++)
         scanf("%d",&max[i][j]);
        printf("\n");
    }
    printf("Enter Available values:\n");
    for(int j=0;j<r;j++)
         scanf("%d",&available[j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++)
         need[i][j]=max[i][j]-allo[i][j];
    }
    printf("\nN E E D:\n");
    for(int i=0;i<n;i++){
        printf("R%d\t",i);
        for(int j=0;j<r;j++)
           printf("%d\t",need[i][j]);
        printf("\n");
    }
    int k=0,i=0,f=0;

    printf("\nSequence:\n");
    while(1){
        if(i==n){
         if(k!=1)
          break;
         else{
             k=0;
             i=0;
         }
       }
       f=0;
     if(check[i]!=1){     
         for(int j=0;j<r;j++){
             if (need[i][j]>available[j]){
                 f=1;
                 break;
                 }
            }
         if(f==1){
          i++;
          continue;
          }
          for(int j=0;j<r;j++)
          available[j]+=allo[i][j];
          check[i]=1;
          k=1;
          printf("<P%d>",i);
        }
     i++;
    }
    for(i=0;i<n;i++)
      if(check[i]!=1){
       k=1;
       break;
      }
      if(k==1){
       printf("No sequence available\n");
       printf("\n");
       printf("\nSYSTEM NOT IN SAFE STATE");
    }
    else
       printf("\nSYSTEM IS IN SAFE STATE");
    return 0;     
}
