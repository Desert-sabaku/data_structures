// 単方向リストの実装

/*
返り値は関数の実行ステータスを返す.
呼び出し元に結果を返すときにはポインタを経由して受け渡す.
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "unidirectionalList.h"

/**
 * @brief 節を生成する内部関数
 * @param data 節に格納するデータ
 * @return 成功時は新しい節へのポインタ、失敗時は `NULL`（`errno`=`ENOMEM`）
 * @note 公開 API ではなく、実装内でのみ使用されます。
 */
static Node_T *GenerateNode(int data)
{
    Node_T *new_node = malloc(sizeof(Node_T));
    if (new_node == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int PrependNode(int data, Node_T **head)
{
    if (head == NULL)
    {
        errno = EINVAL;
        return -1;
    }
    Node_T *new_node = GenerateNode(data);
    if (new_node == NULL)
        return -1;
    new_node->next = *head;
    *head = new_node;
    return 0;
}

void PrintList(const Node_T *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void FreeList(Node_T *head)
{
    while (head != NULL)
    {
        Node_T *next_node = head->next;
        free(head);
        head = next_node;
    }
}

int GetNodeByIndex(size_t index, const Node_T *head, int *out)
{
    if (out == NULL)
    {
        errno = EINVAL;
        return -1;
    }
    const Node_T *current = head;
    for (size_t i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            errno = ERANGE;
            return -1;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        errno = ERANGE;
        return -1;
    }
    *out = current->data;
    return 0;
}

int UpdateNodeByIndex(size_t index, int data, Node_T **head)
{
    if (head == NULL || *head == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    Node_T *current = *head;
    for (size_t i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            errno = ERANGE;
            return -1;
        }
        current = current->next;
    }

    if (current)
    {
        current->data = data;
        return 0;
    }
    errno = ERANGE;
    return -1;
}

int PrependNodeAndCalcSum(int data, Node_T **head, int *out_sum)
{
    if (out_sum == NULL)
    {
        errno = EINVAL;
        return -1;
    }
    Node_T *new_node = GenerateNode(data);
    if (new_node == NULL)
        return -1;
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
    return 0;
}

size_t FindNode(int data, const Node_T *head)
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
