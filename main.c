#include <stdio.h>
#include "unidirectionalList.h"

int main(void)
{
    T_Node *head = NULL;
    PrependNode(4, &head);
    PrependNode(3, &head);
    PrependNode(1, &head);
    PrependNode(6, &head);

    PrintList(head);

    int val;
    if (GetNodeByIndex(3, head, &val) == 0)
        printf("%d\n", val);
    else
        perror("GetNodeByIndex failed");

    if (UpdateNodeByIndex(3, 999, &head) != 0)
        perror("UpdateNodeByIndex failed");

    if (GetNodeByIndex(3, head, &val) == 0)
        printf("%d\n", val);
    else
        perror("GetNodeByIndex failed");

    PrintList(head);

    int sum = 0;
    if (PrependNodeAndCalcSum(32, &head, &sum) == 0)
        printf("sum :%d\n", sum);
    else
        perror("PrependNodeAndCalcSum failed");

    printf("idx: %zu\n", FindNode(999, head));

    FreeList(head);

    return 0;
}
