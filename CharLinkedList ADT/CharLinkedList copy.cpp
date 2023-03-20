/*
 *  CharLinkedList.cpp
 *  SAMMY KAO
 *  2/01/2023
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  This file is the implemention of the CHARLINKEDLIST ADT class 
 *  and its methods
 *
 */

#include "CharLinkedList.h"
#include <string>
#include <sstream>
#include <stdexcept>

/*
 * name:      CharLinkedList default constructor
 * purpose:   initialize an empty CharLinkedList
 * arguments: none
 * returns:   none
 * effects:   numItems to 0 
*/

CharLinkedList::CharLinkedList() {
    numItems = 0;
    front = nullptr;
    back = nullptr;
}

/*
 * name:      CharLinkedList default constructor
 * purpose:   initialize an single CharLinkedList
 * arguments: one char
 * returns:   none
 * effects:   numItems to 1
 */

CharLinkedList::CharLinkedList(char c) {
    numItems = 1;
    front = newNode(c, nullptr, nullptr);
    back = front;
}


/*
 * name:      CharLinkedList constructor
 * purpose:   initialize a CharArrayList that is a 
 simple copy of another array
 * arguments: a different char array, its size
 * returns:   none
 * effects:   numItems to passed in value
 */

CharLinkedList::CharLinkedList(char arr[], int size) {
    numItems = size;
    back = newNode(arr[size - 1], nullptr, nullptr);
    front = back;
    for (int i=size - 2; i >= 0; i--) {
        front = newNode(arr[i], front, nullptr);
        front->next->previous = front;
    }

}

/*
 * name:      CharLinkedList constructor
 * purpose:   initialize a deep copied CharLinkedList 
 * arguments: other CharLinkedList
 * returns:   none
 * effects:   all values same, but deep copied
 */

CharLinkedList::CharLinkedList(const CharLinkedList &other) {
    numItems = other.numItems;
    front = newNode(other.back->info, nullptr, nullptr);
    back = front;
    Node *curr = other.back->previous;
    while (curr != nullptr) {
        front = newNode(curr->info, front, nullptr);
        front->next->previous = front;
        curr = curr->previous;
    }
}

/*
 * name:      CharLinkedList destructor
 * purpose:   clean up any heap space
 * arguments: none
 * returns:   none
 * effects:   deletes any heap memory by calling
 * a recursive function
 */
CharLinkedList::~CharLinkedList() {
    deleteNodes(front);
}


/*
 * name:      CharLinkedList overload operator
 * purpose:   make a copy of another CharLinkedList
 * arguments: CharLinkedList we want to copy
 * returns:   the copied CharLinkedList
 * effects: none
 */
CharLinkedList &CharLinkedList::operator=(const CharLinkedList &other) {
    if (this == &other) {
        return *this;
    }
    clear();
    if (other.back == nullptr) {
        return *this;
    }
    numItems = other.numItems;
    back = newNode(other.back->info, nullptr, nullptr);
    front = back;
    Node *curr = other.front;
    while (curr != nullptr) {
        front = newNode(curr->info, front, nullptr);
        front->next->previous = front;
        curr = curr->previous;
    }
    return *this;
}

/*
 * name:      isEmpty()
 * purpose:   tells whether CharLinkedList is empty
 * arguments: none
 * returns:   boolean value
 * effects:   none
 */
bool CharLinkedList::isEmpty() const {
    return (numItems == 0);
}

/*
 * name:      clear()
 * purpose:   tells whether CharLinkedList is empty
 * arguments: none
 * returns:   boolean value
 * effects:   none
 */
void CharLinkedList::clear() {
    deleteNodes(front);
    front = nullptr;
    back = nullptr;
    numItems = 0;
}

/*
 * name:      size()
 * purpose:   tells size of CharLinkedList
 * arguments: none
 * returns:   size of CharLinkedList
 * effects:   none
 */
int CharLinkedList::size() const {
    return numItems;
}

/*
 * name:      first()
 * purpose:   tells first char of CharLinkedList
 * arguments: none
 * returns:   first char of CharLinkedList
 * effects:   none
 */
char CharLinkedList::first() const {
    if (isEmpty()) {
        throw std::runtime_error("cannot get first of empty LinkedList");
    }
    return front->info;
}

/*
 * name:      last()
 * purpose:   tells last char of CharLinkedList
 * arguments: none
 * returns:   last char of CharLinkedList
 * effects:   none
 */
char CharLinkedList::last() const {
    if (isEmpty()) {
        throw std::runtime_error("cannot get last of empty LinkedList");
    }
    return back->info;
}

/*
 * name:      elementAt()
 * purpose:   tells char of CharLinkedList at
 * requested positions
 * arguments: index of position
 * returns:   indexed position char of CharLinkedList
 * effects:   none
 */
char CharLinkedList::elementAt(int index) const {
    assert_in_range(index);
    int count = 0;
    Node *curr = front;
    while (count < index) {
        curr = curr->next;
        count++;
    }
    return curr->info;
}


/*
 * name:      toString()
 * purpose:   turns the LinkedList into a string, and returns it
 * arguments: none
 * returns:   a string representation of the LinkedList
 * effects:   none
 */

std::string CharLinkedList::toString() const {
    std::stringstream ss;
    ss << "[CharLinkedList of size " << this->numItems << " <<";

    Node *curr = this->front;
    while (curr != nullptr) {
        ss << curr->info;
        curr = curr->next;
    }
    ss << ">>]";
    return ss.str();
}


/*
 * name:      toReverseString()
 * purpose:   turns the LinkedList into a string, 
 * reverses it, and returns it
 * arguments: none
 * returns:   a reversed string representation of the LinkedList
 * effects:   none
 */
std::string CharLinkedList::toReverseString() const {
    std::stringstream ss;
    ss << "[CharLinkedList of size " << this->numItems << " <<";

    Node *curr = this->back;
    while (curr != nullptr) {
        ss << curr->info;
        curr = curr->previous;
    }
    ss << ">>]";
    return ss.str();
}

/*
 * name:      pushAtBack()
 * purpose:   add element to CharLinkedList at back
 * arguments: char to be inserted
 * returns:   none
 * effects:   updates numItems
 */
void CharLinkedList::pushAtBack(char c) {
    back = newNode(c, nullptr, back);
    if (isEmpty()) {
        front = back;
        numItems++;
        return;
    }
    back->previous->next = back;
    numItems++;
}


/*
 * name:      pushAtFront()
 * purpose:   add element to CharLinkedList at front
 * arguments: char to be inserted
 * returns:   none
 * effects:   updates numItems
 */
void CharLinkedList::pushAtFront(char c) {
    front = newNode(c, front, nullptr);
    if (isEmpty()) {
        back = front;
        numItems++;
        return;
    }
    front->next->previous = front;
    numItems++;
}


/*
 * name:      insertAt()
 * purpose:   add element to CharLinkedList at 
 * inputted index
 * arguments: char to be inserted, index position
 * returns:   none
 * effects:   updates numItems
 */
void CharLinkedList::insertAt(char c, int index) {
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
    int count = 0;
    Node *curr = front;
    while (count < index - 1) {
        curr = curr->next;
        count++;
    }
    Node *insertnode = newNode(c, curr->next, curr);
    curr->next = insertnode;
    insertnode->next->previous = insertnode;
    numItems++;
}

/*
 * name:      insertInOrder()
 * purpose:   add element to CharLinkedList in order
 * arguments: char to be inserted
 * returns:   none
 * effects:   updates numItems, assumes list is in order
 */
void CharLinkedList::insertInOrder(char c) {
    if (isEmpty()) {
        pushAtBack(c);
        return;
    }
    if (c <= front->info) {
        pushAtFront(c);
        return;
    }
    Node *curr = front;
    while (curr != nullptr) {
        if (c <= curr->info) {
            Node *insertnode = newNode(c, curr, curr->previous);
            curr->previous = insertnode;
            insertnode->previous->next = insertnode;
            numItems++;
            break;
        }
        curr = curr->next;
    }
    if (curr == nullptr) {
        pushAtBack(c);
        return;
    }
}


/*
 * name:      popFromFront()
 * purpose:   removes char from CharLinkedList at front
 * arguments: none
 * returns:   none
 * effects:   updates numItems
 */
void CharLinkedList::popFromFront() {
    if (isEmpty()) {
        throw std::runtime_error("cannot pop from empty LinkedList");
    }
    Node *temp_node = front->next;
    temp_node->previous = nullptr;
    front->next = nullptr;
    delete front;
    front = temp_node;
    numItems--;
}

/*
 * name:      popFromBack()
 * purpose:   removes char from CharLinkedList at back
 * arguments: none
 * returns:   none
 * effects:   updates numItems
 */
void CharLinkedList::popFromBack() {
    if (isEmpty()) {
        throw std::runtime_error("cannot pop from empty LinkedList");
    }
    Node *temp_node = back->previous;
    temp_node->next = nullptr;
    back->previous = nullptr;
    delete back;
    back = temp_node;
    numItems--;
}

/*
 * name:      removeAt()
 * purpose:   removes char from CharLinkedList at inputted index
 * arguments: index
 * returns:   none
 * effects:   updates numItems
 */
void CharLinkedList::removeAt(int index) {
    assert_in_range(index);
    int count = 0;
    Node *curr = front;
    while (count < (index)) {
        curr = curr->next;
        count++;
    }
    if (index == 0) {
        popFromFront();
        return;
    }
    if (index == (numItems - 1)) {
        popFromBack();
        return;
    }
    curr->previous->next = curr->next;
    curr->next->previous = curr->previous;
    curr->next = nullptr;
    curr->previous = nullptr;
    delete curr;
    numItems--;
}

/*
 * name:      removeAt()
 * purpose:   replaces char from CharLinkedList at inputted index
 * arguments: char to replace and index
 * returns:   none
 * effects:   updates numItems
 */
void CharLinkedList::replaceAt(char c, int index) {
    assert_in_range(index);
    int count = 0;
    Node *curr = front;
    while (count < (index)) {
        curr = curr->next;
        count++;
    }
    Node *insert_node = newNode(c, curr->next, curr->previous);
    if (index == (numItems - 1)) {
        curr->previous->next = insert_node;
        back = insert_node;
    } else if (index == 0) {
        curr->next->previous = insert_node;
        front = insert_node;
    } else {
        curr->previous->next = insert_node;
        curr->next->previous = insert_node;
    }
    curr->next = nullptr;
    curr->previous = nullptr;
    delete curr;
}


/*
 * name:      concatenate()
 * purpose:   adds two linked lists together
 * arguments: pointer to other linked list
 * returns:   none
 * effects:   makes a double copy if 
 * list isconcatenated with itself
 */
void CharLinkedList::concatenate(CharLinkedList *other) {
    Node *curr = other->front;
    while(curr != nullptr) {
        pushAtBack(curr->info);
        curr = curr->next;
    }
}

/*
 * name:      newNode()
 * purpose:   create a new node struct for
 * other functions to use
 * arguments: char for info, two node pointers
 * for next and previous pointers
 * returns:   new noded created
 * effects:   allocates space on heap for the node
 */

CharLinkedList::Node *CharLinkedList::newNode(char input, 
Node *next, Node *previous) {
    Node *newNode = new Node;
    newNode->info = input;
    newNode->next = next;
    newNode->previous = previous;
    return newNode;
}

/*deleteNodes()
* Purpose: to delete the linked list recursively
* Parameters: pointer to a node struct
* Returns: none
*/

void CharLinkedList::deleteNodes(Node *deleted) {
    if (deleted == nullptr) {
        return;
    }
    deleteNodes(deleted->next);
    delete deleted;
    return;
}


/*
 * name:      assert_in_range(int index)
 * purpose:   simple exception for range error
 * arguments: index of position
 * returns:   none
 * effects:   prints out message if not in range
 */
void CharLinkedList::assert_in_range(int index) const {
    std::stringstream ss;
    ss << "index (" << index 
    << ") not in range [0.." 
    << numItems << ")";
    if (index < 0 or index >= numItems
        or isEmpty()) {
        throw std::range_error(ss.str());
    }
}
