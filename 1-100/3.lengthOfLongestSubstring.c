#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int getCount(int a[], int size)
{
    int ret = 0;
    int i = 0;
    while(i < size) {
        if(a[i++]) {
            ret ++;
        }

    }

    return ret;
}

int lengthOfLongestSubstring(char* s)
{

    int a[255] ;
    int len = strlen(s);
    int cur = 1;
    int lenSub = 1;
    int tmp = 1;
    int i;

    memset(a, 0, sizeof(int)*255);

    if(len == 0) {
        return 0;
    }

    a[s[0]] = 1;
    while(cur < len) {
        if(a[s[cur]]) {
            tmp = getCount(a, 255);
            if(tmp > lenSub) {
                lenSub = tmp;
            }
            tmp = a[s[cur]];
            for(i=0; i < 255; i++) {
                if(a[i] < tmp) {
                    a[i] = 0;
                }
            }

        }
        a[s[cur]] = ++cur;
    }

    tmp = getCount(a, 255);
    if(tmp > lenSub) {
        lenSub = tmp;
    }

    return lenSub;

}

int main(int *argc, char *argv[])
{
    char s[255] = "anviaj";
    int ret = lengthOfLongestSubstring(s);
    printf("%s %d\n", s, ret);

    strcpy(s,"au");
    ret = lengthOfLongestSubstring(s);
    printf("%s %d\n", s, ret);

    strcpy(s,"abcabcbb");
    ret = lengthOfLongestSubstring(s);
    printf("%s %d\n", s, ret);

    strcpy(s, "bbb");
    ret = lengthOfLongestSubstring(s);
    printf("%s %d\n", s, ret);


}
