#include<stdio.h>
#include<string.h>

char xor(char a, char b);
const char* mod2div(char msg[], char div[], int msglen, int divlen);
const char* CRC(char msg[], char div[]);

int main()
{
    static char msg[50], div[50];
    char *checksum;
    printf("Enter a message\n");
    scanf("%s", msg);
    printf("Enter Divisor\n");
    scanf("%s", div);
    printf("Original Message %s\n", msg);
    printf("Divisor : %s\n", div);
    checksum = CRC(msg, div);
    printf("Checksum : %s\n", checksum);
}