#include "list.h"

template<class T>
class sortedList : public list<T>{
public:
    void push(T data){
        node<T>* newHead = new(node<T>);
        newHead->next = nullptr;
        newHead->value = data;
        if (list<T>::head == nullptr){
            list<T>::head = newHead;
            ++list<T>::size;
            return;
        }
        node<T>* temp1 = list<T>::head;
        node<T>* temp2 = list<T>::head;
        for (int i = 0; i < list<T>::size; ++i){
            if (temp1->value < data){
                if (temp1->next == nullptr){
                    ++list<T>::size;
                    temp1->next = newHead;
                    return;
                }
                temp2 = temp1;
                temp1 = temp1->next;
            }
            else{
                if (temp1 == list<T>::head){
                    newHead->next = list<T>::head;
                    list<T>::head = newHead;
                    ++list<T>::size;
                    return;
                }
                temp2->next = newHead;
                newHead->next = temp1;
                ++list<T>::size;
                return;
            }
        }
    }
};