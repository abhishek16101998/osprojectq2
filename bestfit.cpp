#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;



int main()
{

	int mem[5]={100,500,200,300,600}, process[4]={212,417,112,426};
	int firstfit[4];
	
	int i,j,flag=0;
	cout<<"Processes which have got the memory according to first fit are: \n";
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
	cout<<"\nProcesses which do not got the memory according to first fit are: \n";
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
	cout<<"\n\n";
	cout<<"Process Allocated Memory according to Worst Fit are: \n";
	int memworst[5] = {100,500,200,300,600};
	int processworst[4] = {212,417,112,426};
	int worstfit[4][5], worstfitfinal[4];
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(memworst[j]!=-1)
			worstfit[i][j]=memworst[j]-processworst[i];
			else
			worstfit[i][j]=-1;
			
		}
		sort(worstfit[i], worstfit[i]+5);
		if(worstfit[i][4]>=0)
		{
			cout<<"Process Requiring Memory "<<processworst[i]<<" has been allocated memory with size "<<worstfit[i][4]+processworst[i]<<endl;
			for(int n=0;n<5;n++)
			{
				if(memworst[n]==worstfit[i][4]+processworst[i])
				{
					memworst[n]=-1;
					break;
				}
			}
			worstfitfinal[i]=processworst[i];
		}
		
	}
	cout<<"\nProcesses who are not allocated according to worst fit are: \n";
	for(i=0;i<4;i++)
	{
		flag=0;
		for(j=0;j<4;j++)
		{
			if(processworst[i]==worstfitfinal[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"Process Requiring memory "<<processworst[i]<<" has not been allocated memory\n";
		}
	}
//------------------------------------------------------------	
		cout<<"\n\n";
	cout<<"Process Allocated Memory according to Best Fit are: \n";
	int membest[5] = {100,500,200,300,600};
	int processbest[4] = {212,417,112,426};
	int bestfit[4][5], bestfitfinal[4];
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(membest[j]!=-1)
			bestfit[i][j]=membest[j]-processbest[i];
			else
			bestfit[i][j]=-1;
			
		}
		int kl,kl1=0,choose;
		sort(bestfit[i], bestfit[i]+5);
			
		for(kl=0;kl<5;kl++)
		{
			if(bestfit[i][kl]>0)
			{
				choose=bestfit[i][kl];
				kl1=kl;
				kl=5;
			}
		}
	
		for(kl=0;kl<5;kl++)
		{
			
			if((choose>bestfit[i][kl])&&bestfit[i][kl]>0)
			{
			kl1=kl;
			choose=bestfit[i][kl];
			}
		}
	;
		if(bestfit[i][kl1]>=0)
		{
			cout<<"Process Requiring Memory "<<processbest[i]<<" has been allocated memory with size "<<bestfit[i][kl1]+processbest[i]<<endl;
			for(int n=0;n<5;n++)
			{
				if(membest[n]==bestfit[i][kl1]+processbest[i])
				{
					membest[n]=-1;
					break;
				}
			}
			bestfitfinal[i]=processbest[i];
		}
		
	}
	cout<<"\nProcesses who are not allocated according to best fit are: \n";
	for(i=0;i<4;i++)
	{
		flag=0;
		for(j=0;j<4;j++)
		{
			if(processbest[i]==bestfitfinal[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<"Process Requiring memory "<<processbest[i]<<" has not been allocated memory\n";
		}
	}
	
	
}
