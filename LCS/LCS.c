  #include<stdio.h>
  #include<stdlib.h>
void LCS(char arr1[],int len1,char arr2[],int len2);
void printLCS(char arr1[],int** countarr,int** arrowarr,int row,int col);

int main(){
    int len1,len2;
    char arr1[100];
    char arr2[100];

    printf("Enter the length of the 2 Strings:\n ");
    scanf("%d",&len1);
    scanf("%d",&len2);
    printf("Enter the two Strings:\n");
    // arr1 = (char*)malloc(len1*sizeof(char));
    // arr2 = (char*)malloc(len2*sizeof(char));
    scanf("%s",&arr1);
    scanf("%s",&arr2);
    // for (int i = 0 ; i < len1; i ++){
    //     scanf("%c",&arr1[i]);
    // }

    // for (int i = 0 ; i < len2; i ++){
    //     scanf("%c",&arr1[i]);
    // }

    printf("%s\n",arr1);
    printf("%s\n",arr2);

    LCS(arr1,len1,arr2,len2);

    return 0;
}
void LCS(char arr1[],int len1,char arr2[],int len2){
    int countarr[len1+1][len2+1];
    int arrowarr[len1+1][len2+1];
    for (int i = 0; i <= len1; i++){
        for (int j = 0; j <= len2; j++){
    //        printf("i: %d, j: %d\n",i,j);
            countarr[i][j] = 0;
            arrowarr[i][j] = 0;
        }
    }

    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
    //        printf("i: %d, j: %d",i,j);
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
    //        printf("i: %d, j: %d",i,j);
            printf("  %d  ",countarr[i][j]);
        }
        printf("\n");
    }

    printf("The Matrix of the Arrow values is:\n");
    for (int i = 0; i <= len1; i++){
        for (int j = 0; j <= len2; j++){
    //        printf("i: %d, j: %d",i,j);
            printf("  %d  ",arrowarr[i][j]);
        }
        printf("\n");
    }

    printLCS(arr1,countarr,arrowarr,len1,len2);
    return ;
}

void printLCS(char arr1[],int** countarr, int** arrowarr, int row,int col){
    printf("row: %d col:%d",row,col);
    if (row == 0 || col == 0) {return;}
    if( arrowarr[row][col] == 0){
        printLCS(arr1,countarr,arrowarr,row-1,col-1);
        printf(" %c ",arr1[row]);
    }else if (arrowarr[row][col] == 1){
        printLCS(arr1,countarr,arrowarr,row-1,col);
    }else{
        printLCS(arr1,countarr,arrowarr,row,col-1);
    }
    printf("\n");
    return ;
}
