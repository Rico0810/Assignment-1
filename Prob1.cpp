#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int L1;
    Node *next;
} *head, *tail, *head2, *tail2;

Node *createNode(int L1){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->L1 = L1;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int L1){
    Node *temp = createNode(L1);

    if(!head) {
        head = tail = temp;
    } else{
        temp->next = head;
        head = temp;
    }
}

void pushTail(int L1){
    Node *temp = createNode(L1);

    if(!tail) {
        head = tail = temp;
    } else{
        tail->next = temp;
        tail = temp;
    }
}

void pushHead2(int L1) {
    Node *temp2 = createNode(L1);

    if(!head2){
        head2 = tail2= temp2;
    } else{
        temp2->next = head2;
        head2 = temp2;
    }
}

void pushTail2(int L1) {
    Node *temp2 = createNode(L1);

    if(!tail2){
        head2 = tail2= temp2;
    } else{
        tail2->next = temp2;
        tail2 = temp2;
    }
}

Node *merge (Node *h1, Node *h2) {
    if(!h1){
        return h2;
    }
    if(!h2){
        return h1;
    }

    if(h1->L1 < h2->L1){
        h1->next = merge(h1->next, h2);
        return h1;
    } else{
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

void printList(Node *node){
    while(node) {
        printf("%d ",node->L1);
        node = node->next;
    }
}

int main(){
    pushHead(20);
    pushHead(19);
    pushTail(105);
    pushTail(118);
    printf("This is the first Linked List:\n");
    printList(head);
    printf("\n");

    pushHead2(10);
    pushTail2(100);
    pushTail2(290);
    printf("This is the second Linked List: \n");
    printList(head2);
    printf("\n\n\n");

    Node *mergehead = merge(head, head2);

    printf("Sorting Result: \n");
    printList(mergehead);
    printf("\n\n");

    int small;
    small = 
    printf("Result : %d\n\n",small);

    int mid;
    mid = sizeof(mergehead) / sizeof(int) - 1;
    printf("Middle: %d",mid);

    return 0;
}


