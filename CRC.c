#include<stdio.h>
#include<math.h>

unsigned int addRedundant(unsigned int p1, unsigned int p2){
    unsigned int div = p2, temp;
    int count=0, i;
    while(div!=0){
        div/=10;
        count++;
    }
    // Adding redundant zeros to p1 based on the size of p2
    temp = pow(10, count-1); // Contains value to be multiplied to p1 in order to get redundant zeros
    p1 *= temp;
    return p1;
}



int main(){
    unsigned int p1, p2;
    printf("Enter Message\n");
    scanf("%u", &p1);
    printf("Enter Divisor\n");
    scanf("%u",&p2);
    p1=addRedundant(p1, p2);
    printf("%u\n", p1);
}