//Binary Search Tree Implementation
#include<conio.h>
#include<stdio.h>
struct node
{
  struct node *left;
  int data;
  struct node *right;
};
struct queue
{
  int capacity;
  struct node **nodeArr;
  int top;
};
int isEmpty(struct queue *q);
struct queue* createQueue(int cap);
void enQueue(struct queue *q,struct node *n);
struct node* deQueue(struct queue *q);
struct queue* deleteQueue(struct queue *q);
void preOrderTraversal(struct node *root);
void inOrderTraversal(struct node *root);
void postOrderTraversal(struct node *root);
void levelOrderTraversal(struct node *root);
void Insert(struct node **root,int data);
struct node* Find(struct node *root,int data);
struct node* Delete(struct node **root,int data);
struct node* FindMax(struct node *root);
struct queue* deleteQueue(struct queue *q)
{
  if(q)
  {
    if(q->nodeArr)
    {
       free(q->nodeArr);
    }
    free(q);
  }
  q=NULL;
  return(q);
}
struct node* deQueue(struct queue *q)
{
  struct node *temp;
  temp=q->nodeArr[q->top];
  q->top--;
  return(temp);
}
void enQueue(struct queue *q,struct node *n)
{
  q->top++;
  q->nodeArr[q->top]=n;
}
struct queue* createQueue(int cap)
{
  struct queue *q;
  q=(struct queue*)malloc(sizeof(struct queue));
  q->capacity=cap;
  q->top=-1;
  *(q->nodeArr)=(struct node*)malloc(sizeof(struct node*)*cap);
  return(q);
}
int isEmpty(struct queue *q)
{
  if(q->top==-1)
    return(1);
  else
    return(0);
}
void levelOrderTraversal(struct node *root)
{
struct node *temp;
  struct queue *Q;
  Q=createQueue(10);
  enQueue(Q,root);
  if(root==NULL)
    return;
  while(!isEmpty(Q))
  {
    temp=deQueue(Q);
    printf(" %d",temp->data);
      if(temp->left)
	enQueue(Q,temp->left);
      if(temp->right)
	enQueue(Q,temp->right);
  }
  Q=deleteQueue(Q);
}
struct node* FindMax(struct node *root)
{
  struct node *temp,*n;
  n=root->left;
  temp=n;
  while(n!=NULL)
  {
    if(temp->data<n->data)
      temp=n;
    n=n->right;
  }
  return(temp);
}
struct node* Delete(struct node **root,int data)
{
struct node *temp;
  if(*root==NULL)
    printf("\nData can not be found");
  else if(data<(*root)->data)
    (*root)->left=Delete(&(*root)->left,data);
  else if(data>(*root)->data)
    (*root)->right=Delete(&(*root)->right,data);
  else
  {
    if((*root)->left&&(*root)->right)
    {
      temp=FindMax(*root);
      (*root)->data=temp->data;
      (*root)->left=Delete(&((*root)->left),temp->data);
    }
    else
    {
    temp=*root;
      if((*root)->left==NULL)
	*root=(*root)->right;
      else
	*root=(*root)->left;
      free(temp);
    }
  }
  return(*root);
}
struct node* Find(struct node *root,int data)
{
struct node *temp;
  temp=root;
  while(1)
  {
    if(data<temp->data)
    {
      if(temp->left==NULL)
	return(temp);
	temp=temp->left;
    }
    else
    {
      if(temp->right==NULL)
	return(temp);
	temp=temp->right;
    }
  }
}
void Insert(struct node **root,int data)
{
  struct node *n,*temp;
  n=(struct node*)malloc(sizeof(struct node));
  n->left=NULL;
  n->data=data;
  n->right=NULL;
  if(*root==NULL)
    *root=n;
  else
  {
    temp=Find(*root,data);
    if(data<temp->data)
      temp->left=n;
    else
      temp->right=n;
  }
}
void preOrderTraversal(struct node *root)
{
  if(root!=NULL)
  {
    printf(" %d",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}
void inOrderTraversal(struct node *root)
{
  if(root!=NULL)
  {
    inOrderTraversal(root->left);
    printf(" %d",root->data);
    inOrderTraversal(root->right);
  }
}
void postOrderTraversal(struct node *root)
{
  if(root!=NULL)
  {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf(" %d",root->data);
  }
}
void main()
{
struct node *root=NULL;
clrscr();
Insert(&root,10);
Insert(&root,5);
Insert(&root,4);
Insert(&root,6);
Insert(&root,15);
Insert(&root,16);
levelOrderTraversal(root);
getch();
}


















