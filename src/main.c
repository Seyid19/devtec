#include <stdlib.h>
#include "stringLib.h"

int main(int argc, char *argv[])
{
	char* str1 = malloc(sizeof(char));
	printf("Enter 1st word:\n");
	scanf("%s",str1);
	printf("Enter second word:\n");
	char* str2 = malloc(sizeof(char));
	scanf("%s",str2);

	if(str_cmp(str1,str2) == 0)
		printf("Same\n");
	else 
		printf("Not same\n");

	int len1 = str_len(str1);
	int len2 = str_len(str2);

	isPolindrome(str1);
	isPolindrome("ana");
	return 0;
}