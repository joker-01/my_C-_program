/*
ũ��������� 
*/

#include<stdlib.h>
#include<iostream>
#include<string.h>
void ferry(int ferryTimes);
using namespace std;

const int MAXTIMES = 20;
int a[MAXTIMES][4];//����ǡ��򡢲ݡ�ũ���ںӰ���λ�ã�0��������1���԰�
char *name[] = {"��","��","��","ũ��"};
int b[MAXTIMES];



int main()
{
	cout<<"**********************"<<endl;
	cout<<"**"<<"   ũ���������   "<<"**"<<endl;
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
				cout<<"��\t  "<<name[b[i]]<<"\t  ���԰�ȥ"<<endl;
			}
			else
			{
				cout<<"��\t  "<<name[b[i]]<<"\t  �ر���"<<endl;
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
		a[ferryTimes+1][3] = 1 - a[ferryTimes][3];//ũ��ÿ�ε�״̬����ı� 
	
		if (a[ferryTimes][3] == a[ferryTimes][i])
		{
			a[ferryTimes+1][i] = a[ferryTimes+1][3];
			ferry(ferryTimes+1);
		}
	}	
}
