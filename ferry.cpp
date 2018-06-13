/*
农夫过河问题 
*/

#include<stdlib.h>
#include<iostream>
#include<string.h>
void ferry(int ferryTimes);
using namespace std;

const int MAXTIMES = 20;
int a[MAXTIMES][4];//存放狼、羊、草、农夫在河岸的位置，0：本案；1：对岸
char *name[] = {"狼","羊","草","农夫"};
int b[MAXTIMES];



int main()
{
	cout<<"**********************"<<endl;
	cout<<"**"<<"   农夫过河问题   "<<"**"<<endl;
	cout<<"**********************"<<endl;
	a[0][0] = 0;
	a[0][1] = 0;
	a[0][2] = 0;
	a[0][3] = 0;
	ferry(0);
	
}

void ferry(int ferryTimes)
{
	
	int i,j;
	if (a[ferryTimes][0] + a[ferryTimes][1] + a[ferryTimes][2] + a[ferryTimes][3] == 4)
	//if(a[ferryTimes][0] == 1 && a[ferryTimes][1] ==1 && a[ferryTimes][2] == 1 && a[ferryTimes][3] ==1)
	{
		for(i=0;i<ferryTimes;i++)
		{
			if(a[i][3]==0)
			{ 
				cout<<"载\t  "<<name[b[i]]<<"\t  到对岸去"<<endl;
			}
			else
			{
				cout<<"载\t  "<<name[b[i]]<<"\t  回本案"<<endl;
			}			 
		}
		cout<<endl;
		return;
	}
	
//	if(a[ferryTimes][1] != a[ferryTimes][3] && (a[ferryTimes][2] == a[ferryTimes][1] ||a[ferryTimes][0] == a[ferryTimes][1]))
	if((a[ferryTimes][0] == a[ferryTimes][1] || a[ferryTimes][1] == a[ferryTimes][2] )&& a[ferryTimes][1] != a[ferryTimes][3])
	{
		
		return;
	}
	
	for(i = 0;i < ferryTimes;i++)
	{
		for(j = 0;j < 4;j++)
		{
			if(a[ferryTimes][j] != a[i][j])
			{
				break;
			}
			
		}
		if(j == 4)
		{
			
			return;
		}
	}
	
	for(i=0;i<=3;i++)
	{
		
		b[ferryTimes] = i;
		a[ferryTimes+1][0] = a[ferryTimes][0];
		a[ferryTimes+1][1] = a[ferryTimes][1];
		a[ferryTimes+1][2] = a[ferryTimes][2];
		a[ferryTimes+1][3] = 1 - a[ferryTimes][3];//农夫每次的状态都会改变 
	
		if (a[ferryTimes][3] == a[ferryTimes][i])
		{
			a[ferryTimes+1][i] = a[ferryTimes+1][3];
			ferry(ferryTimes+1);
		}
	}	
}
