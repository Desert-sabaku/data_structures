#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <vector>

struct Point
{
    int x;
    int y;
};

// implementation by delegation
class Stacker
{
private:
    size_t top;
    std::vector<Point> v;

public:
    Stacker();
    ~Stacker();
    void Push(Point data);
    Point Pop();
    bool IsEmpty();
    void Show();
};

#endif // STACK_HPP
