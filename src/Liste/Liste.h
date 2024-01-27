#include <iostream>

//nœud de la liste
template <typename T,int P>
class Node {
    T data;
    int priority;
    Node* next;
public:
    Node(T value) :  data(value), next(nullptr), priority(P) {};
    
    T getData() const{
        return this->data;
    }

    int getPriority() const{
        return this->priority;
    }

    void setNext(Node* n){
        this->next = n;
    }

    Node* getNext(){
        return this->next;
    }

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
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    }

    void printList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        std::cout << std::endl;
    }

    ~List() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* nextNode = temp->getNext();
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
    }
};