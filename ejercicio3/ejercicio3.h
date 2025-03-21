#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <memory>

struct Node {
    int value;
    std::unique_ptr<Node> next;
    
    Node(int val);
};

struct LinkedList {
    std::unique_ptr<Node> head;
};

void push_front(LinkedList& list, int value);
void push_back(LinkedList& list, int value);
void insert(LinkedList& list, int value, int position);
void erase(LinkedList& list, int position);
void print_list(const LinkedList& list);

#endif // LINKED_LIST_H