/* The given file gives the basics of a dynamic binary search tree, with it providing multiple sub-facets for the user to choose
from, them being, respectively: 
          1) Insert in the BST (with it automatically sorting it to go in the correct spot.)
          2) An Inorder Traversal of the BST and displaying it. 
          3) Searching in the BST for the given element. 
          4) Deletion of an element in the BST and then reordering the tree. 
          
This is a program written in C, with comments explaining the logic behind it. The Binary search tree is best used for searching,
rather than the linked list - for the searching factor would at max be O(n) and usually, would be O(log n.)

*/




#include<stdio.h>
#include<stdlib.h>


struct tnode
{
    int data;
    struct tnode *right;//Creatiing a pointer node right - used for going to the right
    struct tnode *left;//Creating a pointer node left - used for going to the left part of the BST.
};

struct tnode* CreateBST(struct tnode *root, int item)
{
  if(root==NULL)//checks if the root is first node
  {
    root = (struct tnode *)malloc(sizeof(struct tnode));
    root->left = root->right = NULL;
    root->data = item;
    return root;
  }

  else
  {
    if(item< root->data)
      root->left = CreateBST(root->left, item);
      //checks if the value is less then the value in the root and then makes a recursive function - adding it to the 'L' of the node. Node goes like: L||value||R - where L and R are nodes.
      //It adds to 'R' of the node when the value is greater than the value in the previous node.
    if(item>root->data)
      root->right = CreateBST(root->right, item);
  }
  return(root); //returns the actual root, for if the last L or R is returned, the whole other Side is ignored - destroying the purpose of the BST.
}

void Inorder(struct tnode * root)
{
  if(root != NULL)
  {
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
  }
}


struct tnode * SearchBST(struct tnode * root, int key)
{
  if(root==NULL)//Checks if the root is node, making it that the tree is empty.
  {
      printf("No nodes in tree\n");
      return 0;
  }
  else
  {
    if(root->data == key)//Checks if the key is in the current root.
      printf("Print found!\n");
    if(key<root->data)//If root is less than data, it goes to the left part of the tree.
    {
      root->left =SearchBST(root->left, key);//Calls a recursive function to go towards the left side.

    }
    if(key>root->data)
    {
      root->right = SearchBST(root->right, key);//Calls a recursive function to go to the right side.
    }

  }
  return(root);
}

struct tnode *findMin(struct tnode *root)
{
  struct tnode *temp = root;
  while(temp->left!= NULL)//Checks for the value of the next root of temp and confirms it to not be NULL
  {
    temp=temp->left;
  }
  return temp;
}

struct tnode* Delete(struct tnode* root, int item)
{
  if(root ==NULL)//Checks if the root is NULL
  {
    return root;
  }
  else if(item<root->data)//Traversing in the tree, going towards the left, then searching the element.
  {
    root->left =Delete(root->left, item);
  }
  else if(item>root->data)//Traversing in the tree, going towards the right, then searching the element which is to be deleted.
  {
    root->right = Delete(root->right, item);
  }
  else
  {
    if(root->left==NULL && root->right==NULL)//Case when there is only a leaf and no other children spawining from it. Delete the leaf.
    {
      free(root);
      root=NULL;
      return root;
    }
    else if(root->left==NULL && root->right != NULL)//Case when the root has only one child on the right side.
    {
      struct tnode* temp=root;
      root=root->right;
      printf("%d deleted!", temp->data);
      free(temp);
      return root;
    }
    else if( root->left != NULL && root->right == NULL)//Case when the root has only one child on the left side.
    {
      struct tnode* temp = root;
      root= root->left;
      printf("%d  deleted!", temp->data);
      free(temp);
      return root;
    }
    else//Case when the tree has two children, then finds the mininmum of it on the right side, then deletes that after shifting it with the minimum.
    {
      struct tnode * temp = findMin(root->right);
      root->data=temp->data;//Keeping the data of root in the temp variable.
      root->right=Delete(root->right, temp->data);
      return root;
    }
  }
}


int main()
{
  struct tnode *root = NULL;
  int ch, item;
  do
  {
      printf("\nEnter the choice you want to take\n1. Insert\n2. Print the data of the BST\n3. Search\n4. Deletion of the node.\n5.Exit\n");
      scanf("%d", &ch);
      switch(ch)
      {
        case 1:
                  printf("\nEnter the data for the node  : ");
                  scanf("%d", &item);
                  root = CreateBST(root, item);
                  break;

        case 2:
                  Inorder(root);
                  break;
        case 3:
                printf("\nEnter the value you want to search :: " );
                scanf("%d", &item);
                root = SearchBST(root, item);
                break;

        case 4: printf("\nEnter the value you want to delete :: ");
                scanf("%d", &item);//Using the same variable and overwriting it with the value you want to delete. Can use a different var for more clarity.
                root = Delete(root, item);
                break;
        case 5:

                break;
        default: break;
      }
  }while(ch!=5);
}
