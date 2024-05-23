#include<stdio.h>

int main() {
    FILE*fp;
    fp = fopen("master.txt","r");
    if(fp==NULL){ printf("error"); fclose(fp);}

    int i=0;
    while(i<500) {
        char ch;
        ch  =  fgetc(fp);
        if(i%50 == 0 && ch==' ') 
         //printf("o");  
        // printf("%d=%c", i/50,ch);
        //else printf("%c", ch);
        i++;
    }
    fclose(fp);
    return 0;
}