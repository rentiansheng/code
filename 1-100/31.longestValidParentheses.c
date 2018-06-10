#include <stdio.h>

int main() {
    
}


int cmpInt(const void *a, const void * b) {
    return *(int *)a - *(int *)b;
}

void swapInt(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void nextPermutation(int* nums, int numsSize) {
    int startIndex = numsSize - 1;
    int nextIndex = startIndex + 1;
    int tmpIndex = startIndex;

    if(2 > numsSize) {
        return ;
    }
    
    while(0 <= startIndex ) {
        tmpIndex = startIndex ;
        for(nextIndex = startIndex + 1; nextIndex < numsSize; nextIndex++) {
            if(nums[startIndex] < nums[nextIndex]) {
                if(tmpIndex == startIndex) {
                    tmpIndex  = nextIndex;
                } else if(nums[tmpIndex] > nums[nextIndex]) {
                    tmpIndex  = nextIndex;
                }
            }
        }
        if( tmpIndex  != startIndex) {
            swapInt(nums+startIndex, nums+tmpIndex);
            qsort(nums+startIndex + 1, numsSize - startIndex - 1, sizeof(int), cmpInt);
            return ;
        }
        startIndex--;
    }
  
    
    qsort(nums, numsSize, sizeof(int) , cmpInt);

    return;
}