#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
      int val;
      struct ListNode *next;
} ;



struct ListNode * addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    int append = 0;
    int sum = 0;
    struct ListNode *node, *tmp;
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));

    head->next = NULL;
    node = head;

    while(l1 && l2) {
        sum = l1->val + l2->val + append;
        append = sum/10;
        if(append) {
            sum -= (append * 10);
        }
        tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
        tmp->val = sum;
        tmp->next = NULL;
        node->next = tmp;
        node = tmp;
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1) {
        tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
        sum = l1->val + append;
        append = sum/10;
        if(append) {
            sum -= (append * 10);
        }
        tmp->val = sum;
        tmp->next = NULL;
        node->next = tmp;
        node = tmp;
        l1 = l1->next;
    }

    while(l2) {
        tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
        sum = l2->val + append;
        append = sum/10;
        if(append) {
            sum -= (append * 10);
        }
        tmp->val = sum;
        tmp->next = NULL;
        node->next = tmp;
        node = tmp;
        l2 = l2->next;
    }
    if(append) {
        tmp = (struct ListNode *) malloc(sizeof(struct ListNode));
        tmp->val = append;
        tmp->next = NULL;
        node->next = tmp;
    }

    tmp = head;
    if(head->next == NULL) {
        head->val = 0;
    } else {
        head = head->next;
        free(tmp);
    }

    return head;

}


void printListNode(struct ListNode * l)
{
    while(l) {
        printf("%d ->", l->val);
        l = l->next;
    }

    printf("\n");
}

int main(int *argc, char *argv[])
{
    struct ListNode * l1, *l2, *node;

    l1 = node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = 3;
    node->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    node = node->next;
    node->val = 4;
    node->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    node = node->next;
    node->val = 2;
    node->next = NULL;



    l2 = node = (struct ListNode *) malloc(sizeof(struct ListNode));
    node->val = 4;
    node->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    node = node->next;
    node->val = 6;
    node->next = (struct ListNode *) malloc(sizeof(struct ListNode));
    node = node->next;
    node->val = 8;
    node->next = NULL;

    node = addTwoNumbers(l1,l2);

    printListNode(node);

}
