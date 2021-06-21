#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const int maxn=1e6+50;
ll val[maxn],w[maxn],dp[maxn];//val表示每件物品所代表的价值，w代表每件物品所要消耗背包的容量 
int n,m;//有n个物品，背包的容量为n 
int main()
{
	cin>>m>>n;
	rep(i,1,n) cin>>val[i];
	rep(i,1,n) cin>>w[i];
	memset(dp,0,sizeof dp);
	rep(i,1,n)//01背包 
	{
		for(int j=m;j>=w[i];--j)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
		}
	}

	cout<<dp[m]<<endl; 
	return 0;
}

