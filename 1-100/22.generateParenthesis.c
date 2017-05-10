#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
该问题和《编程之美》的买票找零问题一样，通过买票找零问题我们可以知道，
针对一个长度为2n的合法排列，第1到2n个位置都满足如下规则：左括号的个数大于等于右括号的个数。
所以，我们就可以按照这个规则去打印括号：假设在位置k我们还剩余left个左括号和right个右括号，
如果left>0，则我们可以直接打印左括号，而不违背规则。能否打印右括号，我们还必须验证left和right的值是否满足规则，
如果left>=right，则我们不能打印右括号，因为打印会违背合法排列的规则，否则可以打印右括号。如果left和right均为零，
则说明我们已经完成一个合法排列，可以将其打印出来。通过深搜，我们可以很快地解决问题，针对n=2
*/

void generate(int left, int right, char *s, int index ,char** ret, int *returnSize) {
    if(left == 0 && right == 0) {
        char *p = (char *)malloc(sizeof(char)*(index+1));
        char **row = ret + (*returnSize);
        strncpy(p, s, index);
        p[index] = 0;
        *(row) = p;
        (*returnSize)++;
    }
    if(left > 0 ) {
        s[index] = '(';
        generate(left-1, right, s, index+1, ret, returnSize);
    }
    if(right > 0 && left < right) {
        s[index] = ')';
        generate(left, right-1, s, index+1, ret, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {

    char ** ret = (char **)malloc(sizeof(char*)*(4*n*n*n));
    char *s = (char*)malloc(sizeof(char)*(n+n+1));
    *returnSize = 0;


    generate(n, n, s, 0, ret, returnSize);

    return ret;

}


int main(int argc, char *argv[]) {
    int returnSize = 0;
    int i;
    char ** ret;

    ret = generateParenthesis(7, &returnSize);

    printf("\n%d \n", returnSize);

    for(i=0; i<returnSize; i++) {
        printf("%s\n", ret[i]);
    }


}