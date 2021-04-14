#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#define MAX 99999
using namespace std;

double closestPoints(double x[],double y[],int n){
    double x1,x2,y1,y2;//记录下标
    double dist,minDist=MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dist=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);//计算距离
            if(dist<minDist){
                minDist=dist;//找出最小距离 
                x1=x[i];y1=y[i];//记录最小距离两点的坐标 
                x2=x[j];y2=y[j];
            }
       }
   }
    cout<<"最近点对为：("<<x1<<","<<y1<<")-("<<x2<<","<<y2<<")";      //输出坐标
    return minDist;
}
int main(){
    double x[100],y[100];
    double minDist;
    int n;
    cout<<"输入点的个数：\n";
    cin>>n;
    cout<<"输入点集的坐标：\n";
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    minDist=closestPoints(x,y,n);
    cout<<"其距离为：\n"<<sqrt(minDist);
    return 0;
}

