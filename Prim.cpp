#include <iostream>
#include <string>
using namespace std;

const int N = 20;

typedef struct node
{
	int adj;//�ڽӵ� 
	int weigth;//���ϵ�Ȩֵ 
	struct node*nextarc;
}arcNode;//�ڽ��б� 

typedef struct
{
	string data;
	arcNode *firstArc;
}vexNode;

typedef struct
{
	int n,e;//n�����ף�e���� 
	vexNode adjlist[N];//�ڽ��б� 
}AdjGraph;//�ڽӱ�洢�ṹ�Ķ���

void createGraph(AdjGraph &g)
{
	cin >> g.n >> g.e;
	for(int i=0;i<g.n;i++){
		cin>>g.adjlist[i].data;
		g.adjlist[i].firstArc =NULL;
	}
	int u,v,w;
	
	for (int i=0;i<g.e;i++){
		cin >> u >> v >>w;
		arcNode *s=new arcNode;
		s->adj = v;
		s ->weigth = w;
		s->nextarc = g.adjlist[u].firstArc;
		g.adjlist[u].firstArc = s;
		s = new arcNode;
		s->adj=u;
		s ->weigth = w;
		s->nextarc = g.adjlist[v].firstArc;
		g.adjlist[v].firstArc = s;
	}
}

struct vexValue{
	int u;//��U��������Ķ��� 
	int weigth;//��u��i��Ȩֵ 
};//����һ���ṹ����Ϊ����ı��ֵ 
const int INF = 32767;//��һ���Ƚϴ������ģ�����ֵ 

int Minium(vexValue a[],int n){//���Һ��� 
	//��V-U�����е���Сֵ����
	int k = -1;
	int min =INF;
	for(int i=0;i<n;i++){
		if(a[i].weigth != 0 && a[i].weigth < min)
		{
			min=a[i].weigth;
			k=i;
		}
	}
	return k;//����Ȩֵ��С�Ķ���ı�� 
}
void minSpanTree_prim(AdjGraph &g,int u0)
{//g�����ڽӱ���Ϊ�洢�ṹ��ͼ ��u0��ѡ���ĳ�ʼ���� 
	vexValue *closedge = new vexValue[g.n];
	//����һ���������飬���ڶ�ÿ����������� 
	closedge[u0].u=0;// ��ʼ��ʱ��u������ֻ�г�ʼ���㣬���Գ�ʼ�����u��ֵ��0 
	closedge[u0].weigth=0;//ȨֵҲ��Ϊ0 
	for(int i=0;i<g.n;i++){
		if(i != u0){
			closedge[i].u=u0;//��ʼ�� ������ÿ���������u��������Ķ��� �����Ϊ��ʼ���� 
			closedge[i].weigth=INF;	//Ȩֵ���Ϊ�����	
		}
	}
	arcNode*p=g.adjlist[u0].firstArc;//��u0ȥ���������ҳ�ʼ������ܹ�ֱ�ӵ����Ȩֵȥ���޸� 
	while(p){//pָ���һ������ 
		closedge[p->adj].weigth = p->weigth;
		//��������� ����u0���ڽӵ��Ȩֵ�ñ��ϵ�Ȩֵ�޸� 
		p = p->nextarc;
	}
	for(int i=0;i<g.n - 1;i++){
		int k=Minium(closedge,g.n);
		//������ѡ���ֵ��С�Ķ��� 
		cout<<"("<<closedge[k].u<<","<<k<<")"<<endl;
		closedge[k].weigth = 0;
		//����k�Ѿ����뼯�ϣ�ȥ�޸���������ı�ǣ��������ڽ�����k 
		arcNode *p=g.adjlist[k].firstArc;
		while(p){
			if(p->weigth < closedge[p->adj].weigth){
				closedge[p->adj].u = k;
				closedge[p->adj].weigth = p->weigth;
			}
			p=p->nextarc;
		} 
	}
	delete []closedge;//�Ѹ����������ڵĿռ��ͷ� 
}
int main(){
	AdjGraph g;
	createGraph(g);
	minSpanTree_prim(g,0);
	
	return 0;
}

