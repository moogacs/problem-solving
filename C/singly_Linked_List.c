/*
In computer science, a linked list is a linear collection of data elements, whose order is not given by their physical placement in memory.
Instead, each element points to the next.
It is a data structure consisting of a collection of nodes which together represent a sequence.
In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence.
This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration.
More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.
A drawback of linked lists is that access time is linear (and difficult to pipeline).
Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists. 
*/

#include<stdio.h>
#include<stdlib.h>

//Defining a node with two fields -> 1. data and 2. a node pointer next
//A node pointer[root] is declared which always points to the first n
struct node
{
    int data;
    struct node *next;
}*root;

void appendNode(); //This Function adds a new node at the end of the list.
void traverseNode(); //This Function traverses the node to print its stored values.
void beginNode(); //This Function adds a new node at the begining of the list.
void insertNthNode(); //This Function adds a new node at any nth position of the list.

// Menu Driven Code to access different Singly Linked List operations
void main()
{
    int ch = 0;
    while(ch != 5)
    {
        printf("\n");
        printf("Select Operation:\n");
        printf("1.Append Node\n2.Traverse Node\n3.Add Node at the beginning\n4.Add Node at nth pos\n5.Quit:");
        scanf("%d", &ch);
        
        switch (ch)
        {
        case 1:
            appendNode();
            break;

        case 2:
            traverseNode();
            break;

        case 3:
            beginNode();
            break;

        case 4:
            insertNthNode();
            break;

        default:
            printf("Invalid choice %d\n", ch); break;
        }

    }
}

void beginNode()
{
    int val;
    struct node *current;

    printf("Enter Value at beginning:");
    scanf("%d", &val);

    current = (struct node*)malloc(sizeof(struct node));

    current->data = val;

    if(root == NULL)
    {
        current->next = NULL;
        root = current;
    }
    else
    {
        current->next = root;
        root = current;
    }
    
}

void appendNode()
{
    int val; 
    
    struct node *current, *tmp;
    
    printf("Enter the value to append:");
    scanf("%d", &val);

    current = (struct node*)malloc(sizeof(struct node));
    tmp = root;


    current->data = val;
    current->next = NULL;

    if(root == NULL)
        root = current;
    else
    {
        while(tmp->next!=NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = current;

    }
    
}

void traverseNode()
{
    struct node* tmp;

    printf("\n");

    for(tmp = root; tmp != NULL; tmp = tmp->next)
        printf("%d ", tmp->data);

    printf("\n");
}

void insertNthNode()
{
    int n, val;
    struct node *tmp, *current;

    tmp = root;
    printf("Enter nth pos and value [space seperated]:");
    scanf("%d %d", &n, &val);

    current = (struct node*)malloc(sizeof(struct node));

    current->data = val;

    for(int i = 1; i<n-1; i++)
        tmp = tmp->next;

    current->next = tmp->next;
    tmp->next = current;
    
}
