#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int mid = nums1Size + nums2Size ;
    int index = 0, i = 0, j = 0;
    int isOdd = mid&1;
    int pre, last ;
    mid = mid/2;


    while( mid >= index && i < nums1Size && j < nums2Size) {
        pre = last;
        if(nums1[i] < nums2[j]) {
            last = nums1[i];
            i++;
        } else {
            last = nums2[j];
            j++;
        }
        index++;
    }
    while( mid >= index && i < nums1Size) {
        pre = last;
        last = nums1[i++];
        index++;
    }
    while(mid >= index && j < nums2Size) {
        pre = last;
        last = nums2[j++];
        index++;
     }



    if(isOdd) {
        return (double)last;
    } else {
        return (pre + last)/2.0;
    }

}

int main(int *argc, char *argv[])
{
    int num1[] = {};
    int num2[] = {1};
    int ret = 0;

    ret = findMedianSortedArrays(num1, 0, num2, 1);
    printf("%d\n", ret);
}
