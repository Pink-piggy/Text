#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef struct{
	int row,col,val;
}triple;//三元数组 
typedef struct{//邻接矩阵 
	string *vertexs;//一维数组存储顶点 
	triple *adj;//三元组顺序表存储边（矩阵压缩存储） 
	int n,e;//顶点个数和边的个数 
}MatGraph;

void initGraph(MatGraph &g,int vexN,int edgeN){
//初始化图的函数
	g.n=vexN;
	g.e=edgeN;
	g.vertexs=new string[g.n];//分配存储空间，存储顶点信息的一维数组 
	g.adj=new triple[g.e];//存储变的信息的三元组存储空间 
}

void destroyGraph(MatGraph &g){
	//销毁图，把空间释放
	delete[] g.vertexs;
	delete[] g.adj;
} 

bool cmp(const triple &a,const triple &b){
	//按边的权值进行排序 
	return a.val<b.val;
}
void createGraph(MatGraph &g){
	for(int i=0;i<g.n;i++)
		cin>>g.vertexs[i];
	//读入n个顶点信息 
	int u,v,w;
	//循环e（边的个数）次，连续把边存储到三元数组 
	for(int i=0;i<g.e;i++){
		cin>>u>>v>>w;
		g.adj[i].row=u;
		g.adj[i].col=v;
		g.adj[i].val=w;
	} 
}

int FIND_SET(int *S,int x){
	//反复找S顶点的双亲 ，函数返回S顶点所在树的树根的编号 
	while(S[x] >= 0)
		x=S[x];
	
	return x;
}

void UNION(int *S,int x,int y){
	//集合合并 
	S[x]=y;
}

void minSpanTree_kruskal(MatGraph &g){
	sort(g.adj,g.adj+g.e,cmp);
	//用权值对图中的边由小到大排序 
	for(int i=0;i<g.e;i++){
		cout<<"("<<g.adj[i].row<<","<<g.adj[i].col<<")"<<g.adj[i].val<<endl;
	}//做测试用，看是否完成排序 
	int *S=new int[g.n];
	//设置并查集，判断两个顶点是否在同一个集合 
	for(int i=0;i<g.n;i++)//并查集初始化（n个顶点n个集合） 
		S[i]=-1;
		
	int i=0;//第一条边 
	int count=0;//计数，记录我们选到了几条边（只需n-1条边） 
	int u,v;
	int p1,p2;
	while(1){
		u=g.adj[i].row;//第一条边的顶点 
		v=g.adj[i].col;//第一条边的第二个顶点 
		//利用 FIND_SET函数在S并查集里做查找，查找u.v的顶点在哪个集合里 
		p1=FIND_SET(S,u);
		p2=FIND_SET(S,v);
		//若p1==p2，即根节点相同，说明在同一个集合，就不能作为最小生成树的一条边 
		if(p1!=p2){
			count++;//找到一条边计数加一 
			cout<<"("<<g.vertexs[u]<<","<<g.vertexs[v]<<")"<<g.adj[i].val<<endl;
			UNION(S,p1,p2);//把这两个顶点所在的集合合并成一个集合 
			if(count==g.n-1)break;
			// 边数到达要求后，退出 
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

