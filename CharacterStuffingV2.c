#include <stdio.h>
#include <String.h>

void stuffCharacters(char msg[])
{ 
    int i = 0, j, count,testFlag=0, count1, len, x;
    char flag[4]="DLE";
    len = strlen(msg);
    for (int x = 0; x < len; x++)
    {
        if(msg[x] >= 97 && msg[x]<=122)
        msg[x] = msg[x] - 32; 
        
        else
        continue;
    }
    printf("Before Stuffing\n");
    printf("%s\n", msg);
    printf("After Stuffing\n");
    printf("DLESTX");
    while (i < len)
    {
        count = 0;
        j = 0;
        count1=0;
        while (j < 6)
        {
            if (msg[i] == flag[j++])
            {
                i++;
                count++;
            }
            else
            {
                if (count == 1)
                {
                    printf("%c", msg[i-1]);
                    j = 0;
                    count=0;
                }
            }
            if (count == 3)
            {
                if(msg[i+1] == 'S' || msg[i+1] == 'E'){
                    if(msg[i+1] == 'S'){
                        testFlag = 1;
                    }
                    for(x = i+1; x<6; x++){
                        if(msg[x] == flag[x]){
                            count1++;
                        }
                    }
                    if(count1 == 3){
                        if(!testFlag){
                            // i+=3;
                            // testFlag = 0;
                            printf("DLEETXDLEETX");
                            break;
                        }
                        else{
                            // i+=3;
                            printf("DLESTXDLESTX");
                            break;
                        }
                    }
                }
                if(msg[i+1] != 'S' && msg[i+1] !='E'){
                printf("DLEDLE");
                break;
                }
            }
        }
        printf("%c", msg[i++]);
    }
    printf("DLEETX");
}

void main()
{
    char msg[50], flag[4] = "DLE";
    int i = 0, j, count, len;

    printf("Enter frame:\n");
    scanf("%s", msg);
    stuffCharacters(msg);
}
