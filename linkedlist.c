#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//sll.c
struct node
{
    int data;
    struct node *next;
};

struct node *head;

void printll();

void ins_beg()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the new node: \n");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;

    printll();
}

void ins_aft()
{
    struct node *ptr, *preptr;
    int pos;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node after which the new node is to be inserted: \n");
    scanf("%d", &pos);
    printf("Enter the data of the new node");
    scanf("%d", &new_node->data);
    preptr = head;
    ptr = preptr->next;
    while (preptr->data != pos)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    new_node->next = ptr;
    preptr->next = new_node;

    printll();
}

void ins_bef()
{
    struct node *ptr, *preptr;
    int pos;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of the node before which the new node is to be inserted: \n");
    scanf("%d", &pos);
    printf("Enter the data of the newnode \n");
    scanf("%d", &new_node->data);
    preptr = head;
    ptr = preptr->next;
    while (ptr->data != pos)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    new_node->next = preptr->next;
    preptr->next = new_node;
    printll();
}

void ins_end()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr;
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

    printll(head);
}

void del_beg()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr;
    ptr = head;
    head = ptr->next;
    free(ptr);

    printll(head);
}

void del_mid()
{
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
    struct node *ptr, *preptr;
    int data;
    printf("Enter the data of the node to be deleted \n");
    scanf("%d", &data);
    preptr = head;
    ptr = preptr->next;
    while (preptr->next->data != data)
    {
        ptr = ptr->next;
        preptr = preptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);

    printll();
    }
}

void del_end()
{
    if(head==NULL){
        printf("The list is empty");
    }
    else{
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
}

void printll()
{
    struct node *ptr = head;
    if(head == NULL){
        printf("The list is empty");
    }

    else{
        printf("The list is:\n");
    while (ptr != NULL)
    {

        printf("%d\n ", ptr->data);
        ptr = ptr->next;
    } }
}

int sll()
{
    int opt;
    while (1)
    {
        printf("---------Operations on Linked list---------\n");
        printf("1. Insertion in the beginning\n");
        printf("2. Insertion at the end\n");
        printf("3. Insertion after the specified node\n");
        printf("4. Insertion before the specified node\n");
        printf("5. Deletion in the beginning\n");
        printf("6. Deletion of specific node\n");
        printf("7. Deletion at the End\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");

        printf("Select the operation to be performed\n");
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
            printll(head);
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Invalid option\n");
        }
    }
    return 0;
}
