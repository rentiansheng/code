#include <stdio.h>
#include <stdlib.h>


int cmp(const void *p1, const void *p2) {
    return *(int*)p1 - *(int*) p2;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int *start, *end;
    int **ret , **row;
    int tmp;
    int sum;

    int i,j;
    
    *returnSize = 0;
    if(numsSize < 4) {
        return NULL;
    }

    ret =  (int**)malloc(sizeof(int*)*numsSize*4);
    row = ret ;

    qsort(nums, numsSize, sizeof(int), cmp);

    for(i = 0; i < numsSize; i++) {
        if(i > 0 && nums[i-1] == nums[i]) {
            continue;
        }
        for(j = i + 1; j < numsSize; j++) {
            if(j > (i+1) && nums[j-1] == nums[j]) {
                continue;
            }

            tmp = nums[i]+nums[j];

            start = nums +j + 1;
            end = nums + numsSize - 1;

            while(start < end ) {
                sum = tmp + *start + *end ;
                if(sum > target) {
                    end --;
                } else if(sum < target){
                    start ++;
                } else {
                    *row = (int*)malloc(sizeof(int)*4);

                    (*row)[0] = nums[i];
                    (*row)[1] = nums[j];
                    (*row)[2] = *start;
                    (*row)[3] = *end;
                    row++;
                    *returnSize += 1;
                    
                    start++;
                    while(*(start-1) == *start) {
                        start++;
                    }
                    end--;
                    while(*(end+1) == *end) {
                        end--;
                    }
                }
            }
        }
    }
    
    return ret;
}



int main(int argc, char *argv[]) {

    //int a[] = {1, 0, -1, 0, -2, 2};
    int a[] = {-4,-3,-2,-1,0,0,1,2,3,4};

    int len = sizeof(a)/sizeof(int);

    int **ret , *p;
    int returnSize = 0;
    int target = 0;
    int i = 0;

    ret = fourSum(a, len, target, &returnSize);

    printf("%d    %d\n", returnSize, target);
    
    for(i = 0; i< returnSize; i++) {
        printf("%d %d %d %d\n", ret[i][0], ret[i][1], ret[i][2], ret[i][3]);
    }

    
}