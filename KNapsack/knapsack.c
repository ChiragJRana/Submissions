#include<stdio.h>
#include<stdlib.h>
void swap(float* a, float* b)
{
	float t = *a;
	*a = *b;
	*b = t;
}

int partition (float arr[],float arrwe[],float arrpr[], int low, int high)
{
	float pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{
		//printf("Thepivot: %f \n",pivot);

		if (arr[j] < pivot)
		{
			//printf("The pivot: %f",pivot);
			i++;
			swap(&arr[i], &arr[j]);
			swap(&arrwe[i], &arrwe[j]);
			swap(&arrpr[i], &arrpr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	swap(&arrwe[i + 1], &arrwe[high]);
	swap(&arrpr[i + 1], &arrpr[high]);

	return (i + 1);
}

void quickSort(float arr[],float arrwe[],float arrpr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr,arrwe,arrpr, low, high);
		quickSort(arr,arrwe,arrpr, low, pi - 1);
		quickSort(arr,arrwe,arrpr, pi + 1, high);
	}
}

void printArray(float arr[], int size)
{
	for (int i=0; i < size; i++)
		printf(" /%.3f/ ", arr[i]);
	printf("\n\n");
}

void submitsolution(float arrra[],float arrwe[],float arrpr[],int sum,int length){
    int temp = 0;
    float finalval = 0;
    float* arr = (float*)malloc(length*sizeof(float));
    for (int i = length-1;i>=0; i --){
            if(temp < sum){
                if((sum-temp) >= arrwe[i]){
                    temp += arrwe[i];
                    arr[i] = arrwe[i];
                    finalval += arr[i]*arrra[i];
 //                   printf("ifsum temp %d \n",temp);
   //                 printf("arr[i] %f \n",arr[i]);
     //               printf("finalval %f \n",finalval);

                }else{
    //                printf("else %d",temp);
      //              printf("arr[i] %f \n",arr[i]);
                    arr[i] = sum-temp;
                    finalval += arr[i]*arrra[i];
                    temp = sum;
  //                  printf("arr[i] %f \n",arr[i]);
//                    printf("finalval %f \n",finalval);
                    break;
                }
            }
    }
    printf("Weight selected array: ");
    printArray(arr,length);
    printf("The final Answer is: %.3f",finalval);
}
int main()
{
    int n,sum;

    float *arrpr,*arrwe;
    float *arrra;
    printf("Enter the array length:");
	scanf("%d",&n);

	arrpr =  (float*)malloc(n*sizeof(float));
	arrwe =  (float*)malloc(n*sizeof(float));
	arrra =  (float*)malloc(n*sizeof(float));

	printf("Enter the profit and weight value:");

    for (int i = 0; i< n;i++){
        scanf("%f",&arrpr[i]);
        scanf("%f",&arrwe[i]);
        arrra[i] = arrpr[i]/arrwe[i];
    }
	for (int i = 0; i< n;i++){
		printf("%f ",arrra[i]);
	}
    printf(" \nEnter the maximum value of Sum: ");
    scanf("%d",&sum);

	quickSort(arrra,arrwe,arrpr,0, n-1);
	printf("Sorted profit/wt array: \n");
	printArray(arrra, n);
	printf("Sorted weight array: \n");
	printArray(arrwe, n);
	printf("Sorted profit array: \n");
	printArray(arrpr, n);
    submitsolution(arrra,arrwe,arrpr,sum,n);
	return 0;
}
// 10 2 5 3 15 5 7 7 6 1 18 4 3 1
