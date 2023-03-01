#include <stdio.h>
#include <iostream>

using namespace std;

int conversie(char str[]) {
    int num = 0;
    while (str[0] != '\0') {
        num = num * 10 + (str[0] - '0');
        cout << num << endl;
        str = str+1;
    }
    return num;
}

int main() {
    FILE* fp;
    char str[100];
    int sum = 0;

    fp = fopen("in.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    while (fgets(str, 100, fp) != NULL) {
        if(str[strlen(str) - 1] == '\n') {
            str[strlen(str) - 1] = '\0';
        }
        sum += conversie(str);
    }

    printf("Sum: %d\n", sum);
    fclose(fp);
    return 0;
}