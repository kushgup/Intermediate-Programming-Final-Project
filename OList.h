#ifndef OLIST_H
#define OLIST_H

#include <iostream>

template <class T> class OList;
template <class T> class OListIterator;

template <class T>
class Node {

    friend class OList<T>;
    friend class OListIterator<T>; //friend the iterator so it doesn't have to call getValue and getNext all the time

private:
    T value;
    Node<T> * next;

public:
    Node(): next(NULL) { }
    Node(T val): value(val), next(NULL) { }
    Node(T val, Node<T> *other): value(val), next(other) { }

    T getValue() const { return value; }
    Node<T> * getNext() const { return next; }
};

template <class T>
class OList {

private:
    Node<T> * head;

public:
    OList(): head(NULL) { } //default constructor
    OList(const OList<T> & other); //copy constructor
    ~OList(); //destructor

    void clear();
    int size() const;
    T * get(int val) const;
    int count(T val) const;
    void insert(T val);
    void insertPointer(T val)
    void push_back(T val);
    void remove(T val);
    void uniquify();
    bool isSorted();

    OListIterator<T> begin() const { return OListIterator<T>(head); };
    OListIterator<T> end() const { return OListIterator<T>(NULL); };
};

template <class T>
OList<T>::OList(const OList<T> & other): head(NULL) {

    //deep copy the list by dynamically allocating the same number of nodes
    Node<T> * curr = other.head;
    while(curr) {
        insert(curr->value);
        curr = curr->next;
    }
}

template <class T>
OList<T>::~OList() {
    clear();
}

template <class T>
void OList<T>::clear() {

    Node<T> * curr = head;
    while(curr) {
        head = head->next;
        delete curr;
        curr = head;
    }
    head = NULL;
}

template <class T>
int OList<T>::size() const {

    int size = 0;
    Node<T> * curr = head;
    while(curr) {
        size++;
        curr = curr->next;
    }
    return size;
}

template <class T>
T * OList<T>::get(int val) const {

    Node<T> * curr = head;
    if(!head || val < 0)
        return NULL;
    while(val--) {
        if(curr)
            curr = curr->next;
        else
            return NULL;
    }
    return &(curr->value);
}

template <class T>
int OList<T>::count(T val) const {

    Node<T> * curr = head;
    if(!head) //check if there is anything in the list
        return 0;

    int count = 0;
    while(curr) {
        if(curr->value == val)
            count++;
        curr = curr->next;
    }
    return count;
}

template <class T>
void OList<T>::insert(T val) {

    if(!head) {
        head = new Node<T>(val, NULL);
        return;
    }
    //insert where it should be using the < or > operator
    //case 1, insert before head
    if(head->value >= val) {
        head = new Node<T>(val, head);
        return;
    }

    //case 2, middle of the list
    Node<T> *prev = NULL, *curr = head;
    while(curr && curr->value < val) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = new Node<T>(val, curr);
}

template <class T>
void OList<T>::insertPointer(T val) {

    if(!head) {
        head = new Node<T>(val, NULL);
        return;
    }
    //insert where it should be using the < or > operator
    //case 1, insert before head
    if(*(head->value) >= *val) {
        head = new Node<T>(val, head);
        return;
    }

    //case 2, middle of the list
    Node<T> *prev = NULL, *curr = head;
    while(curr && *(curr->value) < *val) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = new Node<T>(val, curr);
}

template <class T>
void OList<T>::push_back(T val) {

    //insert at the end
    Node<T> *curr = head;
    while(curr->next)
        curr = curr->next;
    curr->next = new Node<T>(val, NULL);
}

template <class T>
void OList<T>::remove(T val) {

    Node<T> *prev = NULL, *curr = head;
    while(curr && curr->value != val) {
        prev = curr;
        curr = curr->next;
    }
    if(!curr) //value to remove was not found in the list
        return;
    if(!prev)
        head = curr->next;
    else
        prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

template <class T>
void OList<T>::uniquify() {

    if(!head) //list is empty
        return;

    //assumes list is sorted in ascending order
    Node<T> * temp = head;
    Node<T> * curr = head->next;
    while(curr) {
        if(curr->value == temp->value)
            remove(curr->value);
        temp = curr;
        curr = curr->next;
    }
}

template <class T>
bool OList<T>::isSorted() {

    if(!head) //for empty list
        return true;

    Node<T> * temp = head;
    Node<T> * curr = head->next;
    while(curr) {
        if(curr->value < temp->value)
            return false;
        temp = curr;
        curr = curr->next;
    }
    return true;
}

#endif
