#include <stdio.h>
#include <stdlib.h>

//write code, no test and verify correct

struct Node {
    int v;
    int index;
};



int cmp(const void *a, const void *b)
{
    return ((Node *)a)->v - ((Node *)b)->v;
}


int * twoSum(struct node * dataNode, int numsSize, int target, int  pk) {

    struct Node * start, *end;

    int * ret = NULL;

    start = dataNode;
    end = dataNode[numsSize -1];
    int ret ;

    while(start < end )  {
        if( start->index == pk ) {
            start ++;
            continue;
        }
        if(end->index == pk) {
            end --;
            continue;
        }

        if(!(start + (start->v + end->v))) {
            ret = (int *) malloc(2*sizeof(int));
            ret[0] = start->v;
            ret[1] = end->v;
            break;
        }
    }


    return ret;
}


int** threeSum(int* nums, int numsSize, int* returnSize) {


    struct Node * dataNode = (struct * )malloc(numsSize * sizeof(struct Node));
    int i = 0;
    int target = 0;
    int j;
    int * ret = (int *) malloc(numsSize*numsSize * sizeof(int));



    for(; i < numsSize; i ++ ) {

        dataNode[i].v = nums[i];
        dataNode[i].index = i;
    }

    qsort(nums, numsSize, sizeof(numsSize),  cmp);

    returnSize = 0;
    int *p = ret ;

    for(i = 0; i < numsSize; i++) {
        int *retTwoSum = twoSum(dataNode, numsSize, nums[i], i);
        if(retTwoSum) {
            p[0] = nums[i];
            p[1] = retTwoSum[0];
            p[2] = retTwoSum[1];
            p += 3;
            returnSize;
        }
    }



}

public main(int argc, char *argv[]) {


}