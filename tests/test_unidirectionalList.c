// tests/test_unidirectionalList.c
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "unidirectionalList.h"

// ============================================================================
// PrependNode のテスト
// ============================================================================

void test_prepend_node_single()
{
    Node_T *head = NULL;
    assert(PrependNode(5, &head) == 0);
    assert(head != NULL);
    assert(head->data == 5);
    assert(head->next == NULL);
    FreeList(head);
    printf("✓ test_prepend_node_single passed\n");
}

void test_prepend_node_multiple()
{
    Node_T *head = NULL;
    assert(PrependNode(3, &head) == 0);
    assert(PrependNode(2, &head) == 0);
    assert(PrependNode(1, &head) == 0);

    assert(head->data == 1);
    assert(head->next->data == 2);
    assert(head->next->next->data == 3);
    assert(head->next->next->next == NULL);

    FreeList(head);
    printf("✓ test_prepend_node_multiple passed\n");
}

void test_prepend_node_null_head_pointer()
{
    errno = 0;
    assert(PrependNode(5, NULL) == -1);
    assert(errno == EINVAL);
    printf("✓ test_prepend_node_null_head_pointer passed\n");
}

// ============================================================================
// GetNodeByIndex のテスト
// ============================================================================

void test_get_node_by_index_valid()
{
    Node_T *head = NULL;
    PrependNode(3, &head);
    PrependNode(2, &head);
    PrependNode(1, &head);

    int val;
    assert(GetNodeByIndex(0, head, &val) == 0);
    assert(val == 1);

    assert(GetNodeByIndex(1, head, &val) == 0);
    assert(val == 2);

    assert(GetNodeByIndex(2, head, &val) == 0);
    assert(val == 3);

    FreeList(head);
    printf("✓ test_get_node_by_index_valid passed\n");
}

void test_get_node_by_index_out_of_range()
{
    Node_T *head = NULL;
    PrependNode(1, &head);

    int val;
    errno = 0;
    assert(GetNodeByIndex(5, head, &val) == -1);
    assert(errno == ERANGE);

    FreeList(head);
    printf("✓ test_get_node_by_index_out_of_range passed\n");
}

void test_get_node_by_index_null_out()
{
    Node_T *head = NULL;
    PrependNode(1, &head);

    errno = 0;
    assert(GetNodeByIndex(0, head, NULL) == -1);
    assert(errno == EINVAL);

    FreeList(head);
    printf("✓ test_get_node_by_index_null_out passed\n");
}

void test_get_node_by_index_empty_list()
{
    Node_T *head = NULL;
    int val;

    errno = 0;
    assert(GetNodeByIndex(0, head, &val) == -1);
    assert(errno == ERANGE);

    printf("✓ test_get_node_by_index_empty_list passed\n");
}

// ============================================================================
// UpdateNodeByIndex のテスト
// ============================================================================

void test_update_node_by_index_valid()
{
    Node_T *head = NULL;
    PrependNode(3, &head);
    PrependNode(2, &head);
    PrependNode(1, &head);

    assert(UpdateNodeByIndex(1, 999, &head) == 0);

    int val;
    assert(GetNodeByIndex(1, head, &val) == 0);
    assert(val == 999);

    FreeList(head);
    printf("✓ test_update_node_by_index_valid passed\n");
}

void test_update_node_by_index_out_of_range()
{
    Node_T *head = NULL;
    PrependNode(1, &head);

    errno = 0;
    assert(UpdateNodeByIndex(5, 999, &head) == -1);
    assert(errno == ERANGE);

    FreeList(head);
    printf("✓ test_update_node_by_index_out_of_range passed\n");
}

void test_update_node_by_index_null_head()
{
    errno = 0;
    assert(UpdateNodeByIndex(0, 999, NULL) == -1);
    assert(errno == EINVAL);

    printf("✓ test_update_node_by_index_null_head passed\n");
}

void test_update_node_by_index_empty_list()
{
    Node_T *head = NULL;

    errno = 0;
    assert(UpdateNodeByIndex(0, 999, &head) == -1);
    assert(errno == EINVAL);

    printf("✓ test_update_node_by_index_empty_list passed\n");
}

// ============================================================================
// PrependNodeAndCalcSum のテスト
// ============================================================================

void test_prepend_node_and_calc_sum_single()
{
    Node_T *head = NULL;
    int sum;

    assert(PrependNodeAndCalcSum(5, &head, &sum) == 0);
    assert(sum == 5);

    FreeList(head);
    printf("✓ test_prepend_node_and_calc_sum_single passed\n");
}

void test_prepend_node_and_calc_sum_multiple()
{
    Node_T *head = NULL;
    int sum;

    assert(PrependNodeAndCalcSum(3, &head, &sum) == 0);
    assert(sum == 3);

    assert(PrependNodeAndCalcSum(2, &head, &sum) == 0);
    assert(sum == 5); // 2 + 3

    assert(PrependNodeAndCalcSum(1, &head, &sum) == 0);
    assert(sum == 6); // 1 + 2 + 3

    FreeList(head);
    printf("✓ test_prepend_node_and_calc_sum_multiple passed\n");
}

void test_prepend_node_and_calc_sum_null_out()
{
    Node_T *head = NULL;

    errno = 0;
    assert(PrependNodeAndCalcSum(5, &head, NULL) == -1);
    assert(errno == EINVAL);

    printf("✓ test_prepend_node_and_calc_sum_null_out passed\n");
}

void test_prepend_node_and_calc_sum_negative()
{
    Node_T *head = NULL;
    int sum;

    assert(PrependNodeAndCalcSum(10, &head, &sum) == 0);
    assert(sum == 10);

    assert(PrependNodeAndCalcSum(-5, &head, &sum) == 0);
    assert(sum == 5); // -5 + 10

    FreeList(head);
    printf("✓ test_prepend_node_and_calc_sum_negative passed\n");
}

// ============================================================================
// FindNode のテスト
// ============================================================================

void test_find_node_found()
{
    Node_T *head = NULL;
    PrependNode(5, &head);
    PrependNode(3, &head);
    PrependNode(1, &head);

    assert(FindNode(1, head) == 0);
    assert(FindNode(3, head) == 1);
    assert(FindNode(5, head) == 2);

    FreeList(head);
    printf("✓ test_find_node_found passed\n");
}

void test_find_node_not_found()
{
    Node_T *head = NULL;
    PrependNode(3, &head);
    PrependNode(1, &head);

    assert(FindNode(999, head) == (size_t)-1);

    FreeList(head);
    printf("✓ test_find_node_not_found passed\n");
}

void test_find_node_empty_list()
{
    Node_T *head = NULL;

    assert(FindNode(1, head) == (size_t)-1);

    printf("✓ test_find_node_empty_list passed\n");
}

// ============================================================================
// FreeList のテスト
// ============================================================================

void test_free_list_single()
{
    Node_T *head = NULL;
    PrependNode(5, &head);
    FreeList(head); // Should not crash
    printf("✓ test_free_list_single passed\n");
}

void test_free_list_multiple()
{
    Node_T *head = NULL;
    for (int i = 0; i < 10; i++)
    {
        PrependNode(i, &head);
    }
    FreeList(head); // Should not crash
    printf("✓ test_free_list_multiple passed\n");
}

void test_free_list_null()
{
    FreeList(NULL); // Should not crash
    printf("✓ test_free_list_null passed\n");
}

// ============================================================================
// メイン
// ============================================================================

int main(void)
{
    printf("===== Running Unit Tests =====\n\n");

    printf("--- PrependNode Tests ---\n");
    test_prepend_node_single();
    test_prepend_node_multiple();
    test_prepend_node_null_head_pointer();

    printf("\n--- GetNodeByIndex Tests ---\n");
    test_get_node_by_index_valid();
    test_get_node_by_index_out_of_range();
    test_get_node_by_index_null_out();
    test_get_node_by_index_empty_list();

    printf("\n--- UpdateNodeByIndex Tests ---\n");
    test_update_node_by_index_valid();
    test_update_node_by_index_out_of_range();
    test_update_node_by_index_null_head();
    test_update_node_by_index_empty_list();

    printf("\n--- PrependNodeAndCalcSum Tests ---\n");
    test_prepend_node_and_calc_sum_single();
    test_prepend_node_and_calc_sum_multiple();
    test_prepend_node_and_calc_sum_null_out();
    test_prepend_node_and_calc_sum_negative();

    printf("\n--- FindNode Tests ---\n");
    test_find_node_found();
    test_find_node_not_found();
    test_find_node_empty_list();

    printf("\n--- FreeList Tests ---\n");
    test_free_list_single();
    test_free_list_multiple();
    test_free_list_null();

    printf("\n===== All Tests Passed! =====\n");
    return 0;
}
