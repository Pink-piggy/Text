#include <stdio.h>
#include <stdlib.h>
#define N 8

void merge(int arr[], int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    //����ռ䣬�������Ϊ���������� 
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
	
    for(k=0; left_low<=left_high && right_low<=right_high; k++){  
    	//�Ƚ�����ָ����ָ���Ԫ��,��tmp���������մ�С��ϵ���� 
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }

    if(left_low <= left_high){  
    //����һ��������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
    for(i=left_low;i<=left_high;i++)
        tmp[k++] = arr[i];
    }

    if(right_low <= right_high){
    //���ڶ���������ʣ�ֱ࣬�Ӹ��Ƴ���ճ���ϲ�����β
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }
	//��������ݴ���tmp����Ľ�����Ƶ�arr���� 
    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    //�ͷ�tmp����Ŀռ� 
    free(tmp);
    return;
}

void mergesort(int arr[], int first,int last){
	//�����⻮�ֹ��Ϊ��ģΪn/2��2��������
    int mid = 0;
    if(first<last){
    	//ע���ֹ��� 
        mid = (first+last)/2;
        mergesort(arr, first, mid);
        mergesort(arr, mid+1,last);
        merge(arr,first,mid,last);
    }
    return;
}

int main(){
    int i;
    int a[N]={16,7,2,10,27,13,9,3};

    printf ("����ǰ\n");
    for(i=0;i<N;i++){
    	printf("%d ",a[i]);
	}
	printf ("\n");
    mergesort(a,0,N-1);  // ����

    printf ("�����\n");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    return 0;
}

