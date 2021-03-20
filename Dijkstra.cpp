#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int INF=0x3f3f3f3f;// ������ 
const int Maxsize=1e3+5;// ������ 
int e[Maxsize][Maxsize];// �ڽӾ��� 
int book[Maxsize];// ��� 
int dis[Maxsize];// ����� 
int n,m;// n:�ڵ㣻m:�� 
int v1,v2,w;

int main()
{
    scanf("%d%d",&n,&m);
    // ��ʼ���ڽӾ��� 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)e[i][j]=0;
            else e[i][j]=INF;
        }
    }
    // input vex��arc 
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
    
    for(int i=1;i<=n-1;i++)// n-1��ѭ��������n��ѭ��(��Ϊ 1�ڵ�������ȷ��) 
    {
        // �ҵ�����1�Ŷ�������Ķ���(min_index) 
        int min_num=INF;
        int min_index=0;
        for(int k=1;k<=n;k++)// n��ѭ�� 
        {
            if(min_num>dis[k] && book[k]==0)
            {
                min_num=dis[k];
                min_index=k;
            }
        }
        book[min_index]=1;// ��� 
        for(int j=1;j<=n;j++)
        {
            // �ڵ� min__index =��j �б� 
            if(e[min_index][j]<INF)
            {
                // ����֮��ʹ�þ����ø���
                // ����дΪ dis[j]=min(dis[j],dis[min_index]+e[min_index][j]); 
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
