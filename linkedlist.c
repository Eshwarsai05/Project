#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function declarations
void printll();
void ins_beg();
void ins_end();
void ins_aft();
void ins_bef();
void del_beg();
void del_mid();
void del_end();

// Insert at the beginning
void ins_beg() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;
    printll();
}

// Insert at the end
void ins_end() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    printll();
}

// Insert after a specified node
void ins_aft() {
    struct node *ptr = head;
    int pos;
    printf("Enter the data of the node after which to insert: ");
    scanf("%d", &pos);

    while (ptr != NULL && ptr->data != pos) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with data %d not found.\n", pos);
        return;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);
    new_node->next = ptr->next;
    ptr->next = new_node;

    printll();
}

// Insert before a specified node
void ins_bef() {
    int pos;
    printf("Enter the data of the node before which to insert: ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);

    if (head->data == pos) {
        new_node->next = head;
        head = new_node;
        printll();
        return;
    }

    struct node *preptr = head;
    struct node *ptr = head->next;

    while (ptr != NULL && ptr->data != pos) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with data %d not found.\n", pos);
        free(new_node);
        return;
    }

    new_node->next = ptr;
    preptr->next = new_node;

    printll();
}

// Delete from beginning
void del_beg() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *ptr = head;
    head = head->next;
    free(ptr);

    printll();
}

// Delete a specific node
void del_mid() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int data;
    printf("Enter the data of the node to delete: ");
    scanf("%d", &data);

    if (head->data == data) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printll();
        return;
    }

    struct node *preptr = head;
    struct node *ptr = head->next;

    while (ptr != NULL && ptr->data != data) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    preptr->next = ptr->next;
    free(ptr);

    printll();
}

// Delete from end
void del_end() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printll();
        return;
    }

    struct node *ptr = head;
    struct node *preptr = NULL;

    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);

    printll();
}

// Print the linked list
void printll() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("The list is:\n");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Main menu function
int main() {
    int opt;
    while (1) {
        printf("\n---------Operations on Linked List---------\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a specified node\n");
        printf("4. Insert before a specified node\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete a specific node\n");
        printf("7. Delete from the end\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");

        printf("Select an option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1: ins_beg(); break;
            case 2: ins_end(); break;
            case 3: ins_aft(); break;
            case 4: ins_bef(); break;
            case 5: del_beg(); break;
            case 6: del_mid(); break;
            case 7: del_end(); break;
            case 8: printll(); break;
            case 9: exit(0);
            default: printf("Invalid option.\n");
        }
    }

    return 0;
}
