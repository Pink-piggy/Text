#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int p[50][50], a[50], b[50];//存储两个序列和规划时的状态
int x[50],date=0;//存储子序列

void ppp(int m, int n) {//递归找出子序列
	if (!(m && n))return;
	if (a[m-1] == b[n-1]) {
		x[date++] = a[m-1];
		ppp(m - 1, n - 1);
	}
	else {
		if (p[m - 1][n] > p[m][n - 1])ppp(m - 1, n);
		else ppp(m, n - 1);
	}

}

int main() {
	int m, n;
	printf("输入序列m,n的长度，空格隔开：\n");
	cin >> m >> n;
	printf("输入序列m：\n");
	for (int i = 0; i < m; i++)
		cin >> a[i];
	printf("输入序列n：\n");
	for (int i = 0; i < n; i++)
		cin >> b[i];

	

	p[0][0] = 0;
	for (int i = 0; i <= m; i++) {//矩阵保存最长子序列的数值，更新每个元素
		for (int j = 0; j <= n; j++) {
			if (!(i && j))p[i][j] = 0;
			else if (a[i - 1] == b[j - 1]) {
				p[i][j] = p[i - 1][j - 1] + 1;
			}
			else p[i][j] = max(p[i - 1][j], p[i][j - 1]);
		}
	}


	printf("序列m,n的最长子序列为：\n");
	ppp(m,n);

	for (int i = date-1; i>=0; i--) {
		cout << x[i] << " ";
	}


	return 0;
}
