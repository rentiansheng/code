#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;


bool isValid(char* s) {
    int len = strlen(s);
    char *left = (char *) malloc(sizeof(char)*len); 
    char *start = left;
    char *p = s;
    
    while(*p != 0) {
        if('(' == *p || '{' == *p || '[' == *p) {
            *start = *p;
            start++;
        }else if(')' == *p ) {
             if(start > left && '(' == *(start-1)) {
                start--;
            } else {
                return 0;
            }
        }else if('}' == *p ) {
            if(start > left && '{' == *(start-1)) {
                start--;
            } else {
                return 0;
            }
        } else if(']' == *p) {
            if(start > left && '[' == *(start-1)) {
                start--;
            } else {
                return 0;
            }
        }
        
        
        p++;
    }

    if(start == left) {
        return 1;
    }else {
        return 0;
    }

    



}

int main(int argc, char * argv[]) {




    printf(" %d\n", isValid("(([])){[]}"));

}