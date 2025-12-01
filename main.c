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

    printf("%d\n", GetNodeByIndex(3, head));

    UpdateNodeByIndex(3, 999, &head);

    printf("%d\n", GetNodeByIndex(3, head));

    PrintList(head);

    printf("sum :%d\n", PrependNodeAndCalcSum(32, &head));

    printf("idx: %zu\n", FindNode(999, head));

    return 0;
}
