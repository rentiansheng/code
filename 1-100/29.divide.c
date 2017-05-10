#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

//注意符号， 主要时间，一个很大的数除以小数不要超时呀

int divide(int dividend, int divisor) {
    long int x1, x2,ret = 0, i  = 0, tmp = 0;
    int bl = 0;

    if(divisor == 0) {
        exit(0);
    }
    if(dividend == 0) {
        return 0;
    }
    x1 = dividend;
    x2 = divisor;
    if(dividend < 0 || divisor < 0) {
        if( dividend < 0) {
            x1 = -(long int)dividend;
            bl = !bl;
        }
        if(divisor < 0) {
            x2 = -(long int )divisor;
            bl = !bl;
        }
    }

    if(x2 == 1) {
        ret = x1;
    }else if(x1 == x2 ){
        return 1;
    } else {
        while( x2<<(i+1) <= x1) { i++;}
        while(x1 >= x2) {
            tmp = x1 - (x2<<i);
            if(tmp >= 0) {
                ret += (1<<i);

                x1 = tmp;

            }
            i--;
        }

    }

    if(bl == 1) {
        return -ret;
    }

    if(ret > INT_MAX || ret < INT_MIN) {
        return INT_MAX;
    }


    return ret;
}

int main(int argc, char *argv[]) {
    int x  = 1, d = 5;
    /*printf("%d/%d=%d\n", x, d, divide(x, d));
    x = 2, d = 1;
    printf("%d/%d=%d\n", x, d, divide(x, d));*/


    x = 2147483648, d = 2;//2147483647/2
    printf("%d/%d=%d\n", x, d, divide(x, d));

}