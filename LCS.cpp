#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int p[50][50], a[50], b[50];//�洢�������к͹滮ʱ��״̬
int x[50],date=0;//�洢������

void ppp(int m, int n) {//�ݹ��ҳ�������
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
	printf("��������m,n�ĳ��ȣ��ո������\n");
	cin >> m >> n;
	printf("��������m��\n");
	for (int i = 0; i < m; i++)
		cin >> a[i];
	printf("��������n��\n");
	for (int i = 0; i < n; i++)
		cin >> b[i];

	

	p[0][0] = 0;
	for (int i = 0; i <= m; i++) {//���󱣴�������е���ֵ������ÿ��Ԫ��
		for (int j = 0; j <= n; j++) {
			if (!(i && j))p[i][j] = 0;
			else if (a[i - 1] == b[j - 1]) {
				p[i][j] = p[i - 1][j - 1] + 1;
			}
			else p[i][j] = max(p[i - 1][j], p[i][j - 1]);
		}
	}


	printf("����m,n���������Ϊ��\n");
	ppp(m,n);

	for (int i = date-1; i>=0; i--) {
		cout << x[i] << " ";
	}


	return 0;
}
