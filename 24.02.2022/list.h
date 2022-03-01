#include <iostream>

template <typename T>
struct node {
    T value;
    node* next;
    node() = default;
};

template <class T>
class list{
protected:
    node<T>* head;
    int size;
public:
    ~list(){
        node<T>* temp = head;
        for (int i = 0; i < size - 1; ++i)
            delete temp->next;
        delete head;
    }
    list() : size(0){ head = nullptr; }
    void push(T data){
        node<T>* newHead = new(node<T>);
        newHead->next = nullptr;
        newHead->value = data;
        node<T>* temp = head;
        if (head == nullptr){
            head = newHead;
            ++size;
            return;
        }
        for (int i = 0; i < size - 1; ++i)
            temp = temp->next;
        temp->next = newHead;
        ++size;
    };
    void remove(T data){
        if (head->value == data){
            head = head->next;
            --size;
            return;
        }
        node<T>* temp = head;
        for (int i = 0; i < size; ++i){
            if (temp->next->value == data){
                delete temp->next;
                --size;
                return;
            }
            temp = temp->next;
        }
    }
    void print(std::ostream& out){
        node<T>* temp = head;
        for (int i = 0; i < size; ++i){
            out << temp->value << std::endl;
            temp = temp->next;
        }
    }
    bool isEmpty(){ return head == nullptr; }
    T topValue(){ return head->value; }
};