#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
 
int partition(int A[], int low, int high)
{
	int pivot = A[low];   
	while (low < high){
		while (low < high && A[high] >= pivot){
			--high;
		}
		A[low] = A[high];  
		while (low < high && A[low] <= pivot){
			++low;
		}
		A[high] = A[low]; 
	}
	A[low] = pivot;
	return low;
}

int r = 5;
//A[low..high]
int select_rank_k(int A[], int low, int high, int k)
{
	int r_group = ceil((high - low + 1)*1.0 / r); 
	//计算每个分组中值，存于A[]最前面
	for (int i = 1; i <= r_group; ++i) {
		sort(&A[low + (i - 1)*r], &A[(low + i*r - 1) > high ? high : (low + i*r - 1)]);
		swap(A[low + i - 1], A[low + (i-1)*r + r / 2]);
	}
	sort(&A[low], &A[low + r_group]);
	swap(A[low], A[r_group / 2]);
	int cur = partition(A, low, high);
	if (cur == k-1){
		return A[cur];
	}
	else if (cur < k){
		return select_rank_k(A, cur + 1, high, k);
	}
	else{
		return select_rank_k(A, low, cur - 1, k);
	}
}

int main(void)
{
	int A[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	printf("%d\n", select_rank_k(A, 0, 3, 2));
	return 0;
}
 
