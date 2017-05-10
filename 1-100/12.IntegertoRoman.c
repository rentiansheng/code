#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* intToRoman(int num) {
    char *digits[] = {"I","II", "III","IV","V","VI","VII", "VIII", "IX"};
    char *tens[] = {"X", "XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char *hundreds[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *thousand[] = { "M", "MM", "MMM"};
    int a,b,c,d;
    char * ret = (char *) malloc(sizeof(char)*1000) ;
    int len = 0;
    char *p = ret;

    a = num/1000;
    num -= a* 1000;
    b =  num/100;
    num -= b * 100;
    c = num / 10;
    num -= c * 10;
    d = num;

    if(a) {
        if(a>3) { a = 3; }
        a --;
        len = strlen(thousand[a]);
        strncpy(p, thousand[a], len );
        p += len;
    }

    if(b) {
        b--;
        len = strlen(hundreds[b]);
        strncpy(p, hundreds[b], len );
        p += len;
    }

    if(c) {
        c--;
        len = strlen(tens[c]);
        strncpy(p, tens[c], len );
        p += len;
    }
    if(d) {
        d--;
        len = strlen(digits[d]);
        strncpy(p, digits[d], len );
        p += len;
    }

    *p = 0;

    return ret;
}


int main(int *argc, char *argv[])
{
    char *p ;
    int i ;

        p = intToRoman(200);
        printf("%d  %s\n", i, p);
        free(p);



}