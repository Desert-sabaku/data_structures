// 単方向リストの実装

#include <stdio.h>
#include <stdlib.h>
#include "unidirectionalList.h"
#include "status.h"

/**
 * @brief 節を生成する内部関数
 * @param data 節に格納するデータ
 * @return 成功時は新しい節へのポインタ、失敗時は `NULL`
 * @note 公開 API ではなく、実装内でのみ使用されます。
 */
static Node_T *GenerateNode(int data)
{
    Node_T *new_node = malloc(sizeof(Node_T));
    if (new_node == NULL)
    {
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Status_E PrependNode(int data, Node_T **head)
{
    if (head == NULL)
        return ERR_INVALID_ARG;

    Node_T *new_node = GenerateNode(data);
    if (new_node == NULL)
        return ERR_OUT_OF_MEMORY;

    new_node->next = *head;
    *head = new_node;
    return SUCCESS;
}

Status_E PrintList(const Node_T *head)
{
    if (head == NULL)
        return ERR_INVALID_ARG;

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
    return SUCCESS;
}

Status_E FreeList(Node_T *head)
{
    while (head != NULL)
    {
        Node_T *next_node = head->next;
        free(head);
        head = next_node;
    }
    return SUCCESS;
}

Status_E GetNodeByIndex(size_t index, const Node_T *head, int *out)
{
    if (out == NULL)
    {
        return ERR_INVALID_ARG;
    }

    const Node_T *current = head;
    for (size_t i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            return ERR_RANGE;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        return ERR_RANGE;
    }
    *out = current->data;
    return SUCCESS;
}

Status_E UpdateNodeByIndex(size_t index, int data, Node_T **head)
{
    if (head == NULL || *head == NULL)
    {
        return ERR_INVALID_ARG;
    }

    Node_T *current = *head;
    for (size_t i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            return ERR_RANGE;
        }
        current = current->next;
    }

    if (current)
    {
        current->data = data;
        return SUCCESS;
    }
    return ERR_RANGE;
}

Status_E PrependNodeAndCalcSum(int data, Node_T **head, int *out_sum)
{
    if (out_sum == NULL)
    {
        return ERR_INVALID_ARG;
    }
    Node_T *new_node = GenerateNode(data);
    if (new_node == NULL)
        return ERR_OUT_OF_MEMORY;
    new_node->next = *head;
    *head = new_node;

    int sum = 0;
    Node_T *current = *head;
    while (current)
    {
        sum += current->data;
        current = current->next;
    }
    *out_sum = sum;
    return SUCCESS;
}

Status_E FindNode(int data, const Node_T *head, size_t *out)
{
    size_t idx = 0;
    while (head)
    {
        if (head->data == data)
        {
            *out = idx;
            return SUCCESS;
        }
        head = head->next;
        idx++;
    }
    return NOT_FOUND;
}
