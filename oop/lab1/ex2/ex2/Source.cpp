#include <stdio.h>
#include <string.h>

int main()
{
	char str[200], *word, st[200][20], aux[200];
	scanf("%[^\n]%*c", str);
	//printf("%s", str);
	word = strtok(str, " ");
	int k = 0;
	while (word != NULL) {
		strcpy(st[++k], word);
		word = strtok(NULL, " ");
	}
	for (int i = 1; i <= k-1; i++) {
		for (int j = i; j <= k; j++) {
			if (strlen(st[i]) < strlen(st[j]) || strlen(st[i]) == strlen(st[j]) && strcmp(st[i], st[j]) > 0) {
				strcpy(aux, st[i]);
				strcpy(st[i], st[j]);
				strcpy(st[j], aux);
			}
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%s\n", st[i]);
	}
	return 0;
}