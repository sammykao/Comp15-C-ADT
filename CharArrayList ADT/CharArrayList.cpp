/*
 *  CharArrayList.cpp
 *  SAMMY KAO
 *  01/26/2023
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  PURPOSE: IMPLEMENTATION OF CHARARRAYLIST CLASS 
 *  AND ITS FUNCTIONS
 *
 */

#include "CharArrayList.h"
#include <sstream>
using namespace std;
#include <stdexcept>
#include <string>


/*
 * name:      CharArrayList default constructor
 * purpose:   initialize an empty CharArrayList
 * arguments: none
 * returns:   none
 * effects:   numItems to 0 
 (also updates capacity and data array)
 */
CharArrayList::CharArrayList() {
    numItems = 0;
    capacity = 0;
    list = nullptr;
}
/*
 * name:      CharArrayList constructor
 * purpose:   initialize a single char CharArrayList
 * arguments: char c
 * returns:   none
 * effects:   numItems to 1 
 (also updates capacity to 1 and data array)
 */
CharArrayList::CharArrayList(char c) {
    numItems = 1;
    capacity = 1;
    list = new char[1];
    list[0] = c;
}

/*
 * name:      CharArrayList constructor
 * purpose:   initialize a CharArrayList that is a 
 simple copy of another array
 * arguments: a different char array, its size
 * returns:   none
 * effects:   numItems to passed in value (also 
 updates capacity to be the same and data array)
 */
CharArrayList::CharArrayList(char arr[], int size) {
    capacity = size;
    numItems = size;
    list = new char[size];
    for (int i=0; i < size; i++) {
        list[i] = arr[i];
    }
}
/*
 * name:      CharArrayList constructor
 * purpose:   initialize a deep copied CharArrayList 
 * arguments: other CharArrayList
 * returns:   none
 * effects:   all values same, but deep copied
 */
CharArrayList::CharArrayList(const CharArrayList &other) {
    capacity = other.capacity;
    numItems = other.numItems;
    list = new char[other.capacity];
    for (int i=0; i<other.numItems; i++) {
        this->list[i] = other.list[i];
    }
}

/*
 * name:      CharArrayList destructor
 * purpose:   clean up any heap space
 * arguments: none
 * returns:   none
 * effects:   deletes any heap memory
 */
CharArrayList::~CharArrayList() {
    delete [] list;
}

/*
 * name:      CharArrayList overload operator
 * purpose:   make a copy of another CharArrayList
 * arguments: array list we want to copy
 * returns:   the copied array list
 * effects:   *only copies under the assumption there is
 * a char array already institued with enough capacity.
 */
CharArrayList &CharArrayList::operator=(const CharArrayList &other) {
    if (this == &other) {
        return *this;
    }
    capacity = other.capacity;
    numItems = other.numItems;
    if (list != nullptr) {
        delete [] list;
        list = nullptr;
    }
    list = new char[capacity];
    for (int i=0; i<numItems; i++) {
        list[i] = other.list[i];
    }
    return *this;
}

/*
 * name:      isEmpty()
 * purpose:   tells whether CharArrayList is empty
 * arguments: none
 * returns:   boolean value
 * effects:   none
 */

bool CharArrayList::isEmpty() const{
    return (numItems == 0);
}

/*
 * name:      clear()
 * purpose:   clear the CharArrayList 
 * arguments: none
 * returns:   none
 * effects:   clears the CHarArrayList
 */

void CharArrayList::clear() {
    if (list != nullptr) {
        delete [] list;
        list = nullptr;
    }
    capacity = 0;
    numItems = 0;
}

/*
 * name:      size()
 * purpose:   getter of numItems in chararraylist 
 * arguments: none
 * returns:   size of our CharArrayList
 * effects:   none
 */

int CharArrayList::size() const {
    return numItems;
}

/*
 * name:      first()
 * purpose:   getter of first item in chararraylist 
 * arguments: none
 * returns:   first item
 * effects:   runtime error if empty array
 */

char CharArrayList::first() const {
    if (isEmpty()) {
        throw std::runtime_error("cannot get first of empty ArrayList");
    }
    return list[0];
}

/*
 * name:      last()
 * purpose:   getter of last item in chararraylist 
 * arguments: none
 * returns:   last item in CharArrayList
 * effects:   runtime error if empty array
 */

char CharArrayList::last() const {
    if (isEmpty()) {
        throw std::runtime_error("cannot get last of empty ArrayList");
    }
    return list[numItems - 1];
}

/*
 * name:      elementAt()
 * purpose:   getter of item at user inputted index in
chararraylist 
 * arguments: none
 * returns:   item at user inputted index
 * effects:   range error if empty array
 */

char CharArrayList::elementAt(int index) const {
    assert_in_range(index);
    return list[index];
}

/*
 * name:      toString()
 * purpose:   turns the array into a string, and returns it
 * arguments: none
 * returns:   a string representation of the array
 * effects:   none
 */

std::string CharArrayList::toString() const {
    std::stringstream ss;
    ss << "[CharArrayList of size " << numItems << " <<";
    for (int i=0; i<numItems; i++) {
        ss << list[i];
    }
    ss << ">>]";
    return ss.str();
}

/*
 * name:      toReverseString()
 * purpose:   turns the array into a reversed string, 
 and returns it
 * arguments: none
 * returns:   a reversed string representation of the array
 * effects:   none
 */

std::string CharArrayList::toReverseString() const {
    std::stringstream ss;
    ss << "[CharArrayList of size " << numItems << " <<";
    for (int i=numItems; i>0; i-=1) {
        ss << list[i - 1];
    }
    ss << ">>]";
    return ss.str();
}

/*
 * name:      toReverseString()
 * purpose:   turns the array into a reversed string, 
 and returns it
 * arguments: none
 * returns:   a reversed string representation of the array
 * effects:   none
 */
void CharArrayList::expand() {
    capacity = (capacity * 2) + 2;
    char *new_list = new char[capacity];
    for (int i=0; i<numItems; i++) {
        new_list[i] = list[i];
    }
    delete [] list;
    list = new_list;
}

/*
 * name:      toReverseString()
 * purpose:   turns the array into a reversed string, 
 and returns it
 * arguments: none
 * returns:   a reversed string representation of the array
 * effects:   none
 */
void CharArrayList::pushAtBack(char c) {
    if (numItems == capacity) {
        expand();
    }
    list[numItems] = c;
    numItems++;
}

/*
 * name:      toReverseString()
 * purpose:   turns the array into a reversed string, 
 and returns it
 * arguments: none
 * returns:   a reversed string representation of the array
 * effects:   none
 */
void CharArrayList::pushAtFront(char c) {
    if (numItems == capacity) {
        expand();
    }
    for (int i=numItems; i>0; i-=1) {
        list[i] = list[i - 1];
    }
    list[0] = c;
    numItems++;
}

/*
 * name:      toReverseString()
 * purpose:   turns the array into a reversed string, 
 and returns it
 * arguments: none
 * returns:   a reversed string representation of the array
 * effects:   none
 */
void CharArrayList::insertAt(char c, int index) {
    std::stringstream ss;
    ss << "index (" << index 
    << ") not in range [0.." 
    << numItems << "]";
    if (index < 0 or index > numItems) {
        throw std::range_error(ss.str());
    }
    if (index == numItems) {
        pushAtBack(c);
        return;
    }
    if (numItems == capacity) {
        expand();
    }
    for (int i=numItems; i>index; i-=1) {
        list[i] = list[i - 1];
    }
    list[index] = c;
    numItems++;
}

/*
 * name:      insertInOrder(char c)
 * purpose:   inserts a char into a sorted CharArrayList
 * arguments: char that is to be inserted
 * returns:   none
 * effects:   assumes list is sorted, then inserts
 */
void CharArrayList::insertInOrder(char c) {
    if (numItems == capacity) {
        expand();
    }
    int pos = 0;
    for (int i=0; i<numItems; i++) {
        if (list[i] > c) {
            break;
        }
        pos++;
    }
    for (int i=numItems; i>pos; i-=1) {
        list[i] = list[i - 1];
    }
    list[pos] = c;
    numItems++;
}

/*
 * name:      popFromFront()
 * purpose:   removes the first element of a CharArrayList
 * arguments: none
 * returns:   none
 * effects:   shifts every item one down and decreases numItems
 */
void CharArrayList::popFromFront() {
    if (isEmpty()) {
        throw std::runtime_error("cannot pop from empty ArrayList");
    }
    for (int i=0; i<numItems-1; i++) {
        list[i] = list[i+1];
    }
    numItems--;
}
/*
 * name:      popFromBack()
 * purpose:   removes the last element of a CharArrayList
 * arguments: none
 * returns:   none
 * effects:   decreases numItems
 */
void CharArrayList::popFromBack() {
    if (isEmpty()) {
        throw std::runtime_error("cannot pop from empty ArrayList");
    }
    numItems--;
}
/*
 * name:      removeAt(int index)
 * purpose:   removes element in CharArrayList at indicated index
 * arguments: index of CharArrayList it wants to remove
 * returns:   none
 * effects:   decreases numItems and shifts everything one down from
 * indicated index to numItems
 */
void CharArrayList::removeAt(int index) {
    assert_in_range(index);
    for (int i=index; i<numItems-1; i++) {
        list[i] = list[i+1];
    }
    numItems--;
}
/*
 * name:      replaceAt(int index)
 * purpose:   replace element at indicated index with indicated char
 * arguments: index of element and replacement
 * returns:   none
 * effects:   none
 */
void CharArrayList::replaceAt(char c, int index) {
    assert_in_range(index);
    if (index >= numItems || index < 0) {
        return;
    }
    list[index] = c;
}
/*
 * name:      concatenate
 * purpose:   adds two chararraylists together
 * arguments: pointer to another CharArrayList
 * returns:   none
 * effects:   if an first is an empty array list, basically 
 * making a copy of the second array list.
 */
void CharArrayList::concatenate(CharArrayList *other) {
    for (int i=0; i<other->numItems; i++) {
        if (numItems == capacity) {
            expand();
        }
        list[numItems] = other->list[i];
        numItems++;
    }
}
/*
 * name:      shrink
 * purpose:   reduces capacity of CharArrayList to minimum heap size
 * arguments: none
 * returns:   none
 * effects:   makes capacity equal to numItems
 */
void CharArrayList::shrink() {
    if (numItems == capacity) {
        return;
    }
    char *new_list = new char[numItems];
    for (int i=0; i<numItems; i++) {
        new_list[i] = list[i];
    }
    delete [] list; 
    list = new_list;
    
}

/*
 * name:      assert_in_range(int index)
 * purpose:   simple exception for range error
 * arguments: index of position
 * returns:   none
 * effects:   prints out message if not in range
 */
void CharArrayList::assert_in_range(int index) const {
    std::stringstream ss;
    ss << "index (" << index 
    << ") not in range [0.." 
    << numItems << ")";
    if (index < 0 or index >= numItems
        or isEmpty()) {
        throw std::range_error(ss.str());
    }
}
