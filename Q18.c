//Write a function that reverses a string. The input string is given as an array of characters s.

//You must do this by modifying the input array in-place with O(1) extra memory.

 #include <stdio.h>

void reverseString(char* s, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char s[100005];
    scanf("%s", s);

    int n = 0;
    while (s[n] != '\0')
        n++;

    reverseString(s, n);
    printf("%s", s);
    return 0;
}

