#include<stdio.h>
#include<stdlib.h>

void display(int array[],int start,int len);
void QuickSort(int arr[],int start,int end);
int pass = 1;
int main(){
    int len;
	int* array;
	printf("Enter the length of the array");
	scanf("%d",&len);

	array = (int*)malloc(len * sizeof(int));
	printf("enter the array:");
	for (int i = 0; i< len ; i++){
		scanf("%d",&array[i]);
    }

    display(array,0,len-1);
	QuickSort(array,0,len-1);
    display(array,0,len-1);
    return 0;
}


void QuickSort(int array[], int start, int end){
    int i= start;
    int j = start;
    int temp;
    if(start < end){
    printf("Pass: %d\n",pass++);
    printf("The pivot elements is %d\n",array[i]);
        while(j <= end){
            while(j <= end && array[++j] > array[start]);
                if(j <= end){
                    temp = array[i+1];
                    array[++i] = array[j];
                    array[j] = temp;
                }
        }
        temp = array[i];
        array[i] = array[start];
        array[start] = temp;
        display(array,start,end);
        QuickSort(array,start,i-1);
        QuickSort(array,i+1,end);
    }
}

void display(int array[],int start, int end){
	for(int i = start; i <= end ; i++){
		printf(" %d ",array[i]);
	}
	printf("\n");
return ;
}
