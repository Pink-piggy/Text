#include<iostream>
using namespace std;

int n,m[100][100],p[100];
void chain() {

	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	int l = 0; 
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (l = 2; l <= n; l++) {

		for (i = 1; i <= n - l + 1; i++) {
			j = i + l - 1;

			m[i][j] = m[i][i] + m[i + 1][j] + p[i - 1] * p[i] * p[j];
			for (int k = i + 1; k < j; k++) {

				tmp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

				if (tmp < m[i][j]) {
					m[i][j] = tmp;
				}
			}
		}
	}
}


int main() {
	cout << "输入矩阵长度：";
	cin >> n;
	cout << "输入矩阵：";
	for (int i = 0; i <= n; i++) {
		cin >> p[i];
	}
	chain();
	cout <<"最少相乘次数："<< m[1][n];

	return 0;
}

