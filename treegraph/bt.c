#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to perform inorder traversal of the binary tree
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to perform preorder traversal of the binary tree
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform postorder traversal of the binary tree
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void insertion(struct Node *root)
{
    struct Node *lc, *rc;
    int ch;
    if (root != NULL)
    {
        printf("\nEnter the data: ");
        scanf("%d", &root->data);
        root->left = NULL;
        root->right = NULL;
        printf("\nDo you want to create left child for %d (1/0)?", root->data);
        scanf("%d", &ch);
        if (ch == 1)
        {
            lc = (struct Node *)malloc(sizeof(struct Node));
            root->left = lc;
            insertion(lc);
        }
        printf("\nDo you want to create right child for %d (1/0)?", root->data);
        scanf("%d", &ch);
        if (ch == 1)
        {
            rc = (struct Node *)malloc(sizeof(struct Node));
            root->right = rc;
            insertion(rc);
        }
    }
}

int main()
{
    struct Node *root = NULL; // Initialize an empty binary tree
    root = (struct Node *)malloc(sizeof(struct Node));
    insertion(root);

    // Performing traversals
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
