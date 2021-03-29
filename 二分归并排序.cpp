#include <stdio.h>
#include <stdlib.h>
#define N 8

void merge(int arr[], int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    //申请空间，将数组分为左右两部分 
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
	
    for(k=0; left_low<=left_high && right_low<=right_high; k++){  
    	//比较两个指针所指向的元素,用tmp数组来按照大小关系储存 
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }

    if(left_low <= left_high){  
    //若第一个序列有剩余，直接复制出来粘到合并序列尾
    for(i=left_low;i<=left_high;i++)
        tmp[k++] = arr[i];
    }

    if(right_low <= right_high){
    //若第二个序列有剩余，直接复制出来粘到合并序列尾
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }
	//将排序后暂存在tmp数组的结果复制到arr数组 
    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    //释放tmp数组的空间 
    free(tmp);
    return;
}

void mergesort(int arr[], int first,int last){
	//将问题划分归结为规模为n/2的2个子问题
    int mid = 0;
    if(first<last){
    	//注意防止溢出 
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

    printf ("排序前\n");
    for(i=0;i<N;i++){
    	printf("%d ",a[i]);
	}
	printf ("\n");
    mergesort(a,0,N-1);  // 排序

    printf ("排序后\n");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    return 0;
}

