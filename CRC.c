#include <stdio.h>
#include <string.h>

char xor (char a, char b);
const char *mod2div(char msg[], char div[], int msglen, int divlen);
const char *CRC(char msg[], char div[]);

char xor (char a, char b) {
    if (a == b)
        return '0';
    else
        return '1';
}

    const char *mod2div(char msg[], char div[], int msglen, int divlen)
{
    int i, j;
    static char rem[50], temp[50];
    const char *final_rem;
    for (i = 0; i < divlen; i++)
        rem[i] = msg[i];

    for (j = divlen; j <= msglen; j++)
    {
        for (i = 0; i < divlen; i++)
            temp[i] = rem[i];

        // Shift contents of remainder to left by 1 if 1st bit is 0;
        if (rem[0] == '0')
        {
            for (i = 0; i < divlen - 1; i++)
                rem[i] = temp[i + 1];
        }

        // Perform XOR operation to remainder if 1st bit is not 0;
        else
        {
            for (i = 0; i < divlen - 1; i++)
                rem[i] = xor(temp[i + 1], div[i + 1]);
        }

        // Add next bit of message to remainder for continuation of division
        rem[divlen - 1] = msg[j];
    }
    final_rem = rem;
    return rem;
}
const char *CRC(char msg[], char div[])
{
    const char *checksum, *rem;
    int msglen, divlen, i, tempdivlen;
    
    divlen = strlen(div);
    tempdivlen = divlen - 1;
    for (i = 0; i < tempdivlen; i++)
        strcat(msg, "0");
    
    msglen = strlen(msg);
    rem = mod2div(msg, div, msglen, divlen);
    printf("Checksum : %s\n", rem);
    printf("Transmitted Message %s\n", msg);
    //Accepting string at receiver side
    printf("Enter message received at receiver side: \n");
    scanf("%s", msg);
    strcat(msg, rem); // Overwriting original message.
    printf("Transmitted Message : %s\n", msg);
    rem = mod2div(msg, div, msglen, divlen);
    printf("Checksum : %s\n", rem);
    if (rem[0] == '0' && rem[1] == '0')
        printf("Message is correct\n");
    else
        printf("Error Detected\n");
    
    checksum = msg;
    return checksum;
}

int main()
{
    int i;
    static char msg[50], div[50], recvd[50] = "";
    const char *checksum;
    printf("Enter a message\n");
    scanf("%s", msg);
    printf("Enter Divisor\n");
    scanf("%s", div);
    // Passing 0 as a sender to skip error checking
    checksum = CRC(msg, div);
}