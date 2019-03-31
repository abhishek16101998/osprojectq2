#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

struct node  
{ 
  int data; 
  struct node *next; 
}; 

int main()
{
	struct node *prev,*head,*p;
	int mem[5]={100,500,200,300,600}, process[4]={212,417,112,426};
	
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(mem[j]!=0 && process[i]<=mem[j])
			{
				cout<<"Process Requiring Memory "<<process[i]<<" is allocated memory with size "<<mem[j]<<endl;
				mem[j]=0;
				j=5;
			}
		}
	}
	
}
