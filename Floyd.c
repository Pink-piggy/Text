#include<stdio.h>
int main(){
	int e[10][10];
	int i,j,k,m,n,t1,t2,t3;
	int INF=999999999;//储存一个我们认为的正无穷值
	
	//读入n,m，n表示顶点的个数，m表示边的条数
	scanf("%d %d",&n,&m);
	//初始化
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				//顶点自己到自己的距离为0 
				e[i][j]=0;
			}else{
				//初始化所有边距为TNF，即代表无法到达 
				e[i][j]=INF;
			}
		}
	} 
	//读入可以到达的边 
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2]=t3;
	} 
	//Floyd算法核心语句，三重循环，找到最小距离 
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(e[i][j]>e[i][k]+e[k][j]){
					e[i][j]=e[i][k]+e[k][j];
				}
			}
		}
	} 
	//输出最终的结果
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%5d",e[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
