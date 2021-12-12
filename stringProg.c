#include <stdio.h>
#include <string.h>
#include "stringProg_lib.h"
#define TXT 1024
#define WORD 30

int equal(char c)
{
    int equal = 0;
    if (c >= 'a' && c <= 'z')
    {
        equal += c - 96;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        equal += c - 64;
    }
    return equal;
}

int numerology(char *s)
{
    int len = strlen(s);
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += equal(s[i]);
    }
    return sum;
}
int isAlpha(char c)
{
    if ((c > '`' && c < '{') || (c > '@' && c < '[') || (c == ' '))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Afunction(char *word, char *text)
{
    char temp[30] = {0};
    int len = strlen(text);
    int j = 0;
    for (int i = 0; i <= len; i++)
    {
        if (isAlpha(text[i]))
        {
            temp[j++] = text[i];
        }
        else
        {   
            int l = strlen(temp);
            for (int i = 0; i <= l; i++)
            {
                if (numerology(word) == numerology(&temp[i]))
                {
                    printf("%s\n", &temp[i]);
                }
            }
            memset(temp, 0, sizeof(temp));
                j = 0;
        }
    }
}
int main()
{
    char word[WORD] = {0};
    char text[TXT] = {0};
    scanf("%s", word);
    printf("%s\n", word);
    char ch = 0;
    int i = 0;
    ch = getchar();
    do
    {
        text[i++] = ch;
        ch = getchar();
    } while (ch != '~');
    printf("%s\n", text);
    printf("***Afuncion***\n");
    Afunction(word, text);
    return 0;
}
