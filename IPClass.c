#include<stdio.h>
#include<string.h>


void checkClass(char ip[100])
{
    int i=1, j=1, k=1, l=1, len, x, temp=0;
    len = strlen(ip);
    sscanf(ip, "%d.%d.%d.%d", &i, &j, &k, &l);

    if(i >=1 && i<=126)
    printf("%s belongs to class A IP Addressing\n", ip);
    else if(i >=128 && i<=191)
    printf("%s belongs to class B IP Addressing\n", ip);
    else if(i>=192 && i<=223)
    printf("%s belongs to class C IP Addressing\n", ip);
    else if(i>=224 && i<=239)
    printf("%s belongs to class D IP Addressing\n", ip);
    else if(i>=240 && i<=254)
    printf("%s belongs to class E IP Addressing\n", ip);
    else
    printf("Invalid IP Address\n");
}
int main(){
    char ip[100];
    printf("Enter the ipaddress separate by '.'\n");
    scanf("%s", ip);
    checkClass(ip);
}