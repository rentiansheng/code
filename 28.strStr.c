#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int s1 = strlen(haystack);
    int s2 = strlen(needle);
    int ret = -1;
    int i, j, index;

    if(s1 == 0 && s2 ==0) {
        return 0;
    }
    if(s2 > s1) {
        return -1;
    }

    for(i = 0; i <= (s1 - s2); i++) {
        index = i;
        for(j = 0; j < s2; j++) {
            if(haystack[index++] != needle[j]) {
                break;
            }

        }
        if(j == s2) {
            ret = i;
            break;
        }
    }

    return ret;
}

int main(int argc, char *argv[]) {
    char *haystack = "abcedfghigkhhhhabac";

    printf("a %d\n", strStr(haystack, "a"));
    printf("abc %d\n", strStr(haystack, "abc"));
    printf("hh %d\n", strStr(haystack, "hh"));
    printf("hhha %d\n", strStr(haystack, "hhha"));
    printf("habc %d\n", strStr(haystack, "haba"));
    printf("a %d\n", strStr("a", "a"));


}