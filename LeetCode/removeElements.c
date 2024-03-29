#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){

    if ( head == NULL ){
        return NULL;
    }

    if ( head->val == val ){
        return removeElements(head->next, val);
    } else {
        head->next = removeElements(head->next, val);
    }

    return head;
}