#include<stdio.h>
int max(int x,int y){ //定义一个max函数，方便后续使用 
	return x>y?x:y;
}
 
int main(){
	//定义初始化变量 
	int t[]={0,1,5,2,10,3};
	int t_len=sizeof(t)/sizeof(t[0])-1;//任务的数量 
	
	int sum=0;
	for(int i=1;i<=t_len;i++){
		sum+=t[i];//所有任务的总需时间和 
	}
	int mid=sum/2;//1号机器的最大使用时间 不可超过总时长的1/2 
	
	int tmp[6][11]={{0}};//初始化动态规划矩阵为0 


//求最优解 ,即 1号机器的最大使用时间 
	for(int i=1;i<=t_len;i++){//tmp[i][j]表示前 i 个任务，在 j 及以内的共用时长下的最长共用时长 
		for(int j=1;j<=mid;j++) {	
			if(j>=t[i]){//如果当前单时长 < 时间进度 
				tmp[i][j]=max(tmp[i-1][j],(tmp[i-1][j-t[i]]+t[i]));
				//放弃共用这个新任务 or 把前面i-1个任务中抽出t[i]的时长的任务，与这个新任务共同执行
			}else{
				tmp[i][j]=tmp[i-1][j];//否则当前单时长一定不能被共用 
			}
		}
	}
		
//确定最优解的组成 
	int x[50]={0};//标记选择的任务 	
	for(int i=t_len;i>1;i--){//从状态矩阵右下角的最优值开始往前回溯	 
		if(tmp[i][mid]==tmp[i-1][mid]){//没有执行该任务 
			x[i]=0;
		}else{//标记所执行的任务，减去任务时间，继续寻找 
			x[i]=1;
			mid-=t[i];
//当前状态最优解通过dp[i-1][j-t[i]]+t[i]所得到，下一步从dp[i-1][j-t[i]]继续回溯，同样的方法判断第i-1个任务的执行情况
		}
	}
	x[1]=(tmp[1][mid]>0)?1:0;//如果剩余时间j足够执行第1个任务，第一个任务肯定被执行 
							
							
//求最少加工时间与方案						
	int res=0;
	
	printf("1号机器加工任务：\n"); 
	for(int i=1;i<=t_len;i++){
		if(!x[i]){
			printf("%d ",i);
		}
	}
	printf("\n");
	
	printf("2号机器加工任务：\n"); 
	for(int i=1;i<=t_len;i++){
		if(x[i]){		
		printf("%d ",i); 
		res+=t[i];//累加得到2号机器工作时间 	
		}
	}
	printf("\n");	
	printf("最佳加工时间为： %d \n",max(res,(sum-res)));// 最佳时长取两个中的较大值 
	return 0;
}


