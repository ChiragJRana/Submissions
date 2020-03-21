#include<stdio.h>
#include<stdlib.h>

void display(int array[],int binarray[],int length);
void SumofSubset(int array[],int binarray[],int target_sum,int index,int sum,int length);

int main(){

	int len,sumval = 0;
	int* array;
	int* binarray;

	printf("Enter the length of array:");
	scanf("%d",&len);

	array = (int*)malloc(len*sizeof(int));
    binarray = (int*)malloc(len*sizeof(int));
        printf("Enter the array of the numbers");
	for (int i = 0;i < len;i++){
		scanf("%d",&array[i]);
		binarray[i] = 0;
	}

	printf("Enter the sum:");
    scanf("%d",&sumval);
	SumofSubset(array,binarray,sumval,0,0,len);
	return 0;
}

void display(int array[],int binarray[],int length){
	printf("The array is:\n");
	for(int i = 0;i < length;i++){
		printf("%d ",array[i]);
	}
    printf("\n");
    for(int i = 0;i < length;i++){
		printf("%d ",binarray[i]);
	}
    printf("\n");
}

void SumofSubset(int array[],int binarray[],int target_sum,int index,int sum, int length){
	if(target_sum == sum){
	    printf("found");
        display(array,binarray,length);
        binarray[index] = 1;
		SumofSubset(array,binarray,target_sum,index,sum - array[index-1],length);
		binarray[index] = 0;
	}else{
		for (int i = index;i < length;i++){
           // printf("index is : %d\nsum: %d\ntarget_sum: %d\n\n",index,sum,target_sum);
            binarray[i] = 1;
			SumofSubset(array,binarray,target_sum,i + 1,sum + array[i],length);
			binarray[i] = 0;
            }
    }
}
