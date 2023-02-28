#include <stdio.h>
#include <string.h>

char xor (char a, char b);
const char *mod2div(char msg[], char div[], int msglen, int divlen);
const char *CRC(char msg[], char div[], int isReceiver);

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

const char *CRC(char msg[], char div[], int isReceiver)
{
    const char *checksum, *rem;
    int msglen, divlen, i;
    msglen = strlen(msg);
    divlen = strlen(div);
    rem = mod2div(msg, div, msglen, divlen);
    printf("Rem : %s\n", rem);
    // Code will check for errors if isReceiver is 1.
    if (isReceiver)
    {
        if (rem[0] == '0' && rem[1] == '0')
            printf("Message is correct\n");
        else
            printf("Error Detected\n");
    }
    strcat(msg, rem);
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
    printf("Original Message %s\n", msg);
    printf("Divisor : %s\n", div);
    // Passing 0 as a sender to skip error checking
    checksum = CRC(msg, div, 0);
    // Removing '/0' and last two remainder characters attached to string.
    for (i = 0; i <= strlen(checksum) - 3; i++)
        recvd[i] = checksum[i];
    printf("At Receiver side message : %s\n", recvd);
    printf("Divisor : %s\n", div);
    // Passing 1 as a receiver to check for errors.
    checksum = CRC(recvd, div, 1);
    printf("Received Checksum : %s\n", checksum);
}