#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};
 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL){
        return NULL;
    }

    int sizeA = 0, sizeB = 0, diff;

    struct ListNode *currA = headA;
    struct ListNode *currB = headB;

    while(currA) {
        sizeA++;
        currA = currA->next;
    }

    while(currB) {
        sizeB++;
        currB = currB->next;
    }    

    currA = headA;
    currB = headB;
    
    diff = sizeA - sizeB;

    if (sizeA < sizeB) {
        for (int i = diff; i < 0; i++) {
            currB = currB->next;
        } 
    } else {
        for (int i = diff; i > 0; i--) {
            currA = currA->next;
        }
    }

    while (currA) {
        if (currA == currB) {
            return currA;
        }
        currA = currA->next;
        currB = currB->next; 
    }

    return NULL;
}