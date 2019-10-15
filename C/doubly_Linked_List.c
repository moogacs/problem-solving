/*
Almost same as Singly linked List except its node has three fields which contain reference to previous node, reference to next node and stores data.
*/
#include<stdio.h>
#include<stdlib.h>

// Two nodes are declared 1. head , which points to the first node 2. tail, which points to the last node.
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head, *tail;

typedef struct node node;

void appendNode();
void traverseNode();
void beginNode();
void nthNode();
void delNthNode();

void main()
{
    int ch = 0;
    while(ch != 6)
    {
        printf("\n");
        printf("Select Operation:\n");
        printf("1.Append Node\n2.Traverse Node\n3.Add Node at the beginning\n4.Add Node at nth pos\n5.Delete at nth pos\n6.Quit:");
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
            nthNode();
            break;
        
        case 5:
            delNthNode();
            break;

        case 6:
            printf("Exiting....\n");
            break;
        default:
            printf("Invalid choice %d\n", ch); break;
        }

    }
}

void appendNode()
{
    node *tmp; int val;

    tmp = (node*)malloc(sizeof(node)); 

    printf("Enter the value:");
    scanf("%d", &val);

    tmp->data = val;
    tmp->prev = tmp->next = NULL;

    if(head == NULL && tail == NULL)
        head = tail = tmp;
    else
    {
        tail->next = tmp;
        tmp->prev = tail;
        tail = tail->next;
    }
}

void traverseNode()
{
    node *tmp;

    printf("\n");

    for(tmp = head; tmp!=NULL; tmp=tmp->next)
        printf("%d ", tmp->data);

    printf("\n");
}

void beginNode()
{
    node *tmp; int val;

    tmp = (node*)malloc(sizeof(node));

    printf("Enter the Value:");
    scanf("%d", &val);

    tmp->next = tmp->prev = NULL;
    tmp->data = val;

    if(head == NULL && tail == NULL)
        head = tail = tmp;
    else
    {
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }

}

void nthNode()
{
    node *tmp, *pNode; int val, pos;

    printf("Enter nth pos and value [space seperated]:");
    scanf("%d %d", &pos, &val);

    pNode = head;

    tmp = (node*)malloc(sizeof(node));

    tmp->next = tmp->prev = NULL;
    tmp->data = val;

    for(int i = 1; i<pos-1; i++)
        pNode = pNode->next;

    tmp->next = pNode->next;
    tmp->prev = pNode;
    pNode->next->prev = tmp;
    pNode->next = tmp;

}

void delNthNode()
{
    node *tmp; int pos;

    printf("Enter the position to delete:");
    scanf("%d", &pos);

    tmp = head;

    for(int i = 1; i<pos; i++)
        tmp = tmp->next;

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    
    free(tmp);
    
}