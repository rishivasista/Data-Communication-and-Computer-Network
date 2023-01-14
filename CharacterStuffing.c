#include <stdio.h>
#include <String.h>

void stuffCharacters(char msg[], char flag[])
{ 
    int i = 0, j, count, len, flaglen = strlen(flag) - 1;

    len = strlen(msg);
    for (int x = 0; x < len; x++)
    {
        msg[x] = msg[x] - 32;
    }
    printf("Before Stuffing\n");
    printf("%s\n", msg);
    printf("After Stuffing\n");
    printf("DLESTX");
    while (i < len)
    {
        count = 0;
        j = 0;
        while (j < flaglen)
        {
            if (msg[i] == flag[j++])
            {
                i++;
                count++;
            }
            else
            {
                if (count == 1)
                {
                    printf("%c", msg[i]);
                    j = 0;
                }
            }
            if (count == flaglen)
            {
                printf("DLEDLE");
            }
        }
        printf("%c", msg[i++]);
    }
    printf("DLEETX");
}

void main()
{
    char msg[50], flag[4] = "DLE";
    int i = 0, j, count, len;

    printf("Enter frame:\n");
    scanf("%s", msg);
    stuffCharacters(msg, flag);
    
}