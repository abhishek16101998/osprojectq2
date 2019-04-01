#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;



int main()
{

	int mem[5]={100,500,200,300,600}, process[4]={212,417,112,426};
	int firstfit[4];
	
	int i,j,flag=0;
	cout<<"Processes which have got the memory are: \n";
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(mem[j]!=0 && process[i]<=mem[j])
			{
				cout<<"Process Requiring Memory "<<process[i]<<" is allocated memory with size "<<mem[j]<<endl;
				mem[j]=0;
				firstfit[i]=process[i];
				j=5;
			}
		}
	}
	cout<<"\nProcesses which do not got the memory are: \n";
	for(i=0;i<4;i++)
	{
		flag=0;
		for(j=0;j<4;j++)
		{
			if(process[i]==firstfit[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"Process Requiring memory "<<process[i]<<" has not been allocated memory\n";
		}
	}
	
}
