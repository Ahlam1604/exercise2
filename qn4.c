#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

int isSorted(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1;
    }

    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data > current->next->data) {
            return 0;
        }
        current = current->next;
    }

    return 1;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&head, data);
    }

    printf("Linked List: ");
    printList(head);

    if (isSorted(head)) {
        printf("The linked list is sorted in ascending order.\n");
    } else {
        printf("The linked list is NOT sorted in ascending order.\n");
    }

    return 0;
}
