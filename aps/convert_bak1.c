#include <stdio.h>

void stoupper(char *s)
{
    for (; *s; s++)
        if (('a' <= *s) && (*s <= 'z'))
            *s = 'A' + (*s - 'a');
}

int stringHexToInt(char _hex[])
{
    char hex[*_hex / sizeof(_hex[0])];
    for (int i; _hex[i]; i++)
    {
        hex[i] = _hex[i];
    }
    char *p = hex;
    int weight = 1;
    int res = 0;
    // char a[] = "tesTe";
    // stoupper(hex);
    while (*++p != '\0')
    {
        // printf("%c", *p);
        // if (('a' <= *p) && (*p <= 'z'))
        if (*p >= 97)
            // hex[i] = hex[i] - 32;
            //     // hex[i] = 'A' + (hex[i] - 'a');
            // *p = 'A' + (*p - 'a');
            *p -= 32;
        //*p = 'F';
    }
    p--;
    while (*p != '\0')
    {
        printf("%c %d %d, ", *p, *p >= 48, *p <= 59);
        if (*p >= 48 && *p <= 59)
        {
            res += (*p - '0') * weight;
            weight *= 16;
        }
        else if (*p >= 65 && *p <= 70)
        {
            res += (*p - 'A' + 10) * weight;
            weight *= 16;
        }
        p--;
    }
    return res;
}

int main()
{
    char teste[] = "abcd";
    char *p = teste;
    /*printf("%c", *++p);
    printf("%c", ++*p); */
    // printf("\n%i", stringHexToInt("#1FFfff"));
    // printf("\n%i", stringHexToInt("#1FFf00"));
    // printf("\n%i", stringHexToInt("#1FFabf"));
    // printf("\n%i", stringHexToInt("#1F3fff"));
    // printf("\n%i", stringHexToInt("#1abcff"));
    printf("\n%i", stringHexToInt("#1FFfff"));
    return 0;
}