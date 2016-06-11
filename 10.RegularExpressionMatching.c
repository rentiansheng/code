#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>


#define bool int

char * getNeedChar(char *p , int slen) {
    char * ret = (char *) malloc((slen + 1) * sizeof(char) );
    int index = 0;
    char  *retP = ret;

    while(index < slen) {
        if(p[index] != '*' && p[index + 1] != '*') {
            *retP = p[index];
            retP ++;
        }

        index ++;
    }
    retP = 0;
    return ret;
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