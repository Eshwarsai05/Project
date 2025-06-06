#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Global head pointer
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
void search_node();

// Insert at the beginning
void ins_beg() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
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
    printf("Enter the data of the new node: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    printll();
}

// Insert after a specified node
void ins_aft() {
    int pos_data;
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
        free(new_node);
        return;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
    printll();
}

// Insert before a specified node
void ins_bef() {
    int pos_data;
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

    new_node->next = ptr;
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

// Delete a specific node
void del_mid() {
    if (head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    int data_to_delete;
    printf("Enter the data of the node to be deleted: ");
    scanf("%d", &data_to_delete);

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

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
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
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

// Search for a node
void search_node() {
    int search_data, position = 1;
    printf("Enter the data to search for: ");
    scanf("%d", &search_data);

    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->data == search_data) {
            printf("Node with data %d found at position %d.\n", search_data, position);
            return;
        }
        ptr = ptr->next;
        position++;
    }
    printf("Node with data %d not found in the list.\n", search_data);
}

// Main menu
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
        printf("9. Search for a node\n");
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
            case 9: search_node(); break;
            case 10: exit(0);
            default: printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

struct node2
{
    int data;
    struct node2 *next;
};

struct node2 *start2 = NULL;
void printll2();

void ins_beg2()
{
    struct node2 *new_node = malloc(sizeof(struct node2));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter the data of newnode\n");
    scanf("%d", &new_node->data);
    if (start2 == NULL)
    {
        start2 = new_node;
        new_node->next = start2;
    }
    else
    {
        struct node2 *temp = start2;
        while (temp->next != start2)
        {
            temp = temp->next;
        }
        new_node->next = start2;
        start2 = new_node;
        temp->next = start2;
    }
    printll2();
}

void ins_bef2()
{
    struct node2 *new_node = malloc(sizeof(struct node2));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    struct node2 *ptr, *preptr;
    int pos;
    printf("Enter the data of node2 after which you need to insert the new node2;\n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode\n");
    scanf("%d", &new_node->data);
    ptr = start2;
    if (start2->data == pos)
    {
        ins_beg2();
        return;
    }
    while (ptr->next != start2 && ptr->data != pos)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr->data == pos)
    {
        new_node->next = ptr;
        preptr->next = new_node;
    }
    printll2();
}

void ins_aft2()
{
    struct node2 *new_node = malloc(sizeof(struct node2));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    struct node2 *ptr;
    int pos;
    printf("Enter the data of the node2 after which you need to insert the new node2\n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode\n");
    scanf("%d", &new_node->data);
    ptr = start2;
    if(start2 == NULL){
        printf("List is empty, cannot insert after a node.\n");
        free(new_node);
        return;
    }
    do {
        if(ptr->data == pos){
            new_node->next = ptr->next;
            ptr->next = new_node;
            printll2();
            return;
        }
        ptr = ptr->next;
    } while (ptr != start2);

    printf("Node not found\n");
    free(new_node);
}

void ins_end2()
{
    struct node2 *new_node = malloc(sizeof(struct node2));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    struct node2 *ptr;
    printf("Enter the data of newnode\n");
    scanf("%d", &new_node->data);
    ptr = start2;
    if (start2 != NULL) {
        while (ptr->next != start2)
        {
            ptr = ptr->next;
        }
        new_node->next = start2;
        ptr->next = new_node;
    } else {
        start2 = new_node;
        new_node->next = start2;
    }
    printll2();
}

void del_beg2()
{
    struct node2 *ptr;
    if (start2 == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start2;
    while (ptr->next != start2)
    {
        ptr = ptr->next;
    }
    struct node2 *temp = start2;
    start2 = start2->next;
    ptr->next = start2;
    free(temp);
    printll2();
}

void del_mid2()
{
    struct node2 *ptr, *preptr;
    int data;
    printf("Enter the data of the node2 to be deleted\n");
    scanf("%d", &data);
    ptr = start2;
    if (ptr->data == data)
    {
        del_beg2();
        return;
    }
    while (ptr->next != start2 && ptr->next->data != data)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr->next->data == data)
    {
        struct node2 *temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    printll2();
}

void del_end2()
{
    struct node2 *ptr, *preptr;
    if (start2 == NULL)
    {
        printf("List is empty\n");
        return;
    }
    ptr = start2;
    while (ptr->next != start2)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = start2;
    free(ptr);
    printll2();
}

void printll2()
{
    if (start2 == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct node2 *ptr = start2;
    printf("The list is \n");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start2);
    printf("\n");
}

int scll()
{
    int opt;
    while (opt != 9)
    {
        printf("---------Operations on Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node2\n");
        printf("4. Insertion before the specified node2\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node2\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");

        printf("Select the operation to be performed\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            ins_beg2();
            break;
        case 2:
            ins_end2();
            break;
        case 3:
            ins_aft2();
            break;
        case 4:
            ins_bef2();
            break;
        case 5:
            del_beg2();
            break;
        case 6:
            del_mid2();
            break;
        case 7:
            del_end2();
            break;
        case 8:
            printll2();
            break;
        case 9:
            return 0;
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}
