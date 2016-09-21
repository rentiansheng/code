#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
 };



struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    int i;
    int heapCount = listsSize - 1;
    int left, right ;
    if(listsSize == 0 ){
        return NULL;
    }

    if(listsSize == 1) {
        return lists[0];
    }

    int heapCount = listsSize -1;
    int listNode * tmpNode = NULL;
    struct listNode * heap = (struct listNode *)malloc(sizeof(struct listNode ));

    for(i=0; i < listsSize; i++) {
        heap[i] = lists[i];
    }


    for(i= heapCount/2-1; i >= 0; i--) {
        left = 2*i +1;
        if(left > heapCount) {continue;}
        if(heap[i]->val > heap[left]->val) {
            tmpNode = heap[i];
            heap[i] = heap[left];
            heap[left] = tmpNode;
        }
        right = left+1;
        if(rigth > heapCount) {continue;}
        if(heap[i]->val > heap[right->.val) {
            tmpNode = heap[i];
            heap[i] = heap[right];
            heap[right] = tmpNode;
        }
    }


    struct listNode * heap = heap[0];
    struct listNode *node = head;

    while(heapCount > 0 ) {
        if(heap[0]->next == NULL ) {
            heap[0] = heap[heapCount];
            heapCount--;
        }
        heap[0] = heap[0]->next;
        i = 0;
        while(i < heapCount) {
            left = 2*i+1;
            if(left > heapCount) {break;}
            if(heap[i]->val > heap[left]->val) {
                tmpNode = heap[i];
                heap[i] = heap[left];
                heap[left] = tmpNode
            }
            right = right+1;
            if(right > heapCount) {break;}
            if(heap[i]->val > heap[right]->val) {
                tmpNode = heap[i];
                heap[i] = heap[right];
                heap[right] = tmpNode
            }
        }

        node->next = heap[0];
        node = heap[0];
    }
    while(heap[0] != NULL){
        node->next = heap[0];
        node = heap[0];
        heap[0] = heap[0]->next;
    }


    return head;

}


int main(int argc, char *argv[]) {

}