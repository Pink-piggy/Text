#include <stdio.h>
#include <math.h>
int Binary_Search(int T[],int n,int x)
{
	int l=1,r=n;
	int mid;
    while(l<=r)
        {
        	mid=floor((l+r)/2.0);
            if(x<T[mid])
                r=mid-1;
            else if(x>T[mid])
                l=mid+1;
            else
                return mid+1;
        }
    return 0;
}
int main()
{
	int T[100],n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
        scanf("%d",&T[i]);
    scanf("%d",&x);
    printf("%d的下标为%d\n",x,Binary_Search(T,n,x));
	return 0;
}

