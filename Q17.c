//Problem: A secret system stores code names in forward order. 
//To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <string.h>

void reverse(char s[], int i)
{
    if (i < 0)
        return;
    printf("%c", s[i]);
    reverse(s, i - 1);
}

int main()
{
    char s[1000];
    scanf("%s", s);
    reverse(s, strlen(s) - 1);
    return 0;
}