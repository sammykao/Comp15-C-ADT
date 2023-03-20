/*
 *  unit_tests.h
 *  SAMMY KAO
 *  2/01/2023
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  File is using unit test frame work to conduct tests upon the 
 *  CharLinkedList ADT class. Tests range from simple fucntionality
 *  to error detection, to withstanding multiple stimuli.
 *  
 */
#include <string>
#include <iostream>
#include <stdexcept>
#include "CharLinkedList.h"
#include <cassert>


//Tests default constructor 
void constructortest1() {
    CharLinkedList list;
}

//Tests single char constructor 
void constructortest2() {
    CharLinkedList list('e');
    std::cout << list.toString();
}

//Tests simple array constructor 
void constructortest3() {
    char list[3]= {'e', 'e', 'e'};
    CharLinkedList list1(list, 3);
    std::cout << list1.toString();
}

//Tests copyconstructor
void copyconstructortest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    CharLinkedList list2(list1);
    std::cout << list1.toString();
    std::cout << list2.toString();
}

//Tests overload operator
void overloadoperatorTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    CharLinkedList list2;
    list1 = list2;
    std::cout << list1.toString();
    std::cout << list2.toString();
}

//Tests isEmpty function on two different lists
void isEmptytest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    CharLinkedList list2;
    //List 2 should already be empty
    assert(list2.isEmpty() == true);
    list1.clear();
    //Tests clear function too
    assert(list1.isEmpty() == true);
    //if clear works, then should be true
}

//Tests clear function on list2
void clearTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    CharLinkedList list2;
    assert(list2.isEmpty() == true);
    list1.clear();
    //Tests clear here
    assert(list1.isEmpty() == true);
}

//Tests simple size function
void sizeTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    CharLinkedList list2;
    //Should be 0
    assert(list2.size() == 0);
    assert(list1.size() == 5);
}

//Tests first function
void firstTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    assert(list1.first() == 'p');
}

//More complex first test seeing if it responds to errors
void firstTest2() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.clear();
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        list1.first();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    // looking for an error to be thrown
    assert(runtime_error_thrown);
    assert(error_message == "cannot get first of empty LinkedList");
}

//Tests Last function
void lastTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    assert(list1.last() == 'y');
}

//More complex lasr test seeing if it responds to errors
void lastTest2() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.clear();
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        list1.last();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    //Should be errors
    assert(runtime_error_thrown);
    assert(error_message == "cannot get last of empty LinkedList");
}

//Simple elementAt test
void elementAtTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    assert(list1.elementAt(3) == 'g');
}

//More complex ElementAt test seeing if it responds to errors
void elementAtTest2() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    bool range_error_thrown = false;
    std::string error_message = "";
    try {
        list1.elementAt(200);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    //Should be errors
    assert(range_error_thrown);
    assert(error_message == "index (200) not in range [0..5)");
}

//Simple ToString() test, to string tested in other tests as well
void toStringTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    assert(list1.toString() == "[CharLinkedList of size 5 <<piggy>>]");
}

//Simple ToReverseString() test, toreversestring tested in other tests as wel
void toReverseStringTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    assert(list1.toReverseString() == "[CharLinkedList of size 5 <<yggip>>]");
}

//Tests PushatBack functon
void pushatbackTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.pushAtBack('s');
    //Size should update
    assert(list1.toString() == "[CharLinkedList of size 6 <<piggys>>]");
}

//Tests PushatFront function
void pushatfrontTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.pushAtFront('s');
    //Size should update
    assert(list1.toString() == "[CharLinkedList of size 6 <<spiggy>>]");
}

//Simplle Insert at Tests
void insertAtTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.insertAt('z', 4);
    //Size should update
    assert(list1.toString() == "[CharLinkedList of size 6 <<piggzy>>]");
}

//More complex InsertAt test adding to the back of a list
void insertAtTest2() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.insertAt('s', 5);
    //Size should Update
    assert(list1.toString() == "[CharLinkedList of size 6 <<piggys>>]");
}

//More complex insertAt test looking for errors
void insertAtTest3() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    bool range_error_thrown = false;
    std::string error_message = "";
    try {
        list1.insertAt('s',200);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    //Should be an error
    assert(range_error_thrown);
    assert(error_message == "index (200) not in range [0..5]");
}

//Tests insert in order as well as pushAtBack
void insertinorderTest() {
    CharLinkedList list1;
    list1.pushAtBack('a');
    //Adding to an empty list
    list1.pushAtBack('b');
    list1.pushAtBack('c');
    list1.pushAtBack('e');
    list1.pushAtBack('f');
    std::cout << list1.toString();
    list1.insertInOrder('d');
    assert(list1.toString() == "[CharLinkedList of size 6 <<abcdef>>]");
}

//More complex insertInOrder test, inserting to empty list
void insertinorderTest2() {
    CharLinkedList list1;
    std::cout << list1.toString();
    list1.insertInOrder('d');
    list1.insertInOrder('r');
    std::cout << list1.toString();
    list1.insertInOrder('a');
    list1.insertInOrder('g');
    std::cout << list1.toString();
    list1.insertInOrder('z');
    assert(list1.toString() == "[CharLinkedList of size 5 <<adgrz>>]");
}

//More complex insertinorder test, list of 11 elements
void insertinorderTest3() {
    char list[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list1(list, 11);
    list1.insertInOrder('m');
    list1.insertInOrder('u');
    list1.insertInOrder('a');
    list1.insertInOrder('z');
    assert(list1.toString() == 
    "[CharLinkedList of size 15 <<aabcehilmnqtuvz>>]");
}

//simple pop from front test
void popfromfrontTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.popFromFront();
    assert(list1.toString() == "[CharLinkedList of size 4 <<iggy>>]");
}

//more complex pop from front test
void popfromfrontTest2() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.popFromFront();
    list1.popFromFront();
    assert(list1.toString() == "[CharLinkedList of size 3 <<ggy>>]");
}


//more complex pop from front test with 11 chars
void popfromfrontTest3() {
    char list[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list1(list, 11);
    list1.popFromFront();
    assert(list1.toString() == 
    "[CharLinkedList of size 10 <<bcehilnqtv>>]");
}

//most complex pop from front test scanning for errors
void popfromfrontTest4() {
    char list[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list1(list, 11);
    list1.clear();
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        list1.popFromFront();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    //should be error
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");
}

//simple pop from back test
void popfrombackTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.popFromBack();
    assert(list1.toString() == "[CharLinkedList of size 4 <<pigg>>]");
}

//more complex pop from test
void popfrombackTest2() {
    CharLinkedList list1;
    //also tests pushatback
    list1.pushAtBack('a');
    list1.pushAtBack('b');
    list1.pushAtBack('c');
    list1.pushAtBack('e');
    list1.pushAtBack('f');
    list1.popFromBack();
    assert(list1.toString() == "[CharLinkedList of size 4 <<abce>>]");
}

//more complex pop from back test, with two calls
void popfrombackTest3() {
    char list[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list1(list, 11);
    list1.popFromBack();
    list1.popFromBack();
    assert(list1.toString() == 
    "[CharLinkedList of size 9 <<abcehilnq>>]");
}

//Most complex popfromback test, searching for errors
void popfrombackTest4() {
    char list[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list1(list, 11);
    list1.clear();
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        list1.popFromBack();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    //should be errors
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty LinkedList");
}

//simple removeat test
void removeatTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.removeAt(1);
    assert(list1.toString() == "[CharLinkedList of size 4 <<pggy>>]");
}


//More complex removeat test with 4 calls
void removeatTest2() {
    char list[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list1(list, 11);
    list1.removeAt(2);
    list1.removeAt(5);
    list1.removeAt(0);
    list1.removeAt(7);
    assert(list1.toString() == 
    "[CharLinkedList of size 7 <<behinqt>>]");
}

//Most complex removeat test searching for errors
void removeatTest3() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    bool range_error_thrown = false;
    std::string error_message = "";
    try {
        list1.removeAt(200);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    //should be error
    assert(range_error_thrown);
    assert(error_message == "index (200) not in range [0..5)");
}


//smple replaceat test
void replaceatTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    list1.replaceAt('e', 1);
    assert(list1.toString() == "[CharLinkedList of size 5 <<peggy>>]");
}


//more complex replace at test with 10 calls
void replaceatTest2() {
    char list[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list1(list, 11);
    list1.replaceAt('z',0);
    list1.replaceAt('z',1);
    list1.replaceAt('z',2);
    list1.replaceAt('z',3);
    list1.replaceAt('z',4);
    list1.replaceAt('z',5);
    list1.replaceAt('z',6);
    list1.replaceAt('z',7);
    list1.replaceAt('z',8);
    list1.replaceAt('z',9);
    list1.replaceAt('z',10);
    assert(list1.toString() == 
    "[CharLinkedList of size 11 <<zzzzzzzzzzz>>]");
}

//Most complex replace at test searching for errors
void replaceatTest3() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    bool range_error_thrown = false;
    std::string error_message = "";
    try {
        list1.replaceAt('z',200);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    //should be errors
    assert(range_error_thrown);
    assert(error_message == "index (200) not in range [0..5)");
}


//simple concatenate test
void concatenateTest() {
    char list[5]= {'p', 'i', 'g', 'g', 'y'};
    CharLinkedList list1(list, 5);
    char list4[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list2(list4, 11);
    list2.concatenate(&list1);
    assert(list2.toString() == 
    "[CharLinkedList of size 16 <<abcehilnqtvpiggy>>]");
}

//test that concatenates an empty list to already created one
void concatenateTest2() {
    CharLinkedList list1;
    char list4[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list2(list4, 11);
    list2.concatenate(&list1);
    assert(list2.toString() == 
    "[CharLinkedList of size 11 <<abcehilnqtv>>]");
}

//test that concatenates an already created list to an empty one
void concatenateTest3() {
    CharLinkedList list1;
    char list4[11]= {'a', 'b', 'c', 'e', 'h', 
    'i', 'l', 'n', 'q', 't', 'v'};
    CharLinkedList list2(list4, 11);
    list1.concatenate(&list2);
    assert(list2.toString() == 
    "[CharLinkedList of size 11 <<abcehilnqtv>>]");
}

//concatenating two emptylists
void concatenateTest4() {
    CharLinkedList list1;
    CharLinkedList list2;
    list1.concatenate(&list2);
    assert(list1.toString() == 
    "[CharLinkedList of size 0 <<>>]");
}

