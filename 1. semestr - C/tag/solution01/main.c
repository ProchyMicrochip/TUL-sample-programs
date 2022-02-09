//
// Created by kubap on 16.12.2021.
//

#include <stdio.h>
#include <string.h>

char text[1024] = "Kdyz ma slovo v textu pet pismen tak bude ohraniceno tagem";

void nahrad(){
    int lastpos = -1;
    char vystup[1024] ="";
    while(strchr(text,' ') != NULL){
        char* pos = strchr(text,' ');
        int ipos = (int)(pos - text);
        if(ipos - lastpos == 6){
            strcat(vystup,"<b>");
            strncat(vystup,&text[lastpos+1],5);
            strcat(vystup,"</b> ");
        } else strncat(vystup,&text[lastpos]+1,ipos-lastpos);
        text[ipos] = '0';
        lastpos = ipos;
    }
    if(lastpos == strlen(text) - 6){
        strcat(vystup,"<b>");
        strncat(vystup,&text[lastpos+1],5);
        strcat(vystup,"</b> ");
    } else{
        strncat(vystup,&text[lastpos+1], strlen(text) - lastpos);
    }
    strcpy(text,vystup);
}

int main() {

    nahrad();

    printf(text);
    return 0;
}