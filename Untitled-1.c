#include <stdio.h>
#include <stdlib.h>

// Struct for a simple linked list node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    // Allocate and initialize a node
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;
    printf("Node data: %d\n", head->data);
    free(head);  // Manual deallocation
    return 0;
}