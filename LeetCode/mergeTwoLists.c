#include <stdlib.h>
#include <stdio.h>

struct ListNode {
   int val;
   struct ListNode *next;
 };
 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode* t1 = NULL;
    struct ListNode* t2 = NULL;
    struct ListNode* result = NULL;

    if ( list1 == NULL ){
        return list2;
    }

    if ( list2 == NULL ) {
        return list1;
    }

    if ( list1->val < list2 ->val ){
        result = t1 = list1;
        t2 = list2;
    } else {
        result = t1 = list2;
        t2 = list1;
    }

    while ( t1 != NULL ){
        if(( t1 != NULL && t2 != NULL && t1->val <= t2->val && t1->next != NULL && t1 ->next->val >= t2-> val)) {
            struct ListNode*  newNode = (struct ListNode *) malloc (sizeof (struct ListNode));
            newNode->val = t2->val;
            newNode->next = t1->next;
            t1->next = newNode;
            t1 = t1->next;
            t2 = t2->next;
        } else if ( t1->next == NULL){
            t1->next = t2;
            break;
        } else {
            t1 = t1->next;
        }
        
    }

    return result;
}