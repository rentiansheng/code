/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file twoNum.c
 * @author rentiansheng_iwm(com@baidu.com)
 * @date 2016/03/14 16:58:36
 * @brief 
 *  
 **/



#include <stdio.h>
#include <stdlib.h>



typedef struct {
    int v;
    int index;
}Node;

int cmp(const void *a, const void *b) 
{
    return ((Node *)a)->v - ((Node *)b)->v;
}



int* twoSum(int* nums, int numsSize, int target) {
    Node * dataNode = (Node *) malloc(sizeof(Node)*numsSize);
    int i = 0;
    Node *start, *end;
    int * ret = (int *) malloc(sizeof(int)*2);
    int tmp;
    ret[0] = 0;
    ret[1] = 1; 
    for(; i < numsSize; i++){
        dataNode[i].v = nums[i];
        dataNode[i].index = i;
    }

    qsort(dataNode, numsSize, sizeof(Node), cmp);
    
    start = dataNode;
    end = dataNode + (numsSize-1);
    while(start < end) {
        tmp = target - start->v - end->v;
        if(tmp == 0) {
            ret[0] = start->index;
            ret[1] = end->index;
            break;
        } else if(tmp < 0) {
            end --;
        } else {
            start ++;
        }
    }

    return ret;
    
}


int main(int argc, char *argv[]) 
{

    int numbers[] = {3,2,4};
    int target = 6;


    int *index = twoSum(numbers, sizeof(numbers) / sizeof(numbers[0]), target);

    int i;
    for (i = 0; i < 2; i++){
        printf("index%d = %d ", i + 1, index[i]);
    }
    printf("\n");

}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
