#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char** letterCombinations(char* digits, int* returnSize) {

    char **ret , **row ;
    char *digitsChr[] = {"_", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int  mallocLen = 1;
    int slen = strlen(digits);
    int i,j;
    char *p = digits;
    int *index = (int *) malloc(sizeof(int) * slen);
    int strIndex = 0;
    int sslen = slen-1;


    if(slen == 0) {
        return NULL;
    }
    if(strchr(digits, '0')) {
        return NULL;
    }
    if(strchr(digits, '1')) {
        return NULL;
    }

    i = 0;
    while(i < slen) {
        index[i] = 0;
        mallocLen *= 4;
        i++;
    }
    *returnSize = 0;

    ret = (char **)malloc(sizeof(char*)*mallocLen);
    row = ret;



    while(strIndex >= 0) {

        if(strIndex == slen) {
            p = (char *) malloc(sizeof(char)*(slen+1));

            *row = p;


            for(i = 0; i < slen; i++) {
                (*row)[i] = (char)digitsChr[digits[i]-'0'][index[i]];
            }
            (*row)[slen] = 0;
            row ++;
            *returnSize += 1;
            index[strIndex] = 0;
            strIndex--;
            if(strIndex >= 0) {
                index[strIndex]++;
            }
        } else {
            if(digitsChr[digits[strIndex]-'0'][index[strIndex]]  == 0) {
                index[strIndex] = 0;
                strIndex--;
                if(strIndex >= 0) {
                    index[strIndex]++;
                }

            } else {
                strIndex++;
            }
        }
    }



    return ret;
}




int main(int argc, char *argv[]) {

    //Input:Digit string "23"
    //Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

    char *digits = "23";
    int returnSize = 0;
    char ** ret ;
    int i;

    ret = letterCombinations("234456", &returnSize);

    printf("\n%d \n", returnSize);

    for(i=0; i<returnSize; i++) {
        printf("%s\n", ret[i]);
    }




}