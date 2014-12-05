#ifndef OLISTITERATOR_H
#define OLISTITERATOR_H

#include "OList.h"

template <class T>
class OListIterator {

private:
    Node<T> * position;
    //no "last" position since we are not defining any -- operators
    
public:
    OListIterator(Node<T> * pos): position(pos) { } //conversion constructor

   	T & operator* () const { return position->value; }; //dereferencing won't work with iterators pointing at null, like end iterators
    bool operator== (const OListIterator<T> & other) const { return position == other.position; };
    bool operator!= (const OListIterator<T> & other) const { return position != other.position; };
    OListIterator<T> & operator+= (int move);
    OListIterator<T> operator+ (int move) const;
    OListIterator<T> & operator++ () { position = position->next; return *this; };
    OListIterator<T> operator++ (int);

    Node<T> * getPosition() const { return position; } ; //define this get function to help with testing 'end' and other iterators pointing at NULL
};

template <class T>
OListIterator<T> & OListIterator<T>::operator+= (int move) {

    while(position && move-- > 0) { //don't do anything to the iterator if position is null or move < 0, since the forward move is invalid
        if(position)
            position = position->next;
        else //just stop when you get past the end of the list, don't move farther than that
            return *this;
    }
    return *this;
}

template <class T>
OListIterator<T> OListIterator<T>::operator+ (int move) const {
    
    Node<T> * curr = position;
    while(curr && move-- > 0) { //don't return any shifted iterator if position is null or move < 0, since the forward move is invalid. Return original
        if(curr)
            curr = curr->next;
        else //just stop when you get past the end of the list, don't move farther than that
            break;
    }
    return OListIterator<T>(curr);
}

template <class T>
OListIterator<T> OListIterator<T>::operator++ (int) {

    Node<T> * temp = position; //create a new Node at the current position
    position = position->next; //update the current position by one
    return OListIterator<T>(temp); //return a copy of the old iterator, but the old one is updated
}

#endif
