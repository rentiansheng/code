#include <stdio.h>
#include <stdlib.h>


/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

desc : 数字变化，变化的位数越低，对整个数值大小影响最小。
从最低位置开始依次向高位遍历。找到比当前位置最接近的较大数，
*/
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
    
    while(0 <= startIndex ) {//从最低位开始判断
        tmpIndex = startIndex ;
        //找到与当前位置最接近比较的值。
        for(nextIndex = startIndex + 1; nextIndex < numsSize; nextIndex++) {
            if(nums[startIndex] < nums[nextIndex]) {
                if(tmpIndex == startIndex) {//如果是第一个找到当前位置大的值记录位置
                    tmpIndex  = nextIndex;
                } else if(nums[tmpIndex] > nums[nextIndex]) {//已经存在比较大的值，返回比较大之中较小的
                    tmpIndex  = nextIndex;
                }
            }
        }
        //找到较大的值，对后边位数排序
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

void printIntArr(int *a, int nums) {
    int i = 0;

    for(i = 0; i < nums; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

}

void testCase(int * nums, int numsSize, char *s) {
    printIntArr(nums, numsSize);
    nextPermutation(nums, numsSize);
    printIntArr(nums, numsSize);
    printf("%s ac result\n", s);
    printf("------------------------\n");
}

int main() {

    int nums[] = {6,5,4,8,7,5,1};
    int len = sizeof(nums)/sizeof(int);

    testCase(nums, len, "6 5 5 1 4 7 8");
    

    int nums1[] = {6,4,5,4,8,7,5,1};
    int len1 = sizeof(nums1)/sizeof(int);

    testCase(nums1, len1, "6 4 5 5 1 4 7 8");


    int nums2[] = {6,4,5,4,8,7,5,6,1};
    int len2 = sizeof(nums2)/sizeof(int);

    testCase(nums2, len2, "6 4 5 4 8 7 6 1 5");

    int nums3[] = {1,2,3};
    int len3 = sizeof(nums3)/sizeof(int);

    testCase(nums3, len3, "1 3 2");

    int nums4[] = {3,2,1};
    int len4 = sizeof(nums4)/sizeof(int);

    testCase(nums4, len4, "1 2 3");

    int nums5[] = {1,1,5};
    int len5 = sizeof(nums5)/sizeof(int);

    testCase(nums5, len5, "1 5 1");

    int nums6[] = {4,2,0,2,3,2,0};
    int len6 = sizeof(nums6)/sizeof(int);
    testCase(nums6, len6, "4 2 0 3 0 2 2");

    int nums7[] = {2,3,0,2,4,1};
    int len7 = sizeof(nums7)/sizeof(int);
    testCase(nums7, len7, "2 3 0 4 1 2");

    return 0;
}