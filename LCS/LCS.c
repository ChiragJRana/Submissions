  #include<stdio.h>
  #include<stdlib.h>
void LCS(char arr1[],int len1,char arr2[],int len2);
void printLCS(char arr1[],int row,int col,int countarr[][col],int arrowarr[][col]);

int main(){
    int len1,len2;
    char arr1[100];
    char arr2[100];

    printf("Enter the length of the 2 Strings:\n ");
    scanf("%d",&len1);
    scanf("%d",&len2);
    printf("Enter the two Strings:\n");
    scanf("%s",&arr1);
    scanf("%s",&arr2);

    LCS(arr1,len1,arr2,len2);

    return 0;
}
void LCS(char arr1[],int len1,char arr2[],int len2){
    int countarr[50][50];
    int arrowarr[50][50];
    for (int i = 0; i <= len1; i++){
        for (int j = 0; j <= len2; j++){
            countarr[i][j] = 0;
            arrowarr[i][j] = 0;
        }
    }

    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            if (arr1[i-1] == arr2[j-1]){
                countarr[i][j] = countarr[i-1][j-1] + 1;
                arrowarr[i][j] = 0;
            }
            else if( countarr[i-1][j] >= countarr[i][j-1]){
                countarr[i][j] = countarr[i-1][j];
                arrowarr[i][j] = 1;
            }else{
                countarr[i][j] = countarr[i][j-1];
                arrowarr[i][j] = 2;
            }
        }
    }

    printf("The Matrix of the Counting values is:\n");

    for(int i = 0; i <= len1; i++){
        for (int j = 0; j <= len2; j++){
            printf("  %d  ",countarr[i][j]);
        }
        printf("\n");
    }

    printf("The Matrix of the Arrow values is:\n");
    for (int i = 0; i <= len1; i++){
        for (int j = 0; j <= len2; j++){
            printf("  %d  ",arrowarr[i][j]);
        }
        printf("\n");
    }

    printLCS(arr1,len1+1,len2+1,countarr,arrowarr);
    return ;
}

void printLCS(char arr1[],int row,int col,int countarr[][50], int arrowarr[][50]){
	if (row == 0 || col == 0) {return;}
    if( arrowarr[row][col] == 0){
        printLCS(arr1,row-1,col-1,countarr,arrowarr);
        printf(" %c ",arr1[row-1]);
    }else if (arrowarr[row][col] == 1){
        printLCS(arr1,row-1,col,countarr,arrowarr);
    }else{
        printLCS(arr1,row,col-1,countarr,arrowarr);
    }
    return ;
}
