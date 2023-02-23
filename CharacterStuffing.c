#include <stdio.h>
#include <string.h>

void stuffCharacters(char msg[])
{
    char newMsg[100] = "";
    int count, i, len, x;
    len = strlen(msg);
    for (i = 0; i < len; i++)
    {
        if (msg[i] >= 97 && msg[i] <= 122)
            msg[i] -= 32;
    }
    i = 0;
    strcat(newMsg, "DLESTX");
    x = 6;
    while (i < len)
    {
        if (msg[i] == 'D' && msg[i + 1] == 'L' && msg[i + 2] == 'E')
        {
            if (msg[i + 4] == 'T' && msg[i + 5] == 'X')
            {
                if (msg[i + 3] == 'E')
                {
                    strcat(newMsg, "DLEETXDLEETX");
                    x += 12;
                    i += 6;
                }
                else
                {
                    strcat(newMsg, "DLESTXDLESTX");
                    x += 12;
                    i += 6;
                }
            }
            else
            {
                strcat(newMsg, "DLEDLE");
                x += 6;
                i += 3;
            }
        }
        else
        {
            newMsg[x] = msg[i];
            x++;
            i++;
        }
    }
    strcat(newMsg, "DLEETX");
    printf("Before Stuffing : %s\n", msg);
    printf("After Stuffing : %s\n", newMsg);
}

int main()
{
    char msg[100];
    printf("Enter your message\n");
    scanf("%s", msg);
    stuffCharacters(msg);
}
