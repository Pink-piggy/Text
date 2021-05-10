#include <iostream>
using namespace std;
#define M 5  
#define N 6 

int maxProfit(int tmpProfit[M][N],int f[M][N],int money,int number)
{
	int i,j;
	for (i=1;i<=number;i++)
	{
		for (j=0;j<=money;j++)
		{
			tmpProfit[i][j]=0;
			for (int k=0;k<=j;k++)
			{
				if (tmpProfit[i][j]<f[i][k]+tmpProfit[i-1][j-k])
					tmpProfit[i][j]=f[i][k]+tmpProfit[i-1][j-k];
			}
		}
	}
	return tmpProfit[number][money];
}

int main()
{
	int tmpProfit[M][N]={0};
	int f[M][N] = {0,0,0,0,0,0,
				   0,11,12,13,14,15,
				   0,0,5,10,15,20,
				   0,2,10,30,32,40,
				   0,20,21,22,23,24};
	cout<<"最大收益为："<<maxProfit(tmpProfit,f,5,4)<<endl;
	return 0;
}
