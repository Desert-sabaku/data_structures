#ifndef UNIDIRECTIONAL_LIST_H
#define UNIDIRECTIONAL_LIST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h>

    typedef struct t_Node
    {
        int data;
        struct t_Node *next;
    } T_Node;

    /**
     * @brief リストの先頭に節を追加する
     * @param data 追加する節のデータ
     * @param head リストの先頭節へのポインタへのポインタ
     */
    void PrependNode(int data, T_Node **head);

    /**
     * @brief リストを表示する
     * @param head リストの先頭節へのポインタ
     */
    void PrintList(T_Node *head);

    /**
     * @brief リストのメモリを解放する
     * @param head リストの先頭節へのポインタ
     */
    void FreeList(T_Node *head);

    /**
     * @brief 指定した場所のデータを取得する
     * @param index 場所の指定
     * @param head リストの先頭節へのポインタ
     * @return 指定した場所のデータ
     */
    int GetNodeByIndex(size_t index, T_Node *head);

    /**
     * @brief 指定した場所のデータを更新する
     * @param index 位置
     * @param data 新しいデータ
     * @param head リストの先頭節へのポインタへのポインタ
     */
    void UpdateNodeByIndex(size_t index, int data, T_Node **head);

    /**
     * @brief 先頭に節を追加し、リスト中のデータの合計を返す
     * @param data 追加するデータ
     * @param head リストの先頭節へのポインタへのポインタ
     * @return リスト内のデータの合計
     */
    int PrependNodeAndCalcSum(int data, T_Node **head);

    size_t FindNode(int, T_Node *head);

#ifdef __cplusplus
}
#endif

#endif // UNIDIRECTIONAL_LIST_H
