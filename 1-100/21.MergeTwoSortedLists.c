#include <stdio.h>
#include <stdlib.h>



struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *head, *node;

    if( l1 == NULL && l2 == NULL )  {
        return NULL;
    }

    if( l1 == NULL ) {
        return l2;
    }
    if( l2 == NULL ) {
        return  l1;
    }

    if( l1->val > l2->val ) {
        head = l2;
        l2 = l2->next;
    } else {
        head = l1;
        l1 = l1->next;
    }

    node = head;
    while( l1 != NULL && l2 != NULL ) {
         if(l1->val > l2->val) {
             node->next = l2;
             l2 = l2->next;
             
         }else {
             node->next = l1;
             l1 = l1->next;
         }

         node = node->next;
         node->next = NULL;
    }
    
    while(l1 != NULL) {
        node->next = l1;
        l1 = l1->next;
        node = node->next;
        node->next = NULL;
    }
    while(l2 != NULL) {
        node->next = l2;
        l2 = l2->next;
        node = node->next;
        node->next = NULL;
    }

    return head;
    
}

int main(int argc, char *argv[]) {

    struct ListNode l1[3], l2[5], *ret;
    int i ;
    
     l1[0].val = 3;
     l1[0].next = &l1[1];
     l1[1].val = 7;
     l1[1].next = &l1[2];
     l1[2].val = 18;
     l1[2].next = NULL;

     l2[0].val = 4;
     l2[0].next = &l2[1];
     l2[1].val = 5;
     l2[1].next = &l2[2];
     l2[2].val = 8;
     l2[2].next = &l2[3];
     l2[3].val = 9;
     l2[3].next = &l2[4];
     l2[4].val = 10;
     l2[4].next = NULL;

     
    ret = mergeTwoLists(NULL, NULL);
    while(ret != NULL) {
        printf("%d \n", ret->val);
        ret = ret->next;
    }
}