#include<stdio.h>
int main(){
	int e[10][10];
	int i,j,k,m,n,t1,t2,t3;
	int INF=999999999;//����һ��������Ϊ��������ֵ
	
	//����n,m��n��ʾ����ĸ�����m��ʾ�ߵ�����
	scanf("%d %d",&n,&m);
	//��ʼ��
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				//�����Լ����Լ��ľ���Ϊ0 
				e[i][j]=0;
			}else{
				//��ʼ�����б߾�ΪTNF���������޷����� 
				e[i][j]=INF;
			}
		}
	} 
	//������Ե���ı� 
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2]=t3;
	} 
	//Floyd�㷨������䣬����ѭ�����ҵ���С���� 
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(e[i][j]>e[i][k]+e[k][j]){
					e[i][j]=e[i][k]+e[k][j];
				}
			}
		}
	} 
	//������յĽ��
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%5d",e[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
