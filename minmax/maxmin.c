#include <stdio.h>
#include<stdlib.h>
void maxmin(int i,int j,int*max,int*min,int arr[])
{
    for(int k = i;k <= j; k++){
        printf("%d ",arr[k]);
    }
    printf("\n");
    int max1,max2,min1,min2;
	int mid;
	if(i==j)
		*max=*min=arr[i];
	else if(i==j-1)
	{
		if(arr[i] < arr[j])
			{
				*max=arr[j];
				*min=arr[i];
			}
			else
			{
				*max=arr[i];
				*min=arr[j];
			}
	}
	else
	{
		mid=(i+j)/2;
		maxmin(i,mid,&max1,&min1,arr);
		maxmin(mid+1,j,&max2,&min2,arr);
		if(max1>max2)
			*max = max1;
		else
			*max = max2;
		if(min1 < min2)
			*min = min1;
		else
			*min = min2;
	}
	printf("minval: %d \n",(*min));
	printf("maxval: %d \n",(*max));
    printf("\n");

}
int main()
{
	int max,min,arr[20],size;
	printf("Enter the size of an array: ");
	scanf("%d",&size);
	printf("Enter the elements of an array: ");
	for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    max=arr[0];
	min=arr[0];

	maxmin(0,size-1,&max,&min,arr);
	printf("The minimum element of an array is %d\n",min );
	printf("The maximum element of an array is %d\n",max );
}
