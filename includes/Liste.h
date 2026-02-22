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
    
    T& getData(){
        return this->data;
    }

    int getPriority() const{
        return this->priority;
    }
    
    void setPriority(int p){
        this->priority = p;
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
    
    List(const List& l) : head(nullptr) , size(0) , flag_is_priority(false) {
        
        this->clear();

        Node<T>* temp = l.getHead();

        while( temp != nullptr ){
            this->add(temp->getData(),temp->getPriority());
            temp = temp->getNext();
        };

    };

    void add(T value) {
        if( this->flag_is_priority ) std::runtime_error("missing a priority argument");

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

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("empty priority list");
        }

        Node<T>* temp = head;
        T poppedValue = temp->getData();

        head = head->getNext();
        delete temp;
        size--;

        return poppedValue;
    }

    Node<T>* getHead() const{
        return this->head;
    }

    void add(T value, int priority ) {
        
        if( isEmpty() ){
            this->flag_is_priority = true;
        }

        if( !(isEmpty()) && !this->flag_is_priority ) std::runtime_error("this isn't a priority list");

        Node<T>* newNode = new Node<T>(value, priority);

        if (head == nullptr || priority < head->getPriority()) {
            newNode->setNext(head);
            head = newNode;
        } else {

            Node<T>* temp = head;

            while (temp->getNext() != nullptr && temp->getNext()->getPriority() <= priority) {
                temp = temp->getNext();
            }

            newNode->setNext(temp->getNext());
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

    T& operator[] (unsigned int index) const{
        if( index >= size ) throw std::runtime_error("index out of bounds");

        Node<T>* temp = head;

        while( index != 0 ){
            if( temp == nullptr ) std::runtime_error("nothing to see there");
            temp = temp->getNext();
            index--;
        }

        return temp->getData();
    }

    bool isInList( const T& value ){
        Node<T>* temp = head;
        while (temp != nullptr) {
            if( temp->getData() == value ){
                return true;
            }
            temp = temp->getNext();
        }

        return false;
    }
    void clear(){
        Node<T>* temp = head;

        while (temp != nullptr) {
            Node<T>* nextNode = temp->getNext();
            delete temp;
            temp = nextNode;
        }

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

    void remove(T value) {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current != nullptr && current->getData() != value) {
            previous = current;
            current = current->getNext();
        }

        if (current == nullptr) {
            throw std::runtime_error("Element not found in the list" );
        }

        if (previous == nullptr) {
            head = current->getNext();
        } else {
            previous->setNext(current->getNext());
        }

        delete current;
        size--;
    }

    T getElement(int value){
        Node<T>* temp = head;

        while( temp != nullptr || temp->getData() != value){
            temp = temp->getNext();
        }
        if(temp==nullptr){
            throw std::runtime_error("index out of bounds");
        }

        return temp->getData();
    }

    void setPriorityElement(int value, int priority){
        remove(value);
        add(value, priority);
    }

    int getPriorityElement(T value){
        Node<T>* temp = head;

        while( temp != nullptr ){

            

            if( temp->getData() == value ){
                
                break;
            }
            
            temp = temp->getNext();
        }

        if(temp==nullptr){
            throw std::runtime_error("index out of bounds");
        }

        return temp->getPriority();
    }

    class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator(Node<T>* node) : current(node) {}

        T operator*() const {
            return current->getData();
        }

        Iterator& operator++() {
            if (current != nullptr) {
                current = current->getNext();
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
    
};

