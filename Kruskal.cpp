#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef struct{
	int row,col,val;
}triple;//��Ԫ���� 
typedef struct{//�ڽӾ��� 
	string *vertexs;//һά����洢���� 
	triple *adj;//��Ԫ��˳���洢�ߣ�����ѹ���洢�� 
	int n,e;//��������ͱߵĸ��� 
}MatGraph;

void initGraph(MatGraph &g,int vexN,int edgeN){
//��ʼ��ͼ�ĺ���
	g.n=vexN;
	g.e=edgeN;
	g.vertexs=new string[g.n];//����洢�ռ䣬�洢������Ϣ��һά���� 
	g.adj=new triple[g.e];//�洢�����Ϣ����Ԫ��洢�ռ� 
}

void destroyGraph(MatGraph &g){
	//����ͼ���ѿռ��ͷ�
	delete[] g.vertexs;
	delete[] g.adj;
} 

bool cmp(const triple &a,const triple &b){
	//���ߵ�Ȩֵ�������� 
	return a.val<b.val;
}
void createGraph(MatGraph &g){
	for(int i=0;i<g.n;i++)
		cin>>g.vertexs[i];
	//����n��������Ϣ 
	int u,v,w;
	//ѭ��e���ߵĸ������Σ������ѱߴ洢����Ԫ���� 
	for(int i=0;i<g.e;i++){
		cin>>u>>v>>w;
		g.adj[i].row=u;
		g.adj[i].col=v;
		g.adj[i].val=w;
	} 
}

int FIND_SET(int *S,int x){
	//������S�����˫�� ����������S�����������������ı�� 
	while(S[x] >= 0)
		x=S[x];
	
	return x;
}

void UNION(int *S,int x,int y){
	//���Ϻϲ� 
	S[x]=y;
}

void minSpanTree_kruskal(MatGraph &g){
	sort(g.adj,g.adj+g.e,cmp);
	//��Ȩֵ��ͼ�еı���С�������� 
	for(int i=0;i<g.e;i++){
		cout<<"("<<g.adj[i].row<<","<<g.adj[i].col<<")"<<g.adj[i].val<<endl;
	}//�������ã����Ƿ�������� 
	int *S=new int[g.n];
	//���ò��鼯���ж����������Ƿ���ͬһ������ 
	for(int i=0;i<g.n;i++)//���鼯��ʼ����n������n�����ϣ� 
		S[i]=-1;
		
	int i=0;//��һ���� 
	int count=0;//��������¼����ѡ���˼����ߣ�ֻ��n-1���ߣ� 
	int u,v;
	int p1,p2;
	while(1){
		u=g.adj[i].row;//��һ���ߵĶ��� 
		v=g.adj[i].col;//��һ���ߵĵڶ������� 
		//���� FIND_SET������S���鼯�������ң�����u.v�Ķ������ĸ������� 
		p1=FIND_SET(S,u);
		p2=FIND_SET(S,v);
		//��p1==p2�������ڵ���ͬ��˵����ͬһ�����ϣ��Ͳ�����Ϊ��С��������һ���� 
		if(p1!=p2){
			count++;//�ҵ�һ���߼�����һ 
			cout<<"("<<g.vertexs[u]<<","<<g.vertexs[v]<<")"<<g.adj[i].val<<endl;
			UNION(S,p1,p2);//���������������ڵļ��Ϻϲ���һ������ 
			if(count==g.n-1)break;
			// ��������Ҫ����˳� 
		}
		i++;
		
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	MatGraph g;
	initGraph(g,n,e);
	createGraph(g);
	minSpanTree_kruskal(g);
	destroyGraph(g);
	
	return 0;
}

