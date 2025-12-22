#ifndef UNIDIRECTIONAL_LIST_H
#define UNIDIRECTIONAL_LIST_H

/**
 * @file unidirectionalList.h
 * @brief 単方向リストの公開 API 定義
 * @details 本ヘッダは単方向（Singly Linked List）の基本操作を提供します。
 * 返り値規約: 0 = 成功, -1 = 失敗（詳細は status に設定）
 */

#include <stddef.h>
#include "status.h"

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
     * @return status
     */
    Status_E PrependNode(int data, Node_T **head);

    /**
     * @brief リストを標準出力へ表示する
     * @param head リスト先頭へのポインタ（NULL 可）
     */
    Status_E PrintList(const Node_T *head);

    /**
     * @brief リストの全メモリを解放する
     * @param head リスト先頭へのポインタ（NULL 可）
     */
    Status_E FreeList(Node_T *head);

    /**
     * @brief 指定インデックスのデータを取得する
     * @param index 0 基点のインデックス
     * @param head リスト先頭
     * @param out 取得した値を書き込むポインタ（NULL不可）
     * @return status
     */
    Status_E GetNodeByIndex(size_t index, const Node_T *head, int *out);

    /**
     * @brief 指定インデックスのデータを更新する
     * @param index 0 基点のインデックス
     * @param data 新しいデータ
     * @param head リスト先頭へのポインタのポインタ（NULL不可）
     * @return status
     */
    Status_E UpdateNodeByIndex(size_t index, int data, Node_T **head);

    /**
     * @brief 先頭に節を追加し、リスト中の合計値を計算する
     * @param data 追加するデータ
     * @param head リスト先頭へのポインタのポインタ（NULL不可）
     * @param out_sum 合計値を書き込むポインタ（NULL不可）
     * @return status
     */
    Status_E PrependNodeAndCalcSum(int data, Node_T **head, int *out_sum);

    /**
     * @brief データ値を探索し、その最初のインデックスを返す
     * @param data 探索する値
     * @param head リスト先頭
     * @param out 取得した値を書き込むポインタ
     * @return status
     */
    Status_E FindNode(int data, const Node_T *head, size_t *out);

#ifdef __cplusplus
}
#endif

#endif // UNIDIRECTIONAL_LIST_H
