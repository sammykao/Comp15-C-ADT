/*
 *  CharArrayList.h
 *  SAMMY KAO
 *  01/25/2023
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  PURPOSE: DEFINITION OF CHARARRAYLIST CLASS 
 *
 */
#ifndef CHAR_ARRAY_LIST_H
#define CHAR_ARRAY_LIST_H
#include <string>
#include <stdexcept>

class CharArrayList {
public:
    CharArrayList();
    CharArrayList(char c);
    CharArrayList(char arr[], int size);
    CharArrayList(const CharArrayList &other);

    ~CharArrayList();
    CharArrayList &operator=(const CharArrayList &other);
    //retrieval methods
    bool isEmpty() const;
    void clear();
    int size() const;
    char first() const;
    char last() const;
    char elementAt(int index) const;

    std::string toString() const;
    std::string toReverseString() const;
    //insertion methods
    void pushAtBack(char c);
    void pushAtFront(char c);
    void insertAt(char c, int index);
    void insertInOrder(char c);

    //removal methods
    void popFromFront();
    void popFromBack();
    void removeAt(int index);

    void replaceAt(char c, int index);
    void concatenate(CharArrayList *other);
    void shrink();
    void sort();
    CharArrayList *slice(int left, int right);



private:
    void assert_in_range(int index) const;
    void expand();
    int numItems;
    int capacity;
    char *list;
};

#endif
