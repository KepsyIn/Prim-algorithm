#include <iostream>

//nœud de la liste
template <typename T>
class Node {
    T data;
    int priority;
    Node* next;
public:
    Node(T value) :  data(value), next(nullptr), priority(0){};
    Node(T value , int priority ) : data(value), next(nullptr), priority(priority) {};
    
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
    size_t size;
    bool flag_is_priority;
public:
    List() : head(nullptr), size(0) , flag_is_priority(false) {}
    
    List(const List& l) {
        
        if( !(this->isEmpty()) ){
            this->clear();
        }

        Node<T>* temp = l.head;

        while( temp != nullptr ){
            this->add(temp->getData(),temp->getPriority());
        };
    };

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

        size++;
    }

    void add(T value, int priority ) {
        Node<T>* newNode = new Node<T>(value,priority);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->getNext() != nullptr) {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
        size++;
    }

    size_t length(){
        return this->size;
    }

    bool isEmpty(){
        return ( this->head == nullptr );
    }

    T operator[] (unsigned int index) const{
        if( index >= size ) return;
        Node<T>* temp = head;
        while( index != 0 ){
            if( temp == nullptr ) return;
            temp = temp->getNext();
            index--;
        }
        return temp->getData();
    }

    void clear(){
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* nextNode = temp->getNext();
            delete temp;
            temp = nextNode;
        };
        head = nullptr;
        size = 0;
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