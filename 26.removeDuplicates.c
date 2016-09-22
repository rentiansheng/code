#include <stdio.h>
#include <stdlib.h>




int removeDuplicates(int* nums, int numsSize) {
    int ret = 1;
    int i = 0;

    if(numsSize < 0) {
        return 0;
    }
    if(numsSize <= 1) {
        return numsSize;
    }
    for(i = 1; i < numsSize; i++) {
        if(nums[i-1] != nums[i]) {
            if(ret != i) {
                nums[ret] = nums[i];
            }
            ret++;
        }


    }

    return ret;

}


 int main(int argc, char *argv[]) {

     int no[] = {1,2,2,3,4,4,4,4,4};
     int len = sizeof(no)/sizeof(int) ;
     int ret = 0;
     int i ;




     ret = removeDuplicates(no,len);

     printf("%d \n", ret);
     for(i = 0; i < ret; i++) {
        printf("%d,", no[i]);
     }
     printf("\n");

 }