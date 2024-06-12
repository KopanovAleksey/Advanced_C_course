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

void deleteOdd(node *list){
    if(!list)
        return;
    int i = 0;
    node *ptr = list;
    while (ptr->next && ptr->next->next)
    {
        i++;
        if(i % 2 != 0 && ptr->next->next){
            node *temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
            i++;
        }
        ptr = ptr->next;
    }
    if(i % 2 == 0){
        node *temp = ptr->next;
        ptr->next = NULL;
        free(temp);
    } 
}

void print(node *list){
    if(!list)
        return;
    node *ptr = list;
    while(ptr->next){
        printf("%s ", ptr->word);
        ptr = ptr->next;
    }
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
    print(list);
    printf("\n");
    deleteOdd(list);
    print(list);
    return 0;
}
