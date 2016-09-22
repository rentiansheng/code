#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
};



struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    struct ListNode *ret, *node, *pre, *offsetNode, **part;

    int offset = 0;
    int i = 0;

    if(k <= 1) {
        return head;
    }

    part = (struct ListNode **)malloc(sizeof(struct ListNode*)*k);
    offsetNode = head;
    ret = NULL;

    while(offsetNode != NULL) {
        offset  = 0;
        while(offset < k && offsetNode != NULL) {
            part[offset++] = offsetNode;
            offsetNode = offsetNode->next;
        }
        if(offset < k) {
            if(ret == NULL) {
                ret = head;
            } else {
                node->next = part[0];
            }
        } else {

            for(i = k - 1; i >= 0; i--) {
                if(ret == NULL) {
                    ret = part[i];
                    node = ret;
                }else {
                    node->next = part[i];
                    node = node->next;
                    node->next = NULL;
                }
            }

        }


    }

    free(part);
    return ret;
 }

 int main(int argc, char *argv[]) {

     struct ListNode l[100], *ret;
     int no[] = {1,2,3,4,5};
     int len = sizeof(no)/sizeof(int) ;
     int i = 0;

     for(i = 0; i < len; i++) {
        l[i].val = no[i];
        l[i].next = &l[i+1];
     }
     if(len>0) {
        l[len-1].next = NULL;
     }



     ret = reverseKGroup(l,5);
     while(ret != NULL) {
         printf("%d,", ret->val);
         ret = ret->next;
     }
     printf("\n");

 }