#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>


int myAtoi(char* str) {
    unsigned  long long ret = 0l;

    int bl = 1;
    char *p = str;

    while(*p == ' ') {
        p ++;
    }

    if(*p == '-') {
        bl = 0;
        p ++;
    }else if(*p == '+') {
        p++;
    } else if(*p < '0' || *p > '9') {
        return 0;
    }

    while(*p && *p >= '0' && *p <= '9') {
        ret = ret*10 + (*p - '0');
        //注意溢出有两种的，一种是超出最大值，另外一种是有正数变成负数
        //最大的负数比正数多一个
        if((ret && ret -1 > INT_MAX) || ret < 0) {
          if(bl ) {
            return INT_MAX;
          } else {
            return INT_MIN;
          }
        }
        p ++;
    }

    if(bl == 0) {
        if((ret - 1) == (INT_MAX)) {
            return INT_MIN;
        }
        ret = -ret;
    }else if(ret > INT_MAX) {
        return INT_MAX;
    }

    if(ret != (int)ret) {
        return 0;
    }

    return ret;



}

int main(int *argc, char *argv[])
{
    int ret = 0;

    /*ret = myAtoi("123");
    printf("%d\n", ret);

    ret = myAtoi("-123");
    printf("%d\n", ret);

    ret = myAtoi("0");
    printf("%d\n", ret);

    ret = myAtoi("-0");
    printf("%d\n", ret);

    ret = myAtoi("-aaaaaaa0");
    printf("%d\n", ret);*/


    ret = myAtoi("010");
        printf("%d\n",ret);
}