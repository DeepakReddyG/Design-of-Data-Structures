//shell sort implementation in c 
//code contributed by Srinivas Reddy M

#include<stdio.h>
void shellsort(int [],int);
int main()
{
	int n;
	printf("enter n value\n");
	scanf("%d",&n);
	int a[n],i;
	printf("enter elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("elements before sorting\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
	shellsort(a,n);
	return 0;
}
void shellsort(int a[],int n)
{
	int i,j,gap,temp;
	for(gap=n/2;gap>=1;gap=gap/2)
	{
		for(j=gap;j<n;j++)
		{
			for(i=j-gap;i>=0;i=i-gap)
			{
				if(a[i]>a[i+gap])
				{
					temp=a[i];
					a[i]=a[i+gap];
					a[i+gap]=temp;
				}
				else
				break;
			}
		}
	}
	printf("elements after sorting:\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
}
