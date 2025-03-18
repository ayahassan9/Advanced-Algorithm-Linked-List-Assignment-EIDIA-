#include <stdio.h>
#include <stdlib.h>
struct CircularNode {
    int data;
    struct CircularNode* next;
};

// insert a new node at the beginning of the list
void insertAtBeginning(struct CircularNode** head, int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct CircularNode* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

//insert a new node at the end of the list
void insertAtEnd(struct CircularNode** head, int data) {
    struct CircularNode* newNode = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct CircularNode* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// delete the first node in the list
void deleteFirst(struct CircularNode** head) {
    if (*head == NULL) return; 
    struct CircularNode* temp = *head;
    struct CircularNode* last = *head;
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }
    while (last->next != *head) {
        last = last->next;
    }

    *head = temp->next; 
    last->next = *head; 
    free(temp);
}

// delete the last node in the list
void deleteLast(struct CircularNode** head) {
    if (*head == NULL) return; 
    struct CircularNode* temp = *head;
    struct CircularNode* prev = NULL;
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head; 
    free(temp);
}

// traverse and display the list elements
void traverseList(struct CircularNode* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct CircularNode* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function t
int main() {
    struct CircularNode* circularList = NULL;

    insertAtBeginning(&circularList, 10);
    insertAtBeginning(&circularList, 20);

    insertAtEnd(&circularList, 30);
    insertAtEnd(&circularList, 40);

    printf("Circular Linked List after insertions: ");
    traverseList(circularList);

    deleteFirst(&circularList);
    printf("After deleting first element: ");
    traverseList(circularList);

    deleteLast(&circularList);
    printf("After deleting last element: ");
    traverseList(circularList);

    return 0;
}
