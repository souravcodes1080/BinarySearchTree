#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * left, *right;
}node;

node * createBst(node*,int);
void pre(node*, int);
void in(node*,int);
void post(node*,int);


int main()
{
    node* root=NULL; 
    int ch, data;
    printf("\n0.Exit\n1.InsertItem\n2.Preorder\n3.Inorder\n4.Postorder\n");
    while(1){
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0:
            exit(0);
        case 1:
            printf("\nEnter data: ");
            scanf("%d",&data);
            root=createBst(root,data);
            break;
        case 2:
            pre(root,data);
            break;
        case 3:
            in(root,data);
            break;
        case 4:
            post(root,data);
            break;
        default:
            printf("\nWrong choice...");
            break;
        }
    }
    return 0;
}

node * createBst(node * root, int data)
{
    if(root==NULL){
        root=(node*)malloc(sizeof(node));
        root->left=NULL;
        root->data=data;
        root->right=NULL;
    }
    else if (data < root->data)
    {
        root->left=createBst(root->left,data);
    }
    else if (data> root->data)
    {
        root->right=createBst(root->right,data);
    }
    
    
}

void pre(node* root, int data)
{
    if(root!=NULL){
    printf("%d\t", root->data);
    pre(root->left, data);
    pre(root->right,data);
    }
}

void in(node* root, int data)
{
    if(root!=NULL){
    in(root->left, data);
    printf("%d\t", root->data);
    in(root->right,data);
    }
}

void post(node* root, int data)
{
    if(root!=NULL){
    post(root->left, data);
    post(root->right,data);
    printf("%d\t", root->data);
    }
}