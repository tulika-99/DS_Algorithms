#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Schedule
{
	string pro_id;
	int artime,bt,ct,ta,wt;
	/*
	artime = Arrival time,
	bt = Burst time,
	ct = Completion time,
	ta = Turn around time,
	wt = Waiting time
	*/

};

bool compare(Schedule p1,Schedule p2)
{
	return p1.artime<p2.artime;
	/* This process will always return TRUE if above condition comes*/
}

int main()
{

	Schedule process[100];
	//An array of Processes

	int cpunon=0;

	int n,i;
	//n = number of processes, i= iteration variable

	float percentage;

	printf("Enter the number of process::");
	scanf("%d",&n);

	printf("Enter the pro_id arrival time and brust time of n process\n");
	for(i=0;i<n;i++)
	{
		cin>>process[i].pro_id;
		scanf("%d",&process[i].artime);
		scanf("%d",&process[i].bt);
	}


	sort(process,process+n,compare);

	/*sort is a predefined funcion  defined in algorithm.h header file,
	it will sort the processes according to their arrival time*/

	cpunon=process[0].artime-0;

	// initial values

	process[0].ct=process[0].artime+process[0].bt;
	process[0].ta=process[0].ct-process[0].artime;
	process[0].wt=0;

	for(i=1;i<n;i++)
	{
		if(process[i].artime<=process[i-1].ct)
		{
			process[i].ct=process[i-1].ct+process[i].bt;
			process[i].ta=process[i].ct-process[i].artime;
			process[i].wt=process[i].ta-process[i].bt;
		}
		else
		{
			process[i].ct=process[i].bt+process[i].artime;
			process[i].ta=process[i].ct-process[i].artime;
			process[i].wt=process[i].ta-process[i].bt;
			cpunon+=process[i].artime-process[i-1].ct;
		}
	}

	percentage=(float)((process[n-1].ct-cpunon)/process[n-1].ct)*100;

	cout<<"OUTPUT"<<endl;
	for(i=0;i<n;i++)
	{

		cout<<process[i].pro_id<<" "<<process[i].artime<<" "
		<<process[i].bt<<" "<<process[i].ct<<" "
		<<process[i].ta<<" "<<process[i].wt;

		cout<<endl;
	}

	return 0;
}
