#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char key;
    struct Node *left, *right;
};

struct Node* newNode(char key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;

    return node;
}

int height(struct Node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

struct Node* construct(char inorder[], int start, int end, char preorder[], char *pIndex)
{

    if (start > end) {
        return NULL;
    }

    struct Node* node = newNode(preorder[(*pIndex)++]);
    int i;
    for (i = start; i <= end; i++)
    {
        if (inorder[i] == node->key) {
            break;
        }
    }


    node->left = construct(inorder, start, i - 1, preorder, pIndex);


    node->right = construct(inorder, i + 1, end, preorder, pIndex);

    return node;
}

struct Node* constructTree(char inorder[], char preorder[], int n)
{
    int pIndex = 0;

    return construct(inorder, 0, n - 1, preorder, &pIndex);
}

void printCurrentLevel(struct Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%c ", root->key);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(struct Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main()
{


    char inorder[] = {'D', 'B', 'E', 'A', 'F', 'C', 'G'};
    char preorder[] = {'A', 'B', 'D', 'E', 'C', 'F', 'G'};
    int n = sizeof(inorder)/sizeof(inorder[0]);

    struct Node* root = constructTree(inorder, preorder, n);


    printf("The postorder traversal is "); 

    printLevelOrder(root);

    return 0;
}