#include<stdio.h>
#include<string.h>

void stuffBits(char msg[])
{
    int i, j, k, x, count0, count1, len;
    char flag0[6]="00000", flag1[6]="11111", newMsg[100];
    len = strlen(msg);
    printf("Before Stuffing : %s\n", msg);
    strcat(newMsg, "00000");
    x = 5;
    i=0;
    while(i<len)
    {
        j=0;
        k=0;
        count0=0;
        count1=0;
        
        while(j<6)
        {
            newMsg[x++] = msg[i];
            if(msg[i] == flag0[j] || msg[i] == flag1[j])
            {
                if(msg[i] == flag0[j])
                {
                    i++;
                    j++;
                    count0++;
                }
                else
                {
                    i++;
                    k++;
                    count1++;
                }
            }
            else
            i++;

            if(count0==5 || count1==5)
            {
                if(count0==5)
                {
                    strcat(newMsg, "1");
                    x++;
                    break;
                }
                else {
                    strcat(newMsg, "0");
                    x++;
                    break;
                }
            }
            else if((count0>1 && msg[i]!=flag0[j]) || (count1>1 && msg[i]!=flag1[k]))
            break;
        }
    }
    strcat(newMsg, "11111");
    
    printf("After Stuffing : %s\n", newMsg);
}

int main()
{
    char msg[100];
    printf("Enter your message\n");
    scanf("%s", msg);
    stuffBits(msg);
}
