#include<stdio.h>
#include<String.h>

char* insertCharacter(char msg[], char ch, int index){
    char temp[100];
    char *newMsg;
    strncpy(temp, msg, index);
    temp[index] = ch;
    temp[index+1] = '\0';
    strcat(temp, msg + (index+1));
    newMsg = temp;
    return newMsg;
}


void stuffBits(char msg[]){
    char flag[6] = "11111", stuffedBits[100], *temp;
    int i, j, len, count;
    len = strlen(msg);
    for(i=0; i<len; i++){
        count = 0;
        j = 0;
        while(j < 5){
            if(msg[i] == flag[j++]){
                i++;
                count++;
            }

            
            if(count == 5){
                temp = insertCharacter(msg, '0', i-2);
                strcpy(stuffedBits, "");
                strcat(stuffedBits, "00000");
                strcat(stuffedBits, temp);
                strcat(stuffedBits, "11111");
                i++;
            }
        }
    }
    printf("%s", stuffedBits);
}

void main(){
    char bits[100], stuffedBit[100];
    printf("Enter the bits\n");
    scanf("%s", bits);
    stuffBits(bits);
}