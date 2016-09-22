#include <stdio.h>
#include <stdlib.h>


int cmp(const void * v1, const void *v2) {
    return *(int*)v1 - *(int*)v2;
}

int removeElement(int* nums, int numsSize, int val) {
    int ret = 0;
    int i ;

    qsort(nums, numsSize, sizeof(int), cmp);

    for(i = 0; i < numsSize; i++) {
        if(nums[i] == val) {
            continue;
        }
        if(i != ret) {
            nums[ret] = nums[i];
        }
        nums[ret] = nums[i];
        ret ++;
    }

    return ret;
}

int main(int argc, char *argv[]) {

    int no[] = {1,2,2,3,4,4,4,4,4};
    int len = sizeof(no)/sizeof(int) ;
    int ret = 0;
    int i ;




    ret = removeElement(no,len,4);

    printf("%d \n", ret);
    for(i = 0; i < ret; i++) {
        printf("%d,", no[i]);
    }
    printf("\n");

}