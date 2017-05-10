#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
 };

 struct ListNode* swapPairs(struct ListNode* head) {

    struct ListNode *pre, *node;
    int tmp = 0;
    if(head == 0) {
        return head;
    }
    pre = head;

    while(pre != NULL && (node = pre->next) != NULL) {
       tmp = pre->val;
       pre->val = node->val;
       node->val = tmp;
       pre = node->next;
    }

    return head;
 }

 int main(int argc, char *argv[]) {

     struct ListNode l[100], *ret;
     int no[] = {1,2,3,4};
     int len = sizeof(no)/sizeof(int) ;
     int i = 0;

     for(i = 0; i < len; i++) {
        l[i].val = no[i];
        l[i].next = &l[i+1];
     }
     if(len>0) {
        l[len-1].next = NULL;
     }



     ret = swapPairs(l);
     while(ret != NULL) {
         printf("%d \n", ret->val);
         ret = ret->next;
     }
 }