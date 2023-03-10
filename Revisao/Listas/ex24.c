#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data);
void printList(struct Node* head);
int areListsEqual(struct Node* head1, struct Node* head2);

int main(){
    struct Node* head1 = newNode(5);
    head1->next = newNode(2);
    head1->next->next = newNode(8);

    struct Node* head2 = newNode(5);
    head2->next = newNode(2);
    head2->next->next = newNode(8);

    printf("Lista 1: ");
    printList(head1);

    printf("Lista 2: ");
    printList(head2);

    if (areListsEqual(head1, head2)) {
        printf("As listas sao iguais.\n");
    } else {
        printf("As listas sao diferentes.\n");
    }

    struct Node* head3 = newNode(5);
    head1->next = newNode(2);
    head1->next->next = newNode(8);

    struct Node* head4 = newNode(5);
    head2->next = newNode(3);
    head2->next->next = newNode(8);

    printf("Lista 3: ");
    printList(head1);

    printf("Lista 4: ");
    printList(head2);

    if (areListsEqual(head3, head4)) {
        printf("As listas sao iguais.\n");
    } else {
        printf("As listas sao diferentes.\n");
    }
    free(head1);
    free(head2);
    free(head3);
    free(head4);

    return 0;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));

    node->data = data;
    node->next = NULL;

    return node;
}

void printList(struct Node*  head){
    struct Node* node = head;

    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int areListsEqual(struct Node* head1, struct Node* head2){
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data) {
            return 0; //as listas sao diferentes
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return(head1 == NULL && head2 == NULL);
}