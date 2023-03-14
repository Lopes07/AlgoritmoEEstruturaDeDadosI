#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* newHead = (struct ListNode*) malloc (sizeof(struct ListNode));

    newHead->val = head->val;
    newHead->next = NULL;
    head =  head->next;

    while (head != NULL) {
        struct ListNode* temp = newHead;
        newHead = head;
        head = head->next;
        newHead->next = temp;
    }

    return newHead;
}