#ifndef STATUS_H
#define STATUS_H

/**
 * @file status.h
 * @brief 共通ステータスコード定義
 * @details このヘッダはプロジェクト全体で使用される共通のステータスコードを定義します。
 */

typedef enum Status_e
{
    /* * 0: 成功 (Success)
     * 一般的に 0 を成功とするのが C言語界隈の最大の慣習です。
     */
    SUCCESS = 0,

    /* * --- 汎用エラー (General Errors) ---
     * 多くのAPIで共通して発生しうるエラーです。
     */

    /* 不正な引数 (Null pointer, 範囲外の値など) */
    ERR_INVALID_ARG,

    /* メモリ確保失敗 (malloc 失敗など) */
    ERR_OUT_OF_MEMORY,

    /* リソースが見つからない (ファイルなし、キーなし) */
    ERR_NOT_FOUND,

    /* 既に存在する (重複登録など) */
    ERR_ALREADY_EXISTS,

    /* 許可されていない操作 (権限不足、状態不一致) */
    ERR_NOT_PERMITTED,

    /* --- システム/IOエラー (System/IO Errors) --- */

    /* 内部エラー (予期しないシステムコールの失敗など) */
    ERR_INTERNAL,

    /* IOエラー (読み込み/書き込み失敗、ネットワーク切断) */
    ERR_IO,

    /* タイムアウト */
    ERR_TIMEOUT,

    /* * --- ドメイン固有エラー (Domain Specific Errors) ---
     * ここにあなたのAPI特有のエラーを追加します。
     */

    ERR_RANGE,

    NOT_FOUND,

    /* 番兵: エラーコードの総数を知るため、あるいは範囲チェック用 */
    ERR_COUNT

} Status_E;

#endif // STATUS_H
