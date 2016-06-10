#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    int midLenStr =   len + 1;
    int index = 0;
    int isAdd = 1;
    int i =  0;


    /**
    * 我去，要骂娘，leetcode 在内容分配较少的时候出现下面的错误
    *Run Code Status: Runtime Error
    * eg: "iwjrfduujgrkuddsfkjjwqjjoiaptulbquv"
    *      2
    * 可以在对分配的内容每次都分配的很内容
    * char *tmpRes = (char *) malloc((midLenStr*numRows + 100) * sizeof(char));
    *    char *ret = (char *)malloc((len+100) * sizeof(char));
    *    就可以通过了
    */

    char *tmpRes = (char *) malloc((midLenStr*numRows) * sizeof(char));
    char *ret = (char *)malloc((len+1) * sizeof(char));
    char *arrRes[numRows] ;

    char *p = NULL ;


    memset(tmpRes,0, midLenStr*numRows);
    memset(ret,0, len+1);


    if(numRows == 1 ) {
        strncpy(ret, s, len+1);
        return ret;
    }

    arrRes[0] = tmpRes;
    for(i = 1; i < numRows; i++) {
        arrRes[i] = arrRes[i-1] + midLenStr;
    }

    while (index < len ) {
        i = 0;
        while(i < numRows && index < len ) {
            *arrRes[i] = s[index++];
            arrRes[i++] ++;
        };
        i = numRows - 2;
        while(i > 0 && index < len  ) {
            *arrRes[i] = s[index++];
            arrRes[i--] ++;
        }
    }


    i = 0;
    p = tmpRes;
    len += 1;
    while(i < numRows) {

        //sprintf(ret, "%s%s", tmpRes, p);
        //printf("%s --- %s\n", ret, p);
        strncat(ret, p, len);

        p = p + midLenStr;
        i ++;
    }


    return ret;
}

int main(int *argc, char *argv[])
{
    char *ret ;
    char p[] =  "abc";

    ret = convert(p, 2);
    printf("%s\n", ret);
}

