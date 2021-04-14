#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct point{//��ṹ
    double x,y;
};
double Distance(point a,point b){//��������֮��ľ��� 
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(point a,point b){//��y������������
    return a.y<b.y;
}
bool cmp2(point a,point b){//��x������������
    return a.x<b.x;
}
double closestPoint(point s[],int low,int high,point rec[]){
    double d1,d2,d3,d;
    int mid,i,j,index;
    double x1,y1,x2,y2;//��¼��Ե�λ��
    point P[high-low+1],temp1[2],temp2[2],temp3[2]; //�����ռ�
    if(high-low==1){             //����������
        rec[0].x=s[low].x;rec[0].y=s[low].y;
        rec[1].x=s[high].x;rec[1].y=s[high].y;
        return Distance(s[low],s[high]);
        }
    if(high-low==2){            //����������
        d1=Distance(s[low],s[low+1]);
        d2=Distance(s[low+1],s[high]);
        d3=Distance(s[low],s[high]);
        if((d1<d2)&&(d1<d3)){
            rec[0].x=s[low].x;rec[0].y=s[low].y;
            rec[1].x=s[low+1].x;rec[1].y=s[low+1].y;
            return d1;
        }
        else if(d2<d3){
            rec[0].x=s[low+1].x;rec[0].y=s[low+1].y;
            rec[1].x=s[high].x;rec[1].y=s[high].y;
            return d2;
        }
        else {
            rec[0].x=s[low].x;rec[0].y=s[low].y;
            rec[1].x=s[high].x;rec[1].y=s[high].y;
            return d3;
        }
    }
    mid=(low+high)/2;       //��������ݹ�
    d1=closestPoint(s,low,mid,rec);
    temp1[0]=rec[0];
    temp1[1]=rec[1];
    d2=closestPoint(s,mid+1,high,rec);
    temp2[0]=rec[0];
    temp2[1]=rec[1];
    if(d1<d2){
        d=d1;
        rec[0]=temp1[0];
        rec[1]=temp1[1];
    }
    else {
        d=d2;
        rec[0]=temp2[0];
        rec[1]=temp2[1];
    }
    index=0;
    for(i=mid;(i>=low)&&((s[mid].x-s[i].x)<d);i--)      //�㼯��p1
        P[index++]=s[i];
    for(i=mid+1;(i<=high)&&((s[i].x-s[mid].x)<d);i++)      //�㼯��p2
        P[index++]=s[i];
    sort(P,P+index,cmp);                    //��������
    for(i=0;i<index;i++){
        for(j=j+1;j<index;i++){
            if((P[j].y-P[i].y)>=d)
                break;
            else {
                d3=Distance(P[i],P[j]);
                if(d3<d){
                    rec[0].x=P[i].x;rec[0].y=P[i].y;
                    rec[1].x=P[j].x;rec[1].y=P[j].y;
                    d=d3;
                }
            }
        }
    }
    return d;
}
int main(){
    point p[10];            //�趨��ļ���
    int n;
    double minDist;
    cout<<"�����ĸ�����\n";      //�����ĸ���
    cin>>n;
    cout<<"����㼯:��x,y��\n";
    for(int i=0;i<n;i++)
        cin>>p[i].x>>p[i].y;
    sort(p,p+n,cmp2);      //������ĵ�������
    point index[2];
    minDist=closestPoint(p,0,n-1,index);
    cout<<"��С������Ϊ��("<<index[0].x<<","<<index[0].y<<"),("<<index[1].x<<","<<index[1].y<<")\n";
    cout<<"��С����Ϊ��\n"<<minDist;      //�����Ե���С����
    return 0;
}

