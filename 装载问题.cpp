#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const int maxn=1e6+50;
ll val[maxn],w[maxn],dp[maxn];//val��ʾÿ����Ʒ������ļ�ֵ��w����ÿ����Ʒ��Ҫ���ı��������� 
int n,m;//��n����Ʒ������������Ϊn 
int main()
{
	cin>>m>>n;
	rep(i,1,n) cin>>val[i];
	rep(i,1,n) cin>>w[i];
	memset(dp,0,sizeof dp);
	rep(i,1,n)//01���� 
	{
		for(int j=m;j>=w[i];--j)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
		}
	}

	cout<<dp[m]<<endl; 
	return 0;
}

