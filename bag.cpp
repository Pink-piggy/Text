#include <bits/stdc++.h>
using namespace std;
#define MAXN 105

// 物品重量
int w[MAXN];
// 物品价值
int v[MAXN];
// 最大载重量
int c;
// 当前最优解
int bestv = -1;
// 结果记录数组
bool res[MAXN];

// 计算当前所选物品的总价值
int sum(int pos){
    int tmp = 0;
    for(int i = 1;i <= pos;i++){
        if(res[i]){
            tmp += v[i];
        }
    }
    return tmp;
}

// 约束函数
bool constrain(int pos,int n){
    int tmp = 0;
    for(int i = 1;i <= pos;i++){
        if(res[i]){
            tmp += w[i];
        }
    }
    return tmp > c ? false : true;
}

// 限界函数
bool bound(int pos,int n){
    //计算当前没有检查的物品的总价值
    int tmp = 0;
    for(int i = pos+1;i <= n;i++){
        tmp += v[i];
    }

    return sum(pos) + tmp > bestv ? true : false;
}

// 递归法求解0-1背包问题
void LoadingTraceback(int pos,int n){
    // 可行解
    if(pos>n){
        bestv = sum(n);
    }else{
        // 左孩子，选
        res[pos] = 1;
        // 假如满足约束，那就继续
        if(constrain(pos,n)){
            LoadingTraceback(pos+1, n);
            // 注意，回溯之后要置为不选
            //res[pos] = 0;
        }

        // 右孩子，不选
        res[pos] = 0;
        // 假如满足限界，那就继续
        if(bound(pos,n)){
            LoadingTraceback(pos+1, n);
        }
    }
}

// 迭代法求解0-1背包问题
void LoadingIterate(int pos,int n){
    int f[n+1];
    for(int i = 0;i <= n;i++)
        f[i] = 1;
    while(pos > 0){
        for(;f[pos] <= 2;f[pos]++){
            // 左子树
            if(f[pos] == 1){
                res[pos] = 1;
                if(constrain(pos, n)){
                    // 可行解
                    if(pos == n){
                        bestv = sum(n);
                    }else{
                        pos++;
                        f[pos] = 0;
                    }
                }
            }else{// 右子树
                res[pos] = 0;
                if(bound(pos, n)){
                    // 可行解
                    if(pos == n){
                        bestv = sum(n);
                    }else{
                        pos++;
                        f[pos] = 0;
                    }
                }
            }
        }
        pos--;
        f[pos]++;
    }
}

int main(){
    // 初始化物品重量
    memset(w, 0, sizeof(w));

    w[1] = 2;
    w[2] = 2;
    w[3] = 6;
    w[4] = 5;
    w[5] = 4;

    v[1] = 6;
    v[2] = 3;
    v[3] = 5;
    v[4] = 4;
    v[5] = 6;

    c = 10;

    int n = 5;

    //LoadingTraceback(1, n);
    LoadingIterate(1, n);

    cout<<bestv<<endl;
}

