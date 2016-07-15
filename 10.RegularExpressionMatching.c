#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>


#define bool int

bool isMatch(char* s, char* p) {
    if(*p == 0) {
        return *s? 0: 1;
    }



    if( *(p+1) != '*') {
        if( (*s == *p) || (*p == '.' && *s != 0)  ) {
            return isMatch(s+1, p+1);
        } else {
            return 0;
        }
    }

    while( (*p == *s) || (*p == '.' && *s != 0 )) {
        if(isMatch( s, p+2)) { return 1;}
        s++;
    }



    return isMatch(s, p+2);
}


int main(int *argc, char *argv[])
{
    int ret ;

    /*ret = isMatch("aa","a");
    printf("false %d\n", ret);
    ret = isMatch("aa","aa");
    printf("true %d\n", ret);
    ret = isMatch("aaa","aa");
    printf("false %d\n", ret);*/
    ret = isMatch("a", "ab*");
    printf("true %d\n", ret);
    /*ret = isMatch("ab", ".*");
    printf("true %d\n", ret);
    ret = isMatch("aab", "c*a*b");
    printf("true %d\n", ret);*
    ret = isMatch("abcdede", "ab.*de");
    printf("true %d\n", ret);*/

}