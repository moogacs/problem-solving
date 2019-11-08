#include<stdio.h>
#include<stdlib.h>
struct node{
        int item;
        struct node *link;
}*header=NULL,*pre,*now,*ptr,*pre1;
int i;
void push(int x)            //Insert at front
{
        now=(struct node*)malloc(sizeof(struct node));
        now->item=x;
        now->link=header;
        header=now;
}
void pop()                  //Delete from front
{
        if(header==NULL)
                printf("Underflow\n");
        else
        {
                ptr=header;
                header=header->link;
                free(ptr);
        }
}
void insert(int x)          // Insert at rear
{
        now=(struct node*)malloc(sizeof(struct node));
        now->item=x;
        now->link=NULL;
        if(header==NULL)
                header=now;
        else
        {
                ptr=header;
                while(ptr->link!=NULL)
                        ptr=ptr->link;
                ptr->link=now;
        }
}
void delete_r()             //Delete from rear
{
        if(header==NULL)
                printf("Underflow\n");
        else
        {
                ptr=header;
                while(ptr->link!=NULL)
                {
                        pre=ptr;
                        ptr=ptr->link;
                }
                pre->link=NULL;
                free(ptr);
        }
}
void insert_p(int x,int p)          //Insert at a particular position
{
		if(header==NULL&&p==1)
		{
			now=(struct node *)malloc(sizeof(struct node));
			now->item=x;
			now->link=NULL;
			header=now;
		}
		else
		{		
                	i=1;
                	ptr=header;
                	while(ptr!=NULL)
                	{
                        	if(p==i)
                                	break;
                        	pre=ptr;
                       		ptr=ptr->link;
                        	i++;            
                	}
                	if(p>i)
                        	printf("Out of Bounds\n");
		         	else if(p==1)
			        {
				            now=(struct node *)malloc(sizeof(struct node));
				            now->item=x;
				            now->link=header;
				            header=now;
			        }
                	else
                	{
                        	now=(struct node *)malloc(sizeof(struct node));
                        	now->item=x;
                        	now->link=ptr;
                        	pre->link=now;
                	}
		}
}
void delete_p(int p)            //Delete from a particular position
{
        if(header==NULL)
                printf("Underflow\n");
        else
        {
                i=1;
                ptr=header;
                while(ptr->link!=NULL)
                {
                        if(p==i)
                                break;
                        pre=ptr;
                        ptr=ptr->link;
                        i++;            
                }
                        if(p>i)
                                printf("Out of Bounds\n");
                        else if(p==1)
                        {
                                header=ptr->link;
                                free(ptr);
                        }
                        else if(p==i)
                        {
                                pre->link=ptr->link;
                                free(ptr);
                        }
        }
}
void insert_b(int x,int bef)        // Insert before a specified node
{
        if(header==NULL)
                printf("Underflow\n");
        else
        {
                ptr=header;
                while(ptr!=NULL&&ptr->item!=bef)
                {
                        pre=ptr;
                        ptr=ptr->link;
                }
                if(ptr==header&&ptr->item==bef)
                {
                        now=(struct node*)malloc(sizeof(struct node));
                        now->item=x;
                        now->link=header;
                        header=now;
                }
                else if(ptr->item==bef)
                {
                        now=(struct node*)malloc(sizeof(struct node));
                        now->item=x;
                        pre->link=now;
                        now->link=ptr;
                }
                else
                        printf("Element Not Found");
        }
}
void delete_b(int bef)          // Delete before a specified node
{
        if(header==NULL)
                printf("Underflow\n");
        else
        {
                pre1=header;
                pre=pre1->link;
                if(pre->item==bef)
                {
                        header=pre;
                        free(pre1);
                }
                else
                {
                        pre=pre1=ptr=header;
                        while(ptr!=NULL&&ptr->item!=bef)
                        {       
                                pre=pre1;
                                pre1=pre->link;
                                ptr=pre->link;
                        }
                        if(header->item==bef)
                                printf("No node before first node ");
                        else if(ptr->item==bef)
                        {
                                pre->link=ptr;
                                free(pre1);
                        }
		}
	}
}
void disp()         //Display the elements in the linked list
{
        if(header==NULL)
                printf("Underflow\n");
        else
        {
                ptr=header;
                while(ptr!=NULL)
                {
                        printf("%d ",ptr->item);
                        ptr=ptr->link;
                }
                printf("\n");
        }
}
void main()
{
        int ch,x,p;
        while(1)
        {
                printf("MENU\n1.INSERT AT HEAD\n2.INSERT AT TAIL\n3.INSERT AT POSITION\n4.INSERT BEFORE DATA\n5.DELETE FROM HEAD\n6.DELETE FROM TAIL\n7.DELETE FROM POSITION\n8.DELETE BEFORE DATA\n9.DISPLAY\n10.EXIT\nCHOICE : ");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1: printf("INPUT : ");
                                scanf("%d",&x);
                                push(x);
                                break;
                        case 2: printf("INPUT : ");
                                scanf("%d",&x);
                                insert(x);
                                break;
                        case 3: printf("INPUT : ");
                                scanf("%d",&x);
                                printf("POSITION : ");
                                scanf("%d",&p);
                                insert_p(x,p);
                                break;
                        case 4: printf("INPUT : ");
                                scanf("%d",&x);
                                printf("BEFORE : ");
                                scanf("%d",&p);
                                insert_b(x,p);
                                break;
                        case 5: pop();
                                break;
                        case 6: delete_r();
                                break;
                        case 7: printf("POSITION : ");
                                scanf("%d",&p);
                                delete_p(p);
                                break;
                        case 8: printf("BEFORE : ");
                                scanf("%d",&p);
                                delete_b(p);
                                break;
                        case 9: disp();
                                break;
                        case 10: exit(0);
                                 break;
                        default:printf("Wrong Input\n");
                }
        }
}
