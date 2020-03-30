#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(char* pat, int M, int* lps);

void KMP(char* pattern, char* string)
{
	int patternlen = strlen(pattern);
	int stringlen = strlen(string);


	int lps[patternlen];

	computeLPSArray(pattern, patternlen, lps);

	printf("The LPS Table is: \n");
	printf("[");
	for (int i = 0; i < patternlen ; i++){
		printf("%d", lps[i]);
		if( i != patternlen-1){
			printf(" \t,");
		}else{
			printf("]\n");
		}
	}
	printf("[");
	for (int i = 0; i < patternlen ; i++){
		printf("%c", pattern[i]);
		if( i != patternlen-1){
			printf(" \t,");
		}else{
			printf("]\n");
		}
	}

	printf("[");
	for (int i = 1; i < patternlen+1 ; i++){
		printf("%d",i);
		if( i != patternlen){
			printf(" \t,");
		}else{
			printf("]\n");
		}
	}

	int i = 0;
	int j = 0;
	while (i < stringlen ) {
		if (pattern[j] == string[i]) {
			j++;
			i++;
		}

		if (j == patternlen) {
			printf("Found pattern at index %d \n", i - j);
			j = lps[j - 1];
		}

		else if (i < stringlen && pattern[j] != string[i]) {
				if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

void computeLPSArray(char* pattern, int patternlen, int* lps)
{
	int len = 0;

	lps[0] = 0;

	int i = 1;
	while (i < patternlen) {
		if (pattern[i] == pattern[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{

			if (len != 0) {
				len = lps[len - 1];


			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
    char pattern[100];
    char string[100];
	printf("Enter the String: ");
    gets(string);
	printf("Enter the Pattern: ");
    gets(pattern);
	KMP(pattern, string);
	return 0;
}
