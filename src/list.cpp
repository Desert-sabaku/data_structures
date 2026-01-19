/**
 * @file list.cpp
 * @brief 単方向リストの実装
 * @details 本ファイルは単方向（Singly Linked List）の基本操作を実装します。
 */

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
    void print() const;
    void delAt(size_t index);
    void clear();
    size_t getSize() const { return this->size; }
};

List::List()
{
    this->size = 0;
    this->head = nullptr;
}

List::~List()
{
    clear();
}

std::unique_ptr<Node_t> List::generate(std::string data)
{
    auto new_node = std::make_unique<Node_t>();
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

void List::append(std::string data)
{
    insertAt(this->size, data);
}

void List::prepend(std::string data)
{
    insertAt(0, data);
}

void List::insertAt(size_t index, std::string data)
{
    if (index > this->size)
    {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }

    auto new_node = generate(data);

    if (index == 0)
    {
        new_node->next = this->head.release();
        this->head = std::move(new_node);
    }
    else
    {
        auto current = this->head.get();
        for (size_t i = 0; i < index - 1; ++i)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node.release();
    }
    size++;
}

void List::print() const
{
    auto current = this->head.get();
    std::cout << "List: ";
    while (current != nullptr)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

void List::delAt(size_t index)
{
    if (index >= size)
    {
        std::cerr << "Index out of bounds" << std::endl;
        return;
    }

    if (index == 0)
    {
        this->head.reset(this->head.release()->next);
    }
    else
    {
        auto current = this->head.get();
        for (size_t i = 0; i < index - 1; ++i)
        {
            current = current->next;
        }
        current->next = std::move(current->next->next);
    }
    size--;
}

void List::clear()
{
    this->head = nullptr;
}

int main()
{
    List myList;
    myList.insertAt(0, "First Node");
    myList.append("Node 1");
    myList.append("Node 2");
    myList.append("Node 3");
    myList.insertAt(1, "Node 1.5");
    myList.print();
    myList.delAt(2);
    myList.insertAt(0, "Node 0");
    myList.print();
    std::cout << "Size of the list: " << myList.getSize() << std::endl;
    myList.clear();
    myList.print();
    myList.~List();
    return 0;
}
