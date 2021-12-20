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
int azby(char c)
{
    if (c >= 'm' && c <= 'z')
    {
        return ('z' - c + 1);
    }
    else if (c >= 'M' && c <= 'Z')
    {
        return ('Z' - c + 1);
    }
    return c;
}
int azby2(char c)
{
    if (c >= 'm' && c <= 'z')
    {
        return ('z' - c + 97);
    }
    else if (c >= 'M' && c <= 'Z')
    {
        return ('Z' - c + 65);
    }
    return c;
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
void Bfunction(char *word, char *text){
    printf("Atbash Sequences: ");
    int numerologyWord = numerology(word);
    int start = 0;
    int startWord = 0;
    int flag = 0;
    int x = 0;
    int y = 0;
    while (text[start])
    {
        int sum = 0;
        startWord = start;
        if ((text[start]))
        {
            while (text[startWord] && sum < numerologyWord){
                sum += azby(text[startWord]);
                startWord++;
            }
            --startWord;
            if (sum == numerologyWord)
            {
                x = 1;
                y = 0;
                for (int i = 0; i <= strlen(word) && x; i++)
                {
                    if((azby2(text[start + i + y]) != word[i]) && (azby2(text[start + i + y]) != word[strlen(word) - i]))
                    {
                        x = 0;
                    }
                    if((text[start + i + y] == 32))
                    {
                        i=i-1;
                        y=y+1;
                        x=1;
                    }
                }
                if(strlen(word) > (startWord-start+1))
                {
                    x = 1;
                }
                if(!x)
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
        }
        start++;
    }
    printf("\n");
}
void Cfunction(char *word, char *text){
    printf("Anagram Sequences: ");
    int numerologyWord = numerology(word);
    int start = 0;
    int startWord = 0;
    int flag = 0;
    int x = 0;
    while (text[start])
    {
        int sum = 0;
        startWord = start;
        if (isAlpha(text[start]))
        {
            while (text[startWord] && sum < numerologyWord)
            {
                if( (text[startWord] > 'Z' && text[startWord] < 'a') || ((text[startWord] < 'A') || (text[startWord] > 'z')) )
                {
                    sum = sum + numerologyWord;
                }
                sum += equal(text[startWord]);
                startWord++;
            }
            --startWord;
            if (sum == numerologyWord)
            {
                x = 0;
                for (int j = 0; j < strlen(word); j++)
                {
                    for (int i = 0; i <= (startWord-start)+1; i++)
                    {
                        if(word[j] == text[start + i])
                        {
                            x++;
                            break;
                        }
                    }
                }
                if (x >= strlen(word))
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
        }
        start++;
    }
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
    Afunction(word, text);
    Bfunction(word, text);
    Cfunction(word, text);
    return 0;
}