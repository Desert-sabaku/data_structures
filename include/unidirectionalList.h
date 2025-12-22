#ifndef UNIDIRECTIONAL_LIST_H
#define UNIDIRECTIONAL_LIST_H

/**
 * @file unidirectionalList.h
 * @brief 単方向リストの公開 API 定義
 * @details 本ヘッダは単方向（Singly Linked List）の基本操作を提供します。
 * 返り値規約: 0 = 成功, -1 = 失敗（詳細は errno に設定: ENOMEM/EINVAL/ERANGE など）
 */

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief リストの節（ノード）型
     */
    typedef struct Node_t
    {
        int data;            /**< 節に格納する整数データ */
        struct Node_t *next; /**< 次の節へのポインタ */
    } Node_T;

    /**
     * @brief リスト先頭に節を追加する
     * @param data 追加するデータ
     * @param head リスト先頭へのポインタのポインタ（NULL不可）
     * @return 0:成功, -1:失敗（errno に詳細）
     */
    int PrependNode(int data, Node_T **head);

    /**
     * @brief リストを標準出力へ表示する
     * @param head リスト先頭へのポインタ（NULL 可）
     */
    void PrintList(const Node_T *head);

    /**
     * @brief リストの全メモリを解放する
     * @param head リスト先頭へのポインタ（NULL 可）
     */
    void FreeList(Node_T *head);

    /**
     * @brief 指定インデックスのデータを取得する
     * @param index 0 基点のインデックス
     * @param head リスト先頭
     * @param out 取得した値を書き込むポインタ（NULL不可）
     * @return 0:成功, -1:失敗（errno に詳細）
     */
    int GetNodeByIndex(size_t index, const Node_T *head, int *out);

    /**
     * @brief 指定インデックスのデータを更新する
     * @param index 0 基点のインデックス
     * @param data 新しいデータ
     * @param head リスト先頭へのポインタのポインタ（NULL不可）
     * @return 0:成功, -1:失敗（errno に詳細）
     */
    int UpdateNodeByIndex(size_t index, int data, Node_T **head);

    /**
     * @brief 先頭に節を追加し、リスト中の合計値を計算する
     * @param data 追加するデータ
     * @param head リスト先頭へのポインタのポインタ（NULL不可）
     * @param out_sum 合計値を書き込むポインタ（NULL不可）
     * @return 0:成功, -1:失敗（errno に詳細）
     */
    int PrependNodeAndCalcSum(int data, Node_T **head, int *out_sum);

    /**
     * @brief データ値を探索し、その最初のインデックスを返す
     * @param data 探索する値
     * @param head リスト先頭
     * @return 見つかったインデックス、見つからなければ -1
     */
    size_t FindNode(int data, const Node_T *head);

#ifdef __cplusplus
}
#endif

#endif // UNIDIRECTIONAL_LIST_H
