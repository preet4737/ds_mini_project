#include <stdio.h>
#include <malloc.h>
// A binary root node has data, pointer to left child
// and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

int Structure(struct Node* root1, struct Node* root2)
{
    // 1. both empty
    if (root1==NULL && root2==NULL)
        return 1;
    // 2. both non-empty -> compare them
    if (root1!=NULL && root2!=NULL)
    {
        return
        (
            Structure(root1->left, root2->left) &&
            Structure(root1->right, root2->right)
        );
    }
    // 3. one empty, one not -> false
    return 0;
}

struct Node*Inorder(struct Node*root){

if(root!= NULL){
    Inorder(root->left);
    printf("%d  ",root->data);
    Inorder(root->right);
}

};

int Identical(struct Node* root1, struct Node* root2)
{
    /*1. both empty */
    if (root1==NULL && root2==NULL)
        return 1;

    /* 2. both non-empty -> compare them */
    if (root1!=NULL && root2!=NULL)
    {
        return
        (
            (root1->data == root2->data)&&
            Identical(root1->left, root2->left) &&
            Identical(root1->right, root2->right)
        );
    }

    /* 3. one empty, one not -> false */
    return 0;
}

struct Node* insert(struct Node*root,int val){
struct Node* ptr,*parentptr,*nodeptr;
ptr = (struct Node*)malloc(sizeof(struct Node));
ptr -> data = val;
ptr -> left = NULL;
ptr -> right = NULL;

if (root == NULL){
    root = ptr;
    root -> left = NULL;
    root -> right = NULL;
}

else{
    parentptr = NULL;
    nodeptr = root;
    while(nodeptr!= NULL){
        parentptr = nodeptr;
        if (val < nodeptr->data)
            nodeptr = nodeptr -> left;
        else
            nodeptr = nodeptr ->right;
    }

    if(val< parentptr->data)
        parentptr->left = ptr;
    else
        parentptr->right = ptr;
}
return root;
};

// Driver code
int main()
{
printf("***************************************************\n");
    int choice;
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;
    printf("1.Insert Element in root 1\n");
    printf("2.To Exit enter -1.\n");
    printf("Enter value of node:");
    scanf("%d",&choice);
    while(choice!= -1){
        root1 = insert(root1,choice);
        printf("Enter value of node:");
        scanf("%d",&choice);
    }
printf("***************************************************\n");
    printf("1.Insert Element in root 2\n");
    printf("2.To Exit enter -1.\n");
    printf("Enter value of node:");
    scanf("%d",&choice);
    while(choice!= -1){
        root2 = insert(root2,choice);
        printf("Enter value of node:");
        scanf("%d",&choice);
    }
printf("\n");
printf("******************root ELEMENTS********************\n");
printf("Tree1's elements:");
Inorder(root1);
printf("\n");
printf("Tree2's elements:");
Inorder(root2);
printf("\n");
printf("******************COMPARING************************\n");
if (root1 == NULL && root2 == NULL)
    printf("Trees cannot be compared\n");
else{
    if (Structure(root1, root2))
        printf("Both Trees have same structure\n");
    else
        printf("Trees do not have same structure\n");

    if (Identical(root1,root2))
        printf("Both Trees are identical");
    else
        printf("Trees are not identical");
}
    return 0;
}
