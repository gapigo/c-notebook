#include <stdio.h>

int stringHexToInt(char _hex[])
{
    char hex[*_hex / sizeof(_hex[0])];
    for (int i = 0; _hex[i]; i++)
    {
        hex[i] = _hex[i];
    }
    char *p = hex;
    int weight = 1;
    int res = 0;
    while (*++p != '\0')
    {
        if (*p >= 97)
            *p -= 32;
    }
    p--;
    while (*p != '\0')
    {
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

void getRgbFromHex(int *rgb, int hex)
{
    int resto;
    int divisaoInteira;
    divisaoInteira = hex / (256 * 256);
    resto = hex % (256 * 256);
    rgb[0] = divisaoInteira;
    divisaoInteira = resto / 256;
    resto = resto % 256;
    rgb[1] = divisaoInteira;
    rgb[2] = resto;
}

int main()
{
    int rgb[3];
    getRgbFromHex(rgb, stringHexToInt("#1abcff"));
    printf("%d\n", stringHexToInt("#1abcff"));
    printf("(%d, %d, %d)", rgb[0], rgb[1], rgb[2]);
    return 0;
}