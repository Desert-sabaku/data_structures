#ifndef UNIDIRECTIONAL_LIST_HPP
#define UNIDIRECTIONAL_LIST_HPP

#include <iostream>
#include <string>
#include <memory>

struct Node_t
{
    std::string data;
    Node_t *next;
};

class List
{
private:
    size_t size;
    std::unique_ptr<Node_t> head;
    std::unique_ptr<Node_t> generate(std::string data);

public:
    List();
    ~List();
    void append(std::string data);
    void prepend(std::string data);
    void insertAt(size_t index, std::string data);
    std::string getAt(size_t index);
    void print() const;
    void delAt(size_t index);
    void clear();
    size_t getSize() const { return this->size; }
};

#endif // UNIDIRECTIONAL_LIST_HPP
