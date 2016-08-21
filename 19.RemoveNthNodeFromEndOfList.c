#include <stdio.h>
#include <stdlib.h>



struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *node, *end;
    int i = 0;
    end = head;
    if(n < 1) {
        return head;
    }
    while(i < n ) {
        if(end->next == NULL ) {
            if((n - i) == 1) {
                return head->next;
            } else {
                return head;
            }
        } 
        i++;
        end = end->next;
    }

    node = head;
    while( end->next != NULL) {
        end = end->next;
        node = node->next;
    }

    node->next = node->next->next;
    

    return head;
   
}


int main(int argc, char *argv[]) {
    struct ListNode head[10];
    int i;
    struct ListNode *ret;

    for(i=0; i< 10; i++) {
        head[i].val = i+1;
        head[i].next = &head[i+1];
    }
    head[4].next = NULL;

    head[9].next = NULL;

    ret = removeNthFromEnd(head, 0);

    while(ret != NULL) {
        printf("%d\t", ret->val);
        ret = ret->next;
    }
    printf("\n");
    



}


