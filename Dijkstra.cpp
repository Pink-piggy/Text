#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int INF=0x3f3f3f3f;// 正无穷 
const int Maxsize=1e3+5;// 顶点数 
int e[Maxsize][Maxsize];// 邻接矩阵 
int book[Maxsize];// 标记 
int dis[Maxsize];// 距离表 
int n,m;// n:节点；m:边 
int v1,v2,w;

int main()
{
    scanf("%d%d",&n,&m);
    // 初始化邻接矩阵 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)e[i][j]=0;
            else e[i][j]=INF;
        }
    }
    // input vex，arc 
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&v1,&v2,&w);
        e[v1][v2]=w;
    }
    // init dis
    for(int i=1;i<=n;i++)
    {
        dis[i]=e[1][i];
    }
    // init book
    for(int i=1;i<=n;i++)book[i]=0;
    book[1]=1;
    
    for(int i=1;i<=n-1;i++)// n-1次循环，而非n次循环(因为 1节点自身已确定) 
    {
        // 找到距离1号顶点最近的顶点(min_index) 
        int min_num=INF;
        int min_index=0;
        for(int k=1;k<=n;k++)// n次循环 
        {
            if(min_num>dis[k] && book[k]==0)
            {
                min_num=dis[k];
                min_index=k;
            }
        }
        book[min_index]=1;// 标记 
        for(int j=1;j<=n;j++)
        {
            // 节点 min__index =》j 有边 
            if(e[min_index][j]<INF)
            {
                // 加入之后使得距离变得更短
                // 可以写为 dis[j]=min(dis[j],dis[min_index]+e[min_index][j]); 
                if(dis[j]>dis[min_index]+e[min_index][j])
                {
                    dis[j]=dis[min_index]+e[min_index][j];
                }
            }
        }
    }
    printf("%d ",dis[n]);
    return 0;
}
