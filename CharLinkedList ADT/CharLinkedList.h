/*
 *  CharLinkedList.h
 *  SAMMY KAO
 *  2/01/2023
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  This file is the interface of the ADT CharLinkedList class
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H
#include <string>
#include <stdexcept>

class CharLinkedList {
public:
    //Constructors
    CharLinkedList();
    CharLinkedList(char c);
    CharLinkedList(char arr[], int size);
    CharLinkedList(const CharLinkedList &other);


    //Destructor
    ~CharLinkedList();
    CharLinkedList &operator=(const CharLinkedList &other);
    //retrieval functions
    bool isEmpty() const;
    void clear();
    int size() const;
    char first() const;
    char last() const;
    char elementAt(int index) const;
    std::string toString() const;
    std::string toReverseString() const;

    //insertion function
    void pushAtBack(char c);
    void pushAtFront(char c);
    void insertAt(char c, int index);
    void insertInOrder(char c);

    //removal functions
    void popFromFront();
    void popFromBack();
    void removeAt(int index);
    void replaceAt(char c, int index);
    void concatenate(CharLinkedList *other);


private:
    //node struct
    struct Node {
        char      info;
        Node      *next;
        Node      *previous;
    };

    Node *front;
    Node *back;
    Node *newNode(char input, Node *next, Node *previous);
    void deleteNodes(Node *next);
    int  numItems;  
    void assert_in_range(int index) const;
};

#endif
