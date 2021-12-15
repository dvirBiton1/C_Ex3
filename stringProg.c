#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "stringProg_lib.h"
#define TXT 1024
#define WORD 30

int endLine(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int equal(char c)
{
    int equal = 0;
    if (c >= 'a' && c <= 'z')
    {
        equal += (c - 96);
    }
    else if (c >= 'A' && c <= 'Z')
    {
        equal += (c - 64);
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
int numerology2(char *s1, char *s2)
{
    int sum = 0;
    while (s1 != s2)
    {
        sum += equal(*s1);
        s1++;
    }
    sum += *s1;
    return sum;
}
int numerology3(char *txt, int index1, int index2)
{
    int sum = 0;
    while (index1 != index2)
    {
        sum += equal(txt[index1]);
        index1++;
    }
    sum += txt[index1];
    return sum;
}
int isAlpha(char c)
{
    if ((c >= 'a' && c <= 'z') || ('A' <= c && c <= 'Z'))
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
    printf("Gematria Sequences: ");
    int numerologyWord = numerology(word);
    int start = 0;
    int startWord = 0;
    int flag = 0;
    while (text[start])
    {
        int sum = 0;
        startWord = start;
        if (isAlpha(text[start]))
        {
            while (text[startWord] && sum < numerologyWord)
            {
                sum += equal(text[startWord]);
                startWord++;
            }
            --startWord;
            if (sum == numerologyWord)
            {
                if (flag)
                {
                    printf("~");
                }
                flag = 1;
                for (int i = start; i <= startWord; i++)
                {
                    printf("%c", text[i]);
                }
            }
        }
        start++;
    }
    printf("\n");
}

int main()
{
    char word[WORD] = {0};
    char text[TXT] = {0};
    scanf("%s", word);
    char ch = 0;
    int i = 0;
    ch = getchar();
    while (!endLine(ch))
    {
        word[i] = ch;
        ch = getchar();
    }
    i = 0;
    ch = getchar();
    do
    {
        text[i] = ch;
        i++;
        ch = getchar();
    } while (ch != '~');
    printf("%s\n", word);
    printf("%s\n", text);
    Afunction(word, text);
    // funcA(text,word);
    return 0;
}
