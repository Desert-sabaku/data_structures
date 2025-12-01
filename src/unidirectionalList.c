// 単方向リストの実装

#include <stdio.h>
#include <stdlib.h>
#include "unidirectionalList.h"

static T_Node *GenerateNode(int data)
{
    T_Node *new_node = malloc(sizeof(T_Node));
    if (new_node == NULL)
    {
        fprintf(stderr, "failed: memory allocation");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void PrependNode(int data, T_Node **head)
{
    T_Node *new_node = GenerateNode(data);
    new_node->next = *head;
    *head = new_node;
}

void PrintList(T_Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void FreeList(T_Node *head)
{
    while (head != NULL)
    {
        T_Node *next_node = head->next;
        free(head);
        head = next_node;
    }
}

int GetNodeByIndex(size_t index, T_Node *head)
{
    T_Node *current = head;
    for (size_t i = 0; i < index; i++)
    {
        if (current == NULL)
            return 0; /* out-of-range: return 0 (could also handle via error) */
        current = current->next;
    }
    return current ? current->data : 0;
}

void UpdateNodeByIndex(size_t index, int data, T_Node **head)
{
    if (head == NULL || *head == NULL)
        return;

    T_Node *current = *head;
    for (size_t i = 0; i < index; i++)
    {
        if (current == NULL)
            return; /* out-of-range */
        current = current->next;
    }

    if (current)
        current->data = data;
}

int PrependNodeAndCalcSum(int data, T_Node **head)
{
    T_Node *new_node = GenerateNode(data);
    new_node->next = *head;
    *head = new_node;

    int sum = 0;
    T_Node *current = *head;
    while (current)
    {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

size_t FindNode(int data, T_Node *head)
{
    size_t idx = 0;
    while (head)
    {
        if (head->data == data)
            return idx;
        head = head->next;
        idx++;
    }
    return (size_t)-1; // Not found
}
