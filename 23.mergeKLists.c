#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
 };

//对所有的数组做堆排序

void heapSortItem(struct ListNode ** heap, int size) {
    int heapCount  = size -1;
    struct ListNode * tmpNode = NULL;
    int left, right ;
    int i = 0;


    for(i= heapCount/2; i >= 0; i--) {
        left = 2*i +1;
        if(left > heapCount) {continue;}
        if(heap[i]->val > heap[left]->val) {
            tmpNode = heap[i];
            heap[i] = heap[left];
            heap[left] = tmpNode;
        }
        right = left+1;
        if(right > heapCount) {continue;}
        if(heap[i]->val > heap[right]->val) {
            tmpNode = heap[i];
            heap[i] = heap[right];
            heap[right] = tmpNode;
        }
    }

    i = 10;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    int i;
    int heapCount = 0;
    struct ListNode ** heap = (struct ListNode **)malloc(sizeof(struct ListNode*)*(listsSize));

    for(i=0; i < listsSize; i++) {
        if(lists[i] != NULL) {
           heap[heapCount] = lists[i];
           heapCount++;
        }
    }
    if(heapCount == 0 ){ return NULL;}
    if(heapCount == 1) {
        return heap[0];
    }


    heapSortItem(heap, heapCount);


    struct ListNode * head = heap[0];
    struct ListNode *node = head;


    while(heapCount > 1 ) {
        if(heap[0]->next == NULL ) {
            heap[0] = heap[heapCount-1];
            heapCount--;
        } else {
            heap[0] = heap[0]->next;
        }


        heapSortItem(heap, heapCount);

        node->next = heap[0];
        node = heap[0];
    }

    while(heap[0]->next != NULL){
        heap[0] = heap[0]->next;
        node->next = heap[0];
        node = heap[0];
    }




    return head;

}


int main(int argc, char *argv[]) {

//[[-8,-5,-4,-3,0,2,2,3],[3,3],[-4],[-10,-5,2],[-10,-7,-4,-3,-1,0,1,2],[-9,-9,-6,0,1,2,2]]

    struct ListNode l1[20], l2[20] ,l3[20],l4[20],l5[20],l6[20];
    struct ListNode *ret;
    struct ListNode **list;
    int listsSize = 7;
    int lenSize[7] = {8, 2, 1, 3, 7, 6,0};
    int i,j;
    list = (struct ListNode **)malloc(sizeof(struct ListNode *)*listsSize);
    list[0] = l1;
    list[1] = l2;
    list[2] = l3;
    list[3] = l4;
    list[4] = l5;
    list[5] = l6;



    //[[-8,-5,-4,-3,0,2,2,3]
    //,[3,3],
    //[-4],
    //[-10,-5,2],

    l1[0].val = -8;
    l1[1].val = -5;
    l1[2].val = -4;
    l1[3].val = -3;
    l1[4].val = 0;
    l1[5].val = 2;
    l1[6].val = 2;
    l1[7].val = 3;

    l2[0].val = 3;
    l2[1].val = 3;

    l3[0].val = -4;

    l4[0].val = -10;
    l4[1].val = -5;
    l4[2].val = -2;

    //[-10,-7,-4,-3,-1,0,1,2],
    //[-9,-9,-6,0,1,2,2]]
    l5[0].val = -10;
    l5[1].val = -7;
    l5[2].val = -4;
    l5[3].val = -3;
    l5[4].val = -1;
    l5[5].val = 0;
    l5[6].val = 1;
    l5[7].val = 2;

    l6[0].val = -9;
    l6[1].val = -9;
    l6[2].val = -6;
    l6[3].val = 0;
    l6[4].val = 1;
    l6[5].val = 2;
    l6[6].val = 2;

    for(i = 0; i < listsSize; i++) {
        int maxIndex = lenSize[i]-1;
        for(j = 0; j < maxIndex; j++) {
            list[i][j].next = &list[i][j+1];
        }
        if(maxIndex >= 0) {
            list[i][maxIndex].next = NULL;
        }


    }


    ret = mergeKLists(list, listsSize);


    while(ret != NULL) {
        printf("%d \n", ret->val);
        ret = ret->next;
    }
}