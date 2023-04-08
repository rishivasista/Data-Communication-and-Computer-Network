#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binConverter(int x)
{
    int bin = 0, rem, temp = 1;
    while (x > 0)
    {
        rem = x % 2;
        bin = bin + (rem * temp);
        temp = temp * 10;
        x /= 2;
    }
    return bin;
}

char *adjustZeros(int a, int width)
{
    char *temp1 = (char *)malloc((width + 1) * sizeof(char));
    char *temp2 = (char *)malloc((width + 1) * sizeof(char));
    int len, i;
    sprintf(temp1, "%d", a);
    len = strlen(temp1);
    if (len == width)
    {
        temp2 = temp1;
        return temp2;
    }

    else
    {
        for (i = 0; i < (width - len); i++)
        {
            strcat(temp2, "0");
        }
    }
    strcat(temp2, temp1);
    return temp2;
}

void convertToBin(char ip[100])
{
    int i, j, k, l, len;
    char *temp = (char *)malloc(9 * sizeof(char));
    char *final = (char *)malloc(9 * sizeof(char));
    sscanf(ip, "%d.%d.%d.%d", &i, &j, &k, &l);
    i = binConverter(i);
    j = binConverter(j);
    k = binConverter(k);
    l = binConverter(l);
    temp = adjustZeros(i, 8);
    strcat(final, temp);
    strcat(final, " ");
    temp = adjustZeros(j, 8);
    strcat(final, temp);
    strcat(final, " ");
    temp = adjustZeros(k, 8);
    strcat(final, temp);
    strcat(final, " ");
    temp = adjustZeros(l, 8);
    strcat(final, temp);

    printf("%s in binary is %s\n",ip,final);
}

int main()
{
    char ip[100];
    printf("Enter an IP Address seperated by '.'\n");
    scanf("%s", ip);
    convertToBin(ip);
}