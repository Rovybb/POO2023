#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int toInt(char c[])
{
    int i = 0, num = 0;
    while (c[i] != '\0')
    {
        if (isdigit(c[i]))
            num = num * 10 + int(c[i] - '0');
        i++;
    }
    return num;
}

int main()
{
    FILE* myFile;
    myFile = fopen("in.txt", "r");
    char str[255];
    int sum = 0;

    if (myFile == NULL) {
        perror("Error opening file");
        return(-1);
    }

    while (fgets(str, 100, myFile) != NULL)
    {
        sum += toInt(str);
    }

    printf("%d", sum);
    fclose(myFile);

    return 0;
}