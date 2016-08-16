#include <stdio.h>
#include <stdlib.h>

//write code, no test and verify correct

struct Node {
    int v;
    int index;
};



int cmp(const void *a, const void *b)
{
    return ((struct Node *)a)->v - ((struct Node *)b)->v;
}


int * twoSum(struct Node * dataNode, int numsSize, int * retSize, int target, int  pk) {

    struct Node * start, *end;

    int * ret = (int *) malloc(numsSize*sizeof(int));
    int tmp = 0;

    *retSize = 0;
    start = dataNode;
    end = dataNode + numsSize -1;
    int * retP = ret ;

    while(start < end )  {
        if( start->index == pk ) {
            start ++;
            continue;
        }
        if(end->index == pk) {
            end --;
            continue;
        }

        tmp = target + (start->v + end->v);

        if(tmp == 0) {
            *retP = start->v;
            retP++;
            *retP = end->v;
            retP++;
            (*retSize)++;
            start++;
            end--;
        }else if(tmp < 0) {
            start ++;
        } else {
            end --;
        }
    }


    return ret;
}


int** threeSum(int* nums, int numsSize, int* returnSize) {


    struct Node * dataNode = (struct Node * )malloc(numsSize * sizeof(struct Node));
    int i = 0;
    int target = 0;
    int ** ret = (int **) malloc(numsSize * sizeof(int));
    struct Node * pre = NULL ;

    ret = (int **) malloc(numsSize * 3 *sizeof(int));

    for(; i < numsSize; i ++ ) {
        printf("addr %x\n", ret+i);
        dataNode[i].v = nums[i];
        dataNode[i].index = i;
    }

    qsort(dataNode, numsSize, sizeof(struct Node ),  cmp);

    *returnSize = 0;
    int **row = ret ;
    int rowIndex =0;
    int j = 0;
    int *p = NULL;
    int isAddRow = 1;
    int retTwoSumSize = 0;

    for(i = 0; i < numsSize; i++) {
        if(pre == NULL || pre->v != dataNode[i].v ) {
            int *retTwoSumPtr = twoSum(dataNode, numsSize, &retTwoSumSize, dataNode[i].v, dataNode[i].index);
            int *retTwoSum = retTwoSumPtr;

            while(retTwoSumSize--) {
                rowIndex = 0;
                //*row = (int *) malloc(3*sizeof(int));
                if( p == NULL) {
                    p  = (int *) malloc(3*sizeof(int));
                }
                if(dataNode[i].v <= retTwoSum[0]) {
                    p[rowIndex++] = dataNode[i].v;
                }
                p[rowIndex++] = retTwoSum[0];
                if(dataNode[i].v > retTwoSum[0] && dataNode[i].v < retTwoSum[1]) {
                    p[rowIndex++] = dataNode[i].v;
                }
                p[rowIndex++] = retTwoSum[1];
                if(dataNode[i].v >= retTwoSum[1]) {
                    p[rowIndex] = dataNode[i].v;
                }
                isAddRow = 1;
                for(j = 0; j < *returnSize; j ++) {
                    if(ret[j][0] == p[0] && ret[j][1] == p[1] && ret[j][2] == p[2]) {
                        isAddRow = 0;
                    }
                }
                if(isAddRow) {
                    *row = p;
                    p = NULL;
                    row ++;
                    *returnSize += 1;
                }
                retTwoSum += 2;
            }


            free(retTwoSumPtr);

        }
        pre = &dataNode[i];
    }

    return ret;


}

int main(int argc, char *argv[]) {

    //int a[] = {-1, 0, 1, 2, -1, -4};
    //int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    //int len = 15;
    int a[] = {-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3};
    int len = sizeof(a)/sizeof(int);

    int i = 0;
    int c = 0;
    int **ret;

    printf("%d\n", len);

    ret = threeSum(a, len, &c);

    int **p = ret;

    printf("%d\n", c);

    while(i++ < c) {
        printf("%x %d  %d  %d\n", p, (*p)[0], (*p)[1], (*p)[2]);
        p++;
    }



}