#include<stdio.h>
#include<string.h>

char xor(char a, char b);
const char* mod2div(char msg[], char div[], int msglen, int divlen);
const char* CRC(char msg[], char div[]);

char xor(char a, char b)
{
    if(a==b)
    return '0';
    else
    return '1';
}

const char* mod2div(char msg[], char div[], int msglen, int divlen)
{
    int i, j;
    static char rem[50], temp[50];
    const char *final_rem;
    for(i=0;i<divlen;i++)
    rem[i] = msg[i];

    for(j=divlen; j<=msglen;j++)
    {
        for(i=0;i<divlen;i++)
        temp[i] = rem[i];

        // Shift contents of remainder to left by 1 if 1st bit is 0;
        if(rem[0] == '0')
        {
            for(i=0;i<divlen-1;i++)
            rem[i] = temp[i+1];
        }

        // Perform XOR operation to remainder if 1st bit is not 0;
        else
        {
            for(i=0;i<divlen-1;i++)
            rem[i] = xor(temp[i+1], div[i+1]);
        }
        rem[divlen-1] = msg[j];
    }
    final_rem = rem;
    return rem;
}

const char* CRC(char msg[], char div[])
{
    const char *checksum, *rem;
    int msglen, divlen, i;
    msglen = strlen(msg);
    divlen = strlen(div);
    rem = mod2div(msg, div, msglen, divlen);
    strcat(msg, rem);
    checksum = msg;
    printf("Remainder : %s\n", rem);
    return checksum;
}

int main()
{
    static char msg[50], div[50];
    const char *checksum;
    printf("Enter a message\n");
    scanf("%s", msg);
    printf("Enter Divisor\n");
    scanf("%s", div);
    printf("Original Message %s\n", msg);
    printf("Divisor : %s\n", div);
    checksum = CRC(msg, div);
    printf("Checksum : %s\n", checksum);
}