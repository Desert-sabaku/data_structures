#include <iostream>
#include "stack.hpp"

Stacker::Stacker()
{
    this->top = 0;
}

Stacker::~Stacker()
{
}

void Stacker::Push(Point data)
{
    this->top++;
    this->v.push_back(data);
}

Point Stacker::Pop()
{
    this->top--;
    auto temp = this->v.back();
    this->v.pop_back();
    return temp;
}

bool Stacker::IsEmpty()
{
    return this->top == 0;
}

void Stacker::Show()
{
    printf("    |            |\n");

    for (int i = this->top - 1; i >= 0; i--)
    {
        printf("[%2d]", i);
        if (i >= this->top)
            printf("|            |");
        else
            printf("| (%3d, %3d) |", this->v[i].x, this->v[i].y);
        if (i == this->top)
            printf("<-top\n");
        else
            printf("\n");
    }
    printf("    --------------\n");
}
