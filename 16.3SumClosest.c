#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp (const void * a1, const void *a2) {
    return *(int*)a1 - *(int *)a2;
}

int threeSumClosest(int* nums, int numsSize, int target) {


    int i;
    int  *start, *end;
    int ret = 0;
    int tmp ;
    int endLoc = numsSize -1;


    qsort(nums, numsSize, sizeof(int), cmp);

    if(numsSize < 3) {
        return -1;
    }

    ret = nums[0] + nums[1] + nums[2];
    for(i = 0; i < numsSize; i++) {
        if(i >0   && nums[i-1] == nums[i] ) {
            continue;
        }
        start = &nums[i+1];
        end = nums + endLoc;
        while(start < end) {

            tmp = nums[i] + *start + *end;

            if( abs(target - tmp) < abs(target - ret)) {
                ret = tmp;
            }
            if(tmp > target) {
                end --;
            } else if(tmp < target) {
                start ++;
            }else {
                start++;
                while(start < end && *(start-1) == *start) {
                    start++;
                }
                end--;
                while(end > start && *(start+1) == *start) {
                    end--;
                }

                return ret;
            }

        }
    }

    return ret;

}

int main(int argc, char *argv[]) {

    /*int a[] = {-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3};
    int target = 0;*/

    /*int a[] = {-1, 2, 1, -4};
    int target = 1;*/
    int a[]  ={0,2,1,-3};
    int target = 1;


    int len = sizeof(a)/sizeof(int);

    int i = 0;
    int c = 0;
    int ret;



    ret = threeSumClosest(a, len, target );



    printf("ret: %d target: %d\n", ret, target);





}