#pragma once

#include <iostream>

//nœud de la liste
template <typename T>
class Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

// classe Liste
template <typename T>
class List {
private:
    Node<T>* head;
public:
    List() : head(nullptr) {}

    void add(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~List() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
    }
};