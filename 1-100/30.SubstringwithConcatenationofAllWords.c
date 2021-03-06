#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//注意重复子串， 注意 子串与主串相等
//注意子串重复数据






void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int cmpInt(void const *a , void const *b) {
    return *(int *)a - *(int *)b;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    
    int mapCount ;
    int *map = (int *)malloc(sizeof(int)*wordsSize) ;
    int slen = strlen(s);
    int wslen = 0;
    int i ;
    int *ret = (int *)malloc(sizeof(int)*slen);

    *returnSize = 0;
    if(slen == 0) {
        return NULL;
    }
    if(wordsSize == 0) {
        return NULL;
    }
    wslen = strlen(words[0]);

    if(wslen*wordsSize > slen) {
        return NULL;
    }
    

    for(i = 0; i < wordsSize; i++) {
        //leetcode已第一个参数的长度为准 好坑
        /*if(wslen != strlen(words[i])) {
            return NULL;
        }*/
        map[i] = i;
    }


    char *ptr = s;
    char  *next ;

    int tmp = 0;
    int wordsIndex = 0;
    int isRepeat = 0;
    for(wordsIndex = 0; wordsIndex < wordsSize; wordsIndex++) {
        for(i = 0; i < wordsSize; i++) {
            if(i < wordsIndex && strncmp(words[i], words[wordsIndex], wslen) == 0) {
                isRepeat = 1;
            }
            map[i] = i;
        }
        if(isRepeat) {
            isRepeat = 0;
            continue;
        }

        
        swap(&map[wordsIndex], &map[wordsSize-1]);
        ptr = s;
        while(ptr = strstr(ptr, words[wordsIndex])) {
            
            mapCount = wordsSize - 1;
            next = ptr + wslen;

            int index = 0;
            if(mapCount == 0 ) {
                ret[*returnSize] = ptr - s;
                *returnSize += 1;
                ptr ++;
                continue;
            }
            if(*next == 0 ) {
                break;
            }
            while(index < mapCount) {
                if(strncmp(next, words[map[index]], wslen) == 0) {
                    mapCount--;
                    if(mapCount == 0) {
                        ret[*returnSize] = ptr - s;
                        *returnSize += 1;

                        break;
                    }
                    swap(&map[mapCount], &map[index]);
                    index = 0;
                    next += wslen;
                } else {
                    index++;
                }

               
            }
            
            ptr ++;

        }
    }
    qsort(ret, *returnSize, sizeof(int), cmpInt);
    return ret;
}




int main(int argc, char *argv[]) {
    //char *s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    //char *(sub[5]) = {"fooo","barr","wing","ding","wing"};
    //char *s = "a";
    //char *(sub[5]) = {"a"};
    //char *s = "aaaaaaaa";
    //char *(sub[5]) = {"aa","aa","aa"};
    char *s = "mississippi";
    char *(sub[5]) = {"is","aa","aa"};
    int returnSize = 0;
    int i = 0;

    int *map = findSubstring(s, sub, 1, &returnSize);

    for(i = 0; i < returnSize; i++) {
        printf("%d ", map[i]);
    }
    printf("\n");
}