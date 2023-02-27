#include <iostream>
#include <stdio.h>
#include <cstring>
#pragma warning(disable:4996)

using namespace std;

void sortSentence(char v[][256], int n)
{
    bool ok = true;
    do {

        ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (strlen(v[i]) < strlen(v[i + 1]))
            {
                char aux[255];
                strcpy(aux, v[i]);
                strcpy(v[i], v[i + 1]);
                strcpy(v[i + 1], aux);
                ok = false;
            }
        }

    } while (!ok);
}

int main()
{
    char sentence[256], words[100][256];
    scanf("%[^\n]s", sentence);
    char* p = strtok(sentence, " ");
    int wordsNumber = 0;

    while (p != NULL)
    {
        strcpy(words[wordsNumber], p);
        wordsNumber++;
        p = strtok(NULL, " ");
    }

    sortSentence(words, wordsNumber);
    for (int i = 0; i < wordsNumber; i++)
    {
        printf("%s \n", words[i]);
    }
    return 0;
}