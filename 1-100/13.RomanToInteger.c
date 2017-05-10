#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int romanToInt(char* s) {
    //char *digits[] = {"I","II", "III","IV","V","VI","VII", "VIII", "IX"};
    //char *tens[] = {"X", "XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    //char *hundreds[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *digits[] = {"IX","VIII", "VII","VI","V","IV","III", "II", "I"};
    char *tens[] = {"XC", "LXXX","LXX","LX","L","XL","XXX","XX","X"};
    char *hundreds[] = {"CM", "DCCC", "DCC", "DC", "D", "CD", "CCC", "CC", "C"};
    int a = 0, b = 0, c = 0, d = 0;
    int i = 9;
    int len = 0;

    while(*s == 'M') {
        a ++;
        s++;
    }

    for(i = 0; i < 9; i++) {
        len = strlen(hundreds[i]);
        if(strncmp(s, hundreds[i], len) == 0) {
            b = 9 - i;
            s += len;
            break;
        }
    }

    for(i = 0; i < 9; i++) {
        len = strlen(tens[i]);
        if(strncmp(s, tens[i], len) == 0) {
            c = 9 - i;
            s += len;
            break;
        }
    }

    for(i = 0; i < 9; i++) {
        len = strlen(digits[i]);
        if(strncmp(s, digits[i], len) == 0) {
            d = 9 - i;
            s += len;
            break;
        }
    }

    return (a*1000)+(b*100)+(c*10)+d;

}


int main(int *argc, char *argv[])
{

    printf("3536 %d\n", romanToInt("MMMDXXXVI"));

    return;
    printf("1, %d\n",  romanToInt("I"));
    printf("2, %d\n",  romanToInt("II"));
    printf("3, %d\n",  romanToInt("III"));
    printf("4, %d\n",  romanToInt("IV"));
    printf("5, %d\n",  romanToInt("V"));
    printf("6, %d\n",  romanToInt("VI"));
    printf("7, %d\n",  romanToInt("VII"));
    printf("8, %d\n",  romanToInt("VIII"));
    printf("9, %d\n",  romanToInt("IX"));
    printf("1O, %d\n",  romanToInt("X"));
    printf("11, %d\n",  romanToInt("XI"));
    printf("12, %d\n",  romanToInt("XII"));
    printf("13, %d\n",  romanToInt("XIII"));
    printf("14, %d\n",  romanToInt("XV"));
    printf("16, %d\n",  romanToInt("XVI"));
    printf("17, %d\n",  romanToInt("XVII"));
    printf("18, %d\n",  romanToInt("XVIII"));
    printf("19, %d\n",  romanToInt("XIX"));
    printf("2O, %d\n",  romanToInt("XX"));
    printf("90, %d\n",  romanToInt("XC"));
    printf("99, %d\n",  romanToInt("XCIX"));
    printf("100, %d\n",  romanToInt("C"));
    printf("101, %d\n",  romanToInt("CI"));
    printf("199, %d\n",  romanToInt("CXCIX"));
    printf("300, %d\n",  romanToInt("CCC"));
    printf("400, %d\n",  romanToInt("CD"));
    printf("500, %d\n",  romanToInt("D"));
    printf("600, %d\n",  romanToInt("DC"));
    printf("900, %d\n",  romanToInt("CM"));


}