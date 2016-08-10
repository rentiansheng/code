#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* longestCommonPrefix(char** strs, int strsSize) {
    unsigned int minStrLen = 0;
    int minStrIndex = 0;
    int i = 0;
    int j = 0;
    int len = 0;
    char *ret = NULL;
    int retLen = 0;

    if(strs == NULL || *strs == NULL) {
        return "";
    }
    if( strsSize == 1 ) {
        return strs[0];
    }

    minStrLen= strlen(strs[0]);

    for(i = 1; i < strsSize; i++) {
        len = strlen(strs[i]);
        if(minStrLen > len) {
            minStrLen = len;
            minStrIndex = i;
        }
    }


    retLen = minStrLen + 1;
    ret = (char *)malloc(sizeof(char)*(retLen));
    memset(ret, 0, retLen);


    for(i = 0; i < minStrLen; i++) {
        for(j = 0; j < strsSize; j++) {
            if(strs[j][i] == 0 ||  strs[minStrIndex][i] != strs[j][i]) {
                ret[i] = 0;
                return ret;
            }
            ret[i] = strs[0][i];

        }
    }

    return ret;
}


int main() {

    char *p[] = {"a","ac"};

    char *ret = longestCommonPrefix(p, 2);

    printf("%s \n", ret);
}