#include <stdio.h>
#include <malloc.h>
// A binary tree node has data, pointer to left child
// and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

int isSameStructure(struct Node* a, struct Node* b)
{
    // 1. both empty
    if (a==NULL && b==NULL)
        return 1;
    // 2. both non-empty -> compare them
    if (a!=NULL && b!=NULL)
    {
        return
        (
            isSameStructure(a->left, b->left) &&
            isSameStructure(a->right, b->right)
        );
    }
    // 3. one empty, one not -> false
    return 0;
}

struct Node*Inorder(struct Node*tree){

if(tree!= NULL){
    Inorder(tree->left);
    printf("%d  ",tree->data);
    Inorder(tree->right);
}

};
struct Node* insert(struct Node*tree,int val){
struct Node* ptr,*parentptr,*nodeptr;
ptr = (struct Node*)malloc(sizeof(struct Node));
ptr -> data = val;
ptr -> left = NULL;
ptr -> right = NULL;

if (tree == NULL){
    tree = ptr;
    tree -> left = NULL;
    tree -> right = NULL;
}

else{
    parentptr = NULL;
    nodeptr = tree;
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
return tree;
};

// Driver code
int main()
{
printf("***************************************************\n");
    int choice;
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;
    printf("1.Insert Element in Tree 1\n");
    printf("2.To Exit enter -1.\n");
    printf("Enter value of node:");
    scanf("%d",&choice);
    while(choice!= -1){
        root1 = insert(root1,choice);
        printf("Enter value of node:");
        scanf("%d",&choice);
    }
printf("***************************************************\n");
    printf("1.Insert Element in Tree 2\n");
    printf("2.To Exit enter -1.\n");
    printf("Enter value of node:");
    scanf("%d",&choice);
    while(choice!= -1){
        root2 = insert(root2,choice);
        printf("Enter value of node:");
        scanf("%d",&choice);
    }
printf("\n");
printf("******************TREE ELEMENTS********************\n");
printf("Tree one elements:");
Inorder(root1);
printf("\n");
printf("Tree two elements:");
Inorder(root2);
printf("\n");
printf("******************COMPARING************************\n");
printf("THE RESULT IS .............\n");
    if (isSameStructure(root1, root2))
        printf("Both trees have same structure");
    else
        printf("Trees do not have same structure");

    return 0;
}
