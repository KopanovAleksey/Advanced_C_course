#include<stdlib.h>
#include<stdio.h>

#define datatype int

typedef struct node{
    datatype key;
    struct node *left, *right;
} node;

void insert(node **root, int key){
    if(!(*root)){
        *root = calloc(1,sizeof(node));
        (*root)->key = key;
    }
    else if(key < (*root)->key)
        insert(&((*root)->left), key);
    else
        insert(&((*root)->right), key);
}

void printInOrder(node *root){
    if (root == NULL)
        return;
    if(root->left)
        printInOrder(root->left);
    printf("%d ", root->key);
    if(root->right)
        printInOrder(root->right);
}

int sumTreeKeys(node *root){
    int sum = 0;
    if (!root)
        return sum;
    sum += root->key;
    if(root->left)
        sum += sumTreeKeys(root->left);
    if(root->right)
        sum += sumTreeKeys(root->right);
    return sum;
}

int main(int argc, char const *argv[])
{
    node *tree = NULL;
    insert(&tree, 10);
    insert(&tree, 5);
    insert(&tree, 15);
    insert(&tree, 3);
    insert(&tree, 7);
    insert(&tree, 13);
    insert(&tree, 18);
    insert(&tree, 1);
    insert(&tree, 6);

    printInOrder(tree);
    printf("\n%d", sumTreeKeys(tree));

    return 0;
}
