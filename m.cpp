#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=110;
int n,m,e;//ͼ�Ķ����������õ���ɫ�������ߵ�����
int cnt=0;//������ 
int c[maxn][maxn];//���Ӿ���
int color[maxn];//��ǰ�� 
bool ok(int x){
    for(int i=1;i<=n;i++){
        if(c[x][i]&&color[i]==color[x]){
            return false;
        }
    }
    return true;
}
void backtrack(int x){
    if(x>n){
    	cnt++;
        for(int i=1;i<=n;i++){
            printf("%d ",color[i]);
        }
        printf("\n");
    }
	else{
        for(int i=1;i<=m;i++){
            color[x]=i;
            if(ok(x)){
                backtrack(x+1);
            }
            color[x]=0;
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&e);
    for(int i=1;i<=e;i++){
    	int x,y;
    	scanf("%d %d",&x,&y);
    	c[x][y]=1;
        c[y][x]=1;
	}
    backtrack(1);
    if(cnt){
    	printf("������Ϊ%d\n",cnt);
	}
    else{
    	puts("NO");
	}
    return 0;
}
