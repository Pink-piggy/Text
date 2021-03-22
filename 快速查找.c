#include <stdio.h>
int Search(int T[],int n,int x)
{
    for(int i=0;i<n;i++)
        {
            if(x==T[i])
                return i;
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
    printf("%d\n",Search(T,n,x));
	return 0;
}

