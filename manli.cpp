#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#define MAX 99999
using namespace std;

double closestPoints(double x[],double y[],int n){
    double x1,x2,y1,y2;//��¼�±�
    double dist,minDist=MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dist=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);//�������
            if(dist<minDist){
                minDist=dist;//�ҳ���С���� 
                x1=x[i];y1=y[i];//��¼��С������������� 
                x2=x[j];y2=y[j];
            }
       }
   }
    cout<<"������Ϊ��("<<x1<<","<<y1<<")-("<<x2<<","<<y2<<")";      //�������
    return minDist;
}
int main(){
    double x[100],y[100];
    double minDist;
    int n;
    cout<<"�����ĸ�����\n";
    cin>>n;
    cout<<"����㼯�����꣺\n";
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    minDist=closestPoints(x,y,n);
    cout<<"�����Ϊ��\n"<<sqrt(minDist);
    return 0;
}

