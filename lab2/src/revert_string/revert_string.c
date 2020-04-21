#include "revert_string.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void RevertString(char *str)
{
	printf("called func\n");
	int str_size = sizeof(char) * (strlen(str));
	printf("%d str_size\n", str_size);
	int str_ln = strlen(str) - 1;
	char *reverse = malloc(str_size);//same length
	for (int i = 0; i <= str_ln; i++){
		reverse[i] = str[str_ln-i];
	}
	strcpy(str, reverse);
}

