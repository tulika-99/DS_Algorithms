#include <stdio.h>
#include<stdlib.h>

int main(){
     int n,i, *bt,*at,*ft,*tat,*wt,st=0,sw=0,min,exe;
        printf("Enter the number of process:");
        scanf("%d",&n);
        bt=(int*)malloc(n*sizeof(int));
        at=(int*)malloc(n*sizeof(int));
        ft=(int*)calloc(n,sizeof(int));
        tat=(int*)malloc(n*sizeof(int));
        wt=(int*)malloc(n*sizeof(int));
        ft[-1]=0;
        printf("Enter the Burst time of the processes:\n");
        for(i=0;i<n;i++)
                scanf("%d",&bt[i]);
        printf("Enter the arrival time of the processes:\n");
        for(i=0;i<n;i++)
                scanf("%d",&at[i]);
        min =*bt;
        printf("Printing processes in their order:\n");
        printf("Process\tBT \tAT \tFT \tTAT \tWT\n");
        for(i=0;i<n;i++){
         for(int j=0;j<n;j++){
                        if (at[j]<=ft[i-1] && min>bt[j]){
                        min = bt[j];
                        exe=j;
                }
         }
        ft[i]=min+ft[i-1];
        tat[exe]=ft[i]-at[exe];
        wt[exe]=tat[exe]-min;
        st=st+tat[exe];
        sw=sw+wt[exe];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",exe,bt[exe],at[exe],ft[i],tat[exe],wt[exe]);
        bt[exe]=INT_MAX;
        min=INT_MAX;
        }
        printf("Average turn around time: %0.3f\n",(float)st/n);
        printf("Average waiting time: %0.3f", (float)sw/n);
}
