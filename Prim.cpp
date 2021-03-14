#include <iostream>
#include <string>
using namespace std;

const int N = 20;

typedef struct node
{
	int adj;//邻接点 
	int weigth;//边上的权值 
	struct node*nextarc;
}arcNode;//邻接列表 

typedef struct
{
	string data;
	arcNode *firstArc;
}vexNode;

typedef struct
{
	int n,e;//n个顶底，e条边 
	vexNode adjlist[N];//邻接列表 
}AdjGraph;//邻接表存储结构的定义

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
	int u;//离U集合最近的顶点 
	int weigth;//（u，i）权值 
};//定义一个结构体作为顶点的标记值 
const int INF = 32767;//用一个比较大的整数模拟最大值 

int Minium(vexValue a[],int n){//查找函数 
	//找V-U集合中的最小值顶点
	int k = -1;
	int min =INF;
	for(int i=0;i<n;i++){
		if(a[i].weigth != 0 && a[i].weigth < min)
		{
			min=a[i].weigth;
			k=i;
		}
	}
	return k;//返回权值最小的顶点的编号 
}
void minSpanTree_prim(AdjGraph &g,int u0)
{//g是用邻接表作为存储结构的图 ，u0是选定的初始顶点 
	vexValue *closedge = new vexValue[g.n];
	//定义一个辅助数组，用于对每个顶点做标记 
	closedge[u0].u=0;// 初始的时候，u集合里只有初始顶点，所以初始顶点的u的值是0 
	closedge[u0].weigth=0;//权值也标为0 
	for(int i=0;i<g.n;i++){
		if(i != u0){
			closedge[i].u=u0;//初始化 ，对于每个顶点的离u集合最近的顶点 都标记为初始顶点 
			closedge[i].weigth=INF;	//权值标记为无穷大	
		}
	}
	arcNode*p=g.adjlist[u0].firstArc;//用u0去遍历链表，找初始顶点的能够直接到达的权值去做修改 
	while(p){//p指向第一个顶点 
		closedge[p->adj].weigth = p->weigth;
		//对链表遍历 ，对u0的邻接点的权值用边上的权值修改 
		p = p->nextarc;
	}
	for(int i=0;i<g.n - 1;i++){
		int k=Minium(closedge,g.n);
		//顶点里选标记值最小的顶点 
		cout<<"("<<closedge[k].u<<","<<k<<")"<<endl;
		closedge[k].weigth = 0;
		//顶点k已经加入集合，去修改其他顶点的标记，即遍历邻接链表k 
		arcNode *p=g.adjlist[k].firstArc;
		while(p){
			if(p->weigth < closedge[p->adj].weigth){
				closedge[p->adj].u = k;
				closedge[p->adj].weigth = p->weigth;
			}
			p=p->nextarc;
		} 
	}
	delete []closedge;//把辅助数组所在的空间释放 
}
int main(){
	AdjGraph g;
	createGraph(g);
	minSpanTree_prim(g,0);
	
	return 0;
}

