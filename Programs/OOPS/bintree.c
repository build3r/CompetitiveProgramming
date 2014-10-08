#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *father;
	struct node *left;
	struct node *right;
};

struct node *root=NULL, *ne;

void maketree(int x)
{
    ne=(struct node *)malloc(sizeof(struct node));
    ne->info=x;
    ne->father=NULL;
    ne->left=NULL;
    ne->right=NULL;
    if(root==NULL)
    root=ne;
    else
    ins(root,x);
}

void ins(struct node *root,int x)
{
    if(root->info==x)
    {
        printf("%d element is duplicate\n",x);
        return;
    }
    if(root->info>x)
    {
        if(root->left==NULL)
        {
            root->left=ne;
            ne->father=root;
        }
        else
        ins(root->left,x);
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=ne;
            ne->father=root;
        }
        else
        ins(root->right,x);
    }
}

void inorder(struct node *root)
{
    if(root->left!=NULL)
    inorder(root->left);
    printf("->%d",root->info);
    if(root->right!=NULL)
    inorder(root->right);
}

void preorder(struct node *root)
{
    printf("->%d",root->info);
    if(root->left!=NULL)
    preorder(root->left);
    if(root->right!=NULL)
    preorder(root->right);
}

void postorder(struct node *root)
{

    if(root->left!=NULL)
    postorder(root->left);
    if(root->right!=NULL)
    postorder(root->right);
    printf("->%d",root->info);
}

int main()
{
	int ch, a;
	root = NULL;
	while (ch!=5)
	{
		printf("enter choice :\n");
		printf("1.insert\n2.inorder\n3.preorder\n4.postorder\n5.exit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("enter the element to be inserted :\n");
			scanf("%d", &a);
			maketree(a);
			break;

		case 2:
			inorder(root);
			printf("\n");
			break;

		case 3:
			preorder(root);
			printf("\n");
			break;

		case 4:
			postorder(root);
			printf("\n");
			break;

		case 5:
	               printf("now exiting\n");
	               break;

		default:
			printf("wrong choice \n");
		}
	}
	return 0;
}
