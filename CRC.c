#include<stdio.h>
#include<string.h>

char* addRedundant(char poly1[], char poly2[]){
    int i, l2;
    char *temp;
    l2 = strlen(poly2);
    for(i=0; i<l2-1; i++)
        strcat(poly1, "0");
    temp = poly1;
    return temp;
}

char* CRC(char poly1[], char poly2[]){
    int i, j, l1, l2;
    l1 = strlen(poly1);
    l2 = strlen(poly2);
    for(i=0;i<l1;i++)
    {
        for(j=0;j<l2;j++){
            
        }
    }
}

int main(){
    char poly1[100], poly2[100], *newMsg;
    printf("Enter a String of 0s and 1s\n");
    gets(poly1);
    printf("Enter another String of 0s and 1s\n");
    gets(poly2);
    newMsg = addRedundant(poly1, poly2);
    puts(newMsg);
}