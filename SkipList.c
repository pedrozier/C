#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 10

typedef struct Node
{
    int key;
    int value;
    struct Node **forward;

} Node;

Node *createNode(int key, int value, int level)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->forward = (Node **)malloc(sizeof(Node *) * (level + 1));
    return newNode;
}

int randomLevel()
{
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL)
        level++;
    return level;
}

typedef struct SkipList
{
    int level;
    Node *header;
} SkipList;

SkipList *createSkipList()
{
    SkipList *list = (SkipList *)malloc(sizeof(SkipList));
    list->level = -1;
    list->header = (Node *)malloc(sizeof(Node));
    list->header->key = INT_MAX;
    list->header->forward = (Node **)calloc((MAX_LEVEL + 1), sizeof(Node *));

    return list;
}

Node *skipListSearch(SkipList *list, int key)
{
    Node *current = list->header;

    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && current->forward[i]->key < key)
        {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    if (current != NULL && current->key == key)
    {
        return current;
    }

    return NULL;
}

void skipListInsert(SkipList *list, int key, int value)
{
    Node *update[MAX_LEVEL + 1];
    Node *current = list->header;

    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && current->forward[i]->key < key)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current == NULL || current->key != key)
    {
        int newLevel = 0;
        while (rand() < RAND_MAX / 2 && newLevel < MAX_LEVEL)
        {
            newLevel++;
        }
        if (newLevel > list->level)
        {
            for (int i = list->level + 1; i <= newLevel; i++)
            {
                update[i] = list->header;
            }
            list->level = newLevel;
        }
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->key = key;
        newNode->value = value;
        newNode->forward = (Node **)calloc((newLevel + 1), sizeof(Node *));
        for (int i = 0; i <= newLevel; i++)
        {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

void skipListRemove(SkipList *list, int key)
{
    Node *update[MAX_LEVEL + 1];
    Node *current = list->header;

    for (int i = list->level; i >= 0; i--)
    {
        while (current->forward[i] != NULL && current->forward[i]->key < key)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current != NULL && current->key == key)
    {
        for (int i = 0; i <= list->level; i++)
        {
            if (update[i]->forward[i] == current)
            {
                update[i]->forward[i] = current->forward[i];
            }
        }
        free(current);
        while (list->level > 0 && list->header->forward[list->level] == NULL)
        {
            list->level--;
        }
    }
}

void skipListDestroy(SkipList *list)
{
    Node *current = list->header->forward[0];
    Node *temp;

    while (current != NULL)
    {
        temp = current->forward[0];
        free(current);
        current = temp;
    }
    free(list->header);
    free(list);
}

void skipListPrint(SkipList *list)
{
    printf("Skip List:\n");
    for (int i = list->level; i >= 0; i--)
    {
        Node *node = list->header->forward[i];
        printf("Level %d: ", i);
        while (node != NULL)
        {
            printf("%d -> ", node->key);
            node = node->forward[i];
        }
        printf("NULL\n");
    }
}

int main()
{
    srand(time(NULL));

    SkipList *list = createSkipList();

    for (int i = 0; i < 300; i++)
    {
        skipListInsert(list, i, i + 10);
    }

    skipListPrint(list);
    skipListRemove(list, 2);
    skipListPrint(list);

    int searchKey = 3;
    Node *result = skipListSearch(list, searchKey);
    if (result != NULL)
    {
        printf("Key %d found with value %d\n", searchKey, result->value);
    }
    else
    {
        printf("Key %d not found\n", searchKey);
    }

    skipListDestroy(list);

    getchar();

    return 0;
}
