#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Though not strictly used in this merged version, kept for completeness if needed for future string operations

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Global head pointer for the linked list, initialized to NULL
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
void search_node(); // New feature declaration

// Insert at the beginning
void ins_beg() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) { // Always check if malloc was successful
        printf("Memory allocation failed! Unable to create new node.\n");
        return;
    }
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;
    printll();
}

// Insert at the end
void ins_end() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed! Unable to create new node.\n");
        return;
    }
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
    int pos_data; // Data of the node after which to insert
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed! Unable to create new node.\n");
        return;
    }

    printf("Enter the data of the node after which the new node is to be inserted: ");
    scanf("%d", &pos_data);
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);

    struct node *ptr = head;
    while (ptr != NULL && ptr->data != pos_data) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with data %d not found in the list. Insertion failed.\n", pos_data);
        free(new_node); // Free allocated memory if not inserted
        return;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
    printll();
}

// Insert before a specified node
void ins_bef() {
    int pos_data; // Data of the node before which to insert
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed! Unable to create new node.\n");
        return;
    }
    printf("Enter the data of the node before which the new node is to be inserted: ");
    scanf("%d", &pos_data);
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);

    if (head == NULL) {
        printf("List is empty. Cannot insert before a specific node.\n");
        free(new_node);
        return;
    }

    // Special case: inserting before the head node
    if (head->data == pos_data) {
        new_node->next = head;
        head = new_node;
        printll();
        return;
    }

    struct node *preptr = head;
    struct node *ptr = head->next;

    while (ptr != NULL && ptr->data != pos_data) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with data %d not found in the list. Insertion failed.\n", pos_data);
        free(new_node);
        return;
    }

    new_node->next = ptr; // This is the 'preptr->next' from original dev1 logic
    preptr->next = new_node;
    printll();
}

// Delete from beginning
void del_beg() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    printf("Node deleted from the beginning.\n");
    printll();
}

// Delete a specific node (by data value)
void del_mid() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    int data_to_delete;
    printf("Enter the data of the node to be deleted: ");
    scanf("%d", &data_to_delete);

    // Special case: deleting the head node
    if (head->data == data_to_delete) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printf("Node with data %d deleted.\n", data_to_delete);
        printll();
        return;
    }

    struct node *preptr = head;
    struct node *ptr = head->next;

    while (ptr != NULL && ptr->data != data_to_delete) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Node with data %d not found in the list. Deletion failed.\n", data_to_delete);
        return;
    }

    preptr->next = ptr->next;
    free(ptr);
    printf("Node with data %d deleted.\n", data_to_delete);
    printll();
}

// Delete from end
void del_end() {
    if (head == NULL) {
        printf("The list is empty. Cannot delete from an empty list.\n");
        return;
    }

    // If only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        printll();
        return;
    }

    struct node *ptr = head;
    struct node *preptr = NULL; // Keep track of the node before 'ptr'

    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;
    free(ptr);
    printf("Last node deleted.\n");
    printll();
}

// Print the linked list
void printll() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("The list is: ");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data); // Show linked list style
            ptr = ptr->next;
        }
        printf("NULL\n"); // Indicate end of list
    }
}

// New feature: Search for a node
void search_node() {
    struct node *ptr = head;
    int search_data;
    printf("Enter the data to search for: ");
    scanf("%d", &search_data);

    if (head == NULL) {
        printf("List is empty. Cannot search.\n");
        return;
    }

    int position = 1;
    while (ptr != NULL) {
        if (ptr->data == search_data) {
            printf("Node with data %d found at position %d.\n", search_data, position);
            return; // Found, so exit
        }
        ptr = ptr->next;
        position++;
    }
    printf("Node with data %d not found in the list.\n", search_data);
}

// Main menu function
int main() {
    int opt;
    while (1) {
        printf("\n--------- Operations on Linked List ---------\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a specified node\n");
        printf("4. Insert before a specified node\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete a specific node\n");
        printf("7. Delete from the end\n");
        printf("8. Print the linked list\n");
        printf("9. Search for a node\n"); // New option for searching
        printf("10. Exit\n");

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
            case 9: search_node(); break; // Call the new search function
            case 10: exit(0);
            default: printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}