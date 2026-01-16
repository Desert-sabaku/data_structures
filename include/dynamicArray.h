#ifndef ARRAY_H
#define ARRAY_H

/**
 * @file array.h
 * @brief 配列操作の公開 API 定義
 * @details 本ヘッダは動的配列の基本操作を提供します。
 * 返り値規約: 0 = 成功, -1 = 失敗（詳細は status に設定）
 */

#include <stddef.h>
#include "status.h"

#ifdef __cplusplus
extern "C"
{
#endif
    /**
     * @brief 動的配列型
     */
    typedef struct DynamicArray_t
    {
        int *data;       /**< 配列データへのポインタ */
        size_t size;     /**< 現在の要素数 */
        size_t capacity; /**< 配列の容量 */
    } DynamicArray_T;

    /**
     * @brief 動的配列を初期化する
     * @param array 初期化する配列へのポインタ（NULL不可）
     * @param initial_capacity 初期容量
     * @return status
     */
    Status_E InitDynamicArray(DynamicArray_T *array, size_t initial_capacity);

    /**
     * @brief 動的配列に要素を追加する
     * @param array 要素を追加する配列へのポインタ（NULL不可）
     * @param value 追加する値
     * @return status
     */
    Status_E AppendToDynamicArray(DynamicArray_T *array, int value);

    /**
     * @brief 動的配列の全メモリを解放する
     * @param array 解放する配列へのポインタ（NULL不可）
     * @return status
     */
    Status_E FreeDynamicArray(DynamicArray_T *array);

    /**
     * @brief 動的配列の指定インデックスの要素を削除する
     * @param array 要素を削除する配列へのポインタ（NULL不可）
     * @param index 削除する要素のインデックス
     * @return status
     */
    Status_E DeleteDynamicArrayAt(DynamicArray_T *array, size_t index);
#ifdef __cplusplus
}
#endif

#endif /* ARRAY_H */
