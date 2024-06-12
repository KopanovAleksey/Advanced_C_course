#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

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

void findMinMax(node *root, int *min, int *max){
    if (!root)
        return;
    if(root->key > *max)
        *max = root->key;
    if(root->key < *min)
        *min = root->key;
    if(root->left)
        findMinMax(root->left, min, max);
    if(root->right)
        findMinMax(root->right, min, max);
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

    int min = INT_MAX;
    int max = INT_MIN;
    findMinMax(tree, &min, &max);
    printf("Dif = %d\n", max - min);


    return 0;
}
