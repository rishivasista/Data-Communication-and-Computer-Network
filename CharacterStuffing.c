#include <stdio.h>
#include <String.h>

void stuffCharacters(char msg[]);

void stuffCharacters(char msg[])
{
    int len, i, j, count;
    char newMsg[100] = "";
    len = strlen(msg);
    for (i = 0; i < len; i++)
    {
        if (msg[i] >= 97 && msg[i] <= 122)
            msg[i] -= 32;
    }
    i = 0;
    j = 6;
    strcat(newMsg, "DLESTX");
    while (i < len)
    {
        if (msg[i] == 'D' && msg[i + 1] == 'L' && msg[i + 2] == 'E')
        {
            if (msg[i + 4] == 'T' && msg[i + 5] == 'X')
            {
                if (msg[i + 3] == 'S')
                {
                    strcat(newMsg, "DLESTXDLESTX");
                    i += 6;
                    j = i + 12;
                }
                else if (msg[i + 3] == 'E')
                {
                    strcat(newMsg, "DLEETXDLEETX");
                    i += 6;
                    j = i + 12;
                }
            }

            else
            {
                strcat(newMsg, "DLEDLE");
                i += 3;
                j = i + 9;
            }
        }
        else
        {
            newMsg[j] = msg[i];
            i++;
            j++;
        }
    }
    strcat(newMsg, "DLEETX");
    printf("Original Message : %s\n", msg);
    printf("After Stuffing : %s\n", newMsg);
}

int main()
{
    char msg[100];
    printf("Enter a message\n");
    scanf("%s", msg);
    stuffCharacters(msg);
}
