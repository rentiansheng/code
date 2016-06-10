#include <stdio.h>
#include <stdlib.h>
#include <memory.h>



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

int main(int *argc, char *argv[])
{
    int ret = 0;

    ret = reverse(123);
    printf("%d\n", ret);

    ret = reverse(-123);
    printf("%d\n", ret);
}