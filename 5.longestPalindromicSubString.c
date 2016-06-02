#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int findStrLen(char *s, int len ,int index, int offset) {
    int left = index;
    int right = index+offset;
    int ret = 0 ;

    while(left >= 0 && right < len && s[left] == s[right]) {
        left --;
        right ++;
        ret ++ ;
    }
    return ret;
}

char* longestPalindrome(char* s) {
    char  * subStr ;
    int len = strlen(s);

    int tmpRet[2] = {0,0};
    int i = 0;
    int subLen  = 0;
    int ret = 0;
    int maxSubLen = 0;
    int maxSubStart = 0;

    subStr = (char *) malloc(sizeof(char)*1001);
    memset(subStr, 0, 1001);
    for(i = 0; i < len; i++) {
        ret = findStrLen(s, len, i, 0);
        subLen = 2*ret - 1;
        if(subLen > maxSubLen) {
            maxSubLen = subLen;
            maxSubStart = i - ret + 1;
        }

        ret = findStrLen(s, len, i, 1);
        subLen = 2*ret ;
        if(subLen > maxSubLen) {
            maxSubLen = subLen;
            maxSubStart = i - ret + 1;
        }

    }
    if(maxSubLen > 1000) {
        maxSubLen = 1000;
    }

    snprintf(subStr, maxSubLen+1, "%s", s+maxSubStart  );

    return subStr;

}


int main(int *argc, char *argv[])
{
    char *s = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";
    char * ret = longestPalindrome(s);
    printf("%s\n", ret);
}
