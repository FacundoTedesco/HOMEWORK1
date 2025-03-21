#include "ejercicio3.h"  

Node::Node(int val) : value(val), next(nullptr) {}

void push_front(LinkedList& list, int value) {
    auto new_node = std::make_unique<Node>(value);
    new_node->next = std::move(list.head);
    list.head = std::move(new_node);
}

void push_back(LinkedList& list, int value) {
    auto new_node = std::make_unique<Node>(value);
    if (!list.head) {
        list.head = std::move(new_node);
        return;
    }
    Node* temp = list.head.get();
    while (temp->next) {
        temp = temp->next.get();
    }
    temp->next = std::move(new_node);
}

void insert(LinkedList& list, int value, int position) {
    if (position <= 0 || !list.head) {
        push_front(list, value);
        return;
    }
    Node* temp = list.head.get();
    int index = 0;
    while (temp->next && index < position - 1) {
        temp = temp->next.get();
        index++;
    }
    auto new_node = std::make_unique<Node>(value);
    new_node->next = std::move(temp->next);
    temp->next = std::move(new_node);
}

void erase(LinkedList& list, int position) {
    if (!list.head) return;
    if (position <= 0 || !list.head->next) {
        list.head = std::move(list.head->next);
        return;
    }
    Node* temp = list.head.get();
    int index = 0;
    while (temp->next && temp->next->next && index < position - 1) {
        temp = temp->next.get();
        index++;
    }
    temp->next = std::move(temp->next->next);
}

void print_list(const LinkedList& list) {
    Node* temp = list.head.get();
    while (temp) {
        std::cout << temp->value;
        if (temp->next) std::cout << " -> ";
        temp = temp->next.get();
    }
    std::cout << std::endl;
}

int main() {
    LinkedList list;
    push_back(list, 5);
    push_back(list, 7);
    push_front(list, 3);
    insert(list, 4, 2);
    insert(list, 8, 5);
    print_list(list); // 3 -> 5 -> 4 -> 7 -> 8
    
    erase(list, 2);
    print_list(list); // Expected: 3 -> 5 -> 7 -> 8
    
    erase(list, 5);
    print_list(list); // Expected: 3 -> 5 -> 7
    
    return 0;
}
