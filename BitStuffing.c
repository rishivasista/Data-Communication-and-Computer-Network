#include <stdio.h>
#include <String.h>

char* stuffBits(char msg[])
{
    char newMsg[100] = "", flag0[6] = "00000", flag1[6] = "11111", *temp;
    int i, j, k, x, count0, count1, len;
    len = strlen(msg);
    i = 0;
    x = 5;
    strcat(newMsg, "00000");
    while (i < len)
    {
        j = 0;
        count0 = 0;
        count1 = 0;
        k = 0;
        while (j < 6)
        {
            newMsg[x++] = msg[i];
            if (msg[i] == flag0[j] || msg[i] == flag1[k])
            {
                
                if (msg[i] == flag0[j])
                {
                    j++;
                    count0++;
                }
                else
                {
                    k++;
                    count1++;
                }
                i++;
            }
            else

                i++;

            if (count0 == 5 || count1 == 5)
            {
                if (count0 == 5)
                {
                    strcat(newMsg, "1");
                    x++;
                }
                else
                {
                    strcat(newMsg, "0");
                    x++;
                }
                break;
            }
            else if ((count0 > 1 && msg[i] != flag0[j]) || (count1 > 1 && msg[i] != flag1[k]))
            {
                break;
            }
        }
    }
    strcat(newMsg, "11111");
    temp = newMsg;
    return temp;
}

int main()
{
    char msg[100], *newMsg;
    printf("Enter a message\n");
    scanf("%s", msg);
    newMsg = stuffBits(msg);
    printf("%s", newMsg);
}