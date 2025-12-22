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
    MYLIB_SUCCESS = 0,

    /* * --- 汎用エラー (General Errors) ---
     * 多くのAPIで共通して発生しうるエラーです。
     */

    /* 不正な引数 (Null pointer, 範囲外の値など) */
    MYLIB_ERR_INVALID_ARG,

    /* メモリ確保失敗 (malloc 失敗など) */
    MYLIB_ERR_OUT_OF_MEMORY,

    /* リソースが見つからない (ファイルなし、キーなし) */
    MYLIB_ERR_NOT_FOUND,

    /* 既に存在する (重複登録など) */
    MYLIB_ERR_ALREADY_EXISTS,

    /* 許可されていない操作 (権限不足、状態不一致) */
    MYLIB_ERR_NOT_PERMITTED,

    /* --- システム/IOエラー (System/IO Errors) --- */

    /* 内部エラー (予期しないシステムコールの失敗など) */
    MYLIB_ERR_INTERNAL,

    /* IOエラー (読み込み/書き込み失敗、ネットワーク切断) */
    MYLIB_ERR_IO,

    /* タイムアウト */
    MYLIB_ERR_TIMEOUT,

    /* * --- ドメイン固有エラー (Domain Specific Errors) ---
     * ここにあなたのAPI特有のエラーを追加します。
     */
    MYLIB_ERR_PARSE_FAILED,
    MYLIB_ERR_INVALID_FORMAT,

    /* 番兵: エラーコードの総数を知るため、あるいは範囲チェック用 */
    MYLIB_ERR_COUNT

} Status_E;

#endif // STATUS_H
