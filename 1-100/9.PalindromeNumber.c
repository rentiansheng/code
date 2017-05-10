#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>

#define bool int

int reverse(int x) {
    int bl = 1;
    long ret = 0;
    int i = 0;

    if(x == 0) {
        return x;
    }

    if(x < 0) { bl = 0; x = -x;}

    while(x > 0) {
        i = x%10;
        x = x/10;

        ret = ret*10 + i;
    }

    if(bl == 0) {
        ret = -ret;
    }

    if(ret != (int)ret) {
        return 0;
    }

    return (int)ret;

}

bool isPalindrome(int x) {
    int rx = 0;

    if(x < 0） {
        return false;
    }
    rx = reverse(x);

    return x == rx;
}


int main(int *argc, char *argv[])
{
    int ret = 0;

    ret = isPalindrome(-2147447412);
    printf("%d\n", ret);

}