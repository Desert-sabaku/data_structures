#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "unidirectionalList.h"
#include "status.h"

static void flush_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

static void print_menu(void)
{
    printf("\n=== Singly Linked List Menu ===\n");
    printf("1) Prepend value\n");
    printf("2) Get value by index\n");
    printf("3) Update value by index\n");
    printf("4) Find index by value\n");
    printf("5) Print list\n");
    printf("6) Free list\n");
    printf("0) Exit\n");
}

int main(void)
{
    Node_T *head = NULL;
    bool running = true;

    while (running)
    {
        int choice;
        print_menu();
        printf("> ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            flush_stdin();
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int value;
            printf("Value to prepend: ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid number.\n");
                flush_stdin();
                break;
            }
            Status_E status = PrependNode(value, &head);
            printf("PrependNode -> %s\n", status_to_string(status));
            break;
        }

        case 2:
        {
            size_t index;
            printf("Index to get: ");
            if (scanf("%zu", &index) != 1)
            {
                printf("Invalid index.\n");
                flush_stdin();
                break;
            }
            int value;
            Status_E status = GetNodeByIndex(index, head, &value);
            if (status == SUCCESS)
            {
                printf("Value at index %zu: %d\n", index, value);
            }
            else
            {
                printf("GetNodeByIndex failed: %s\n", status_to_string(status));
            }
            break;
        }

        case 3:
        {
            size_t index;
            int value;
            printf("Index to update: ");
            if (scanf("%zu", &index) != 1)
            {
                printf("Invalid index.\n");
                flush_stdin();
                break;
            }
            printf("New value: ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid value.\n");
                flush_stdin();
                break;
            }
            Status_E status = UpdateNodeByIndex(index, value, &head);
            printf("UpdateNodeByIndex -> %s\n", status_to_string(status));
            break;
        }

        case 4:
        {
            int value;
            printf("Value to find: ");
            if (scanf("%d", &value) != 1)
            {
                printf("Invalid value.\n");
                flush_stdin();
                break;
            }
            size_t idx;
            Status_E status = FindNode(value, head, &idx);
            if (status == SUCCESS)
            {
                printf("Found value %d at index %zu\n", value, idx);
            }
            else
            {
                printf("FindNode failed: %s\n", status_to_string(status));
            }
            break;
        }

        case 5:
            if (head == NULL)
            {
                printf("List is empty.\n");
            }
            else
            {
                PrintList(head);
            }
            break;

        case 6:
            FreeList(head);
            head = NULL;
            printf("List freed.\n");
            break;

        case 0:
            running = false;
            break;

        default:
            printf("Unknown option.\n");
            break;
        }
    }

    FreeList(head);
    return 0;
}
