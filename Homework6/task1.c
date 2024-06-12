#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STR_SIZE 1000

typedef struct node
{
    char *word;
    struct node *next;
} node;

node *insert(node *list, char *value){
    node *newNode = calloc(1, sizeof(node));
    int len = strlen(value);
    newNode->word = malloc(len+1);
    strcpy(newNode->word, value);
    if(!list){
        newNode->next = list;
        return newNode;
    }
    node *ptr = list;
    while (ptr->next)
        ptr = ptr->next;
    ptr->next = newNode;
    return list;
}

void printFnL(node *list){
    if(!list)
        return;
    node *ptr = list;
    printf("%s ", ptr->word);
    while(ptr->next)
        ptr = ptr->next;
    printf("%s",ptr->word);
}

int main(int argc, char const *argv[])
{
    node *list = NULL;
    char word[STR_SIZE] = "";
    int ch = ' ';
    int i=0;
    while(EOF != (ch = getchar())){
        switch(ch){
            case '.':
            case ' ':
                word[i] = '\0';
                list = insert(list, word);
                i=0;
                break;
            default:
                word[i++] = ch;
                if(i>=STR_SIZE)
                    i=0;
        }
        if('.' == ch)
            break;
    }

    printFnL(list);

    return 0;
}
