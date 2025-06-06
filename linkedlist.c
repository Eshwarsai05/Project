#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//sll.c
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL; // Initialize head to NULL for an empty list initially

void printll();

void ins_beg()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) { // Always check if malloc was successful
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the data of the new node: \n");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;

    printll();
}

void ins_aft()
{
    struct node *ptr, *preptr;
    int pos_data; // Changed 'pos' to 'pos_data' for clarity (it's the data, not position)
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the data of the node after which the new node is to be inserted: \n");
    scanf("%d", &pos_data);
    printf("Enter the data of the new node: "); // Added newline for better formatting
    scanf("%d", &new_node->data);

    preptr = head;
    // Handle case where list is empty or target node is not found
    if (preptr == NULL) {
        printf("List is empty. Cannot insert after a node.\n");
        free(new_node); // Free allocated memory if not inserted
        return;
    }

    while (preptr != NULL && preptr->data != pos_data) // Iterate until target data is found or end of list
    {
        preptr = preptr->next;
    }

    if (preptr == NULL) { // Target node not found
        printf("Node with data %d not found in the list. Insertion failed.\n", pos_data);
        free(new_node);
        return;
    }

    new_node->next = preptr->next;
    preptr->next = new_node;

    printll();
}

void ins_bef()
{
    struct node *ptr, *preptr;
    int pos_data; // Changed 'pos' to 'pos_data'
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the data of the node before which the new node is to be inserted: \n");
    scanf("%d", &pos_data);
    printf("Enter the data of the newnode \n");
    scanf("%d", &new_node->data);

    // Handle insertion before the head node
    if (head == NULL) {
        printf("List is empty. Cannot insert before a specific node.\n");
        free(new_node);
        return;
    }
    if (head->data == pos_data) {
        new_node->next = head;
        head = new_node;
        printll();
        return;
    }

    preptr = head;
    ptr = head->next; // Start ptr from the second node

    while (ptr != NULL && ptr->data != pos_data)
    {
        preptr = preptr->next;
        ptr = ptr->next;
    }

    if (ptr == NULL) { // Target node not found
        printf("Node with data %d not found in the list. Insertion failed.\n", pos_data);
        free(new_node);
        return;
    }

    new_node->next = preptr->next;
    preptr->next = new_node;
    printll();
}

void ins_end()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the data of the new node: \n");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    printll(); // Removed 'head' as an argument for printll
}

void del_beg()
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }
    struct node *ptr;
    ptr = head;
    head = ptr->next;
    free(ptr);

    printll(); // Removed 'head' as an argument for printll
}

void del_mid()
{
    if(head == NULL){
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }
    struct node *ptr, *preptr;
    int data_to_delete;
    printf("Enter the data of the node to be deleted \n");
    scanf("%d", &data_to_delete);

    // Handle deletion of the head node
    if (head->data == data_to_delete) {
        ptr = head;
        head = head->next;
        free(ptr);
        printll();
        return;
    }

    preptr = head;
    ptr = head->next; // Start ptr from the second node

    while (ptr != NULL && ptr->data != data_to_delete)
    {
        preptr = preptr->next;
        ptr = ptr->next;
    }

    if (ptr == NULL) { // Node not found
        printf("Node with data %d not found in the list. Deletion failed.\n", data_to_delete);
        return;
    }

    preptr->next = ptr->next;
    free(ptr);

    printll();
}

void del_end()
{
    if(head==NULL){
        printf("The list is empty. Cannot delete from an empty list.\n");
        return;
    }
    // If only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printll();
        return;
    }

    struct node *ptr, *preptr;
    preptr = head;
    ptr = preptr->next;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = NULL;
    free(ptr);

    printll();
}

void printll()
{
    struct node *ptr = head;
    if(head == NULL){
        printf("The list is empty.\n"); // Added newline for consistent formatting
    }
    else{
        printf("The list is:\n");
        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data); // Changed format to show linked list style
            ptr = ptr->next;
        }
        printf("NULL\n"); // Indicate end of list
    }
}

// New feature: Search for a node
void search_node() {
    struct node *ptr = head;
    int search_data;
    printf("Enter the data to search for: \n");
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

int sll()
{
    int opt;
    while (1)
    {
        printf("\n---------Operations on Linked list---------\n"); // Added newline for better spacing
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Search for a node\n"); // Added new option
        printf("10. Exit\n"); // Changed exit option

        printf("Select the operation to be performed: \n");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                ins_beg();
                break;
            case 2:
                ins_end();
                break;
            case 3:
                ins_aft();
                break;
            case 4:
                ins_bef();
                break;
            case 5:
                del_beg();
                break;
            case 6:
                del_mid();
                break;
            case 7:
                del_end();
                break;
            case 8:
                printll(); // Removed 'head' as an argument
                break;
            case 9: // New case for search
                search_node();
                break;
            case 10: // Updated exit case
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n"); // More user-friendly message
        }
    }
    return 0;
}

int main() {
    sll();
    return 0;
}
