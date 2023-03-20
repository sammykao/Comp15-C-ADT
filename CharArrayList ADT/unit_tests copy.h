/*
 * unit_tests.h
 *
 * CS 15 homework 1
 * by Tyler Calabrese, January 2021
 *
 * edited by: Milod Kazerounian, January 2022
 *
 * Uses Matt Russell's unit_test framework to test the CharArrayList class.
 *
 * Instructions for using testing framework can be found at in CS 15's lab
 * 1 -- both in the spec and in the provided ArrayList_tests.h and Makefile.
 * More in-depth information for those who are curious as to how it works can
 * be found at http://www.github.com/mattrussell2/unit_test.
 */

#include "CharArrayList.h"
#include <cassert>
#include <string>
#include <iostream>
/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

/* To give an example of thorough testing, we are providing
 * the unit tests below which test the insertAt function. Notice: we have
 * tried to consider all of the different cases insertAt may be
 * called in, and we test insertAt in conjunction with other functions!
 *
 * You should emulate this approach for all functions you define.
 */


// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() { 
                                   CharArrayList test_list;
                                   test_list.insertAt('a', 0);
                                   assert(test_list.size() == 1);
                                   assert(test_list.elementAt(0) == 'a');
                               
}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
        // insertAt for out-of-range index
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        // if insertAt is correctly implemented, a range_error will be thrown,
        // and we will end up here
        range_error_thrown = true;
        error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");

}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
}

// Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {

    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');

}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }

}

// Tests insertion into front, back, and middle of a larger list.
void insertAt_front_back_middle() {
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        // insertAt middle
        test_list.insertAt('z', 3);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(3) == 'z');
        assert(test_list.toString() == 
        "[CharArrayList of size 9 <<abczdefgh>>]");

        // insertAt front
        test_list.insertAt('y', 0);

        assert(test_list.size() == 10);
        assert(test_list.elementAt(0) == 'y');
        assert(test_list.toString() == 
        "[CharArrayList of size 10 <<yabczdefgh>>]");

        // insertAt back
        test_list.insertAt('x', 10);

        assert(test_list.size() == 11);
        assert(test_list.elementAt(10) == 'x');
        assert(test_list.toString() == 
        "[CharArrayList of size 11 <<yabczdefghx>>]");

}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {

    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");

}

//Tests first default constructor
void CharArrayList1Test1() {
    CharArrayList list;
    assert(list.size() == 0);

}
//Tests single char constructor
void CharArrayList2Test1() {
    CharArrayList list('e');
    assert(list.size() == 1);
}

////Tests overload operator
void overloadoperatorTest1() {
    char arr[5] = {'e', 'e', 'r', 't', 'h'};
    CharArrayList list(arr, 5);
    char arr1[5] = {'r', 'x', 's', 'f', 't'};
    CharArrayList list1(arr1, 5);
    list1 = list;
}

////Tests copy constructor
void copyconstructorTest1() {
    char arr[5] = {'e', 'e', 'r', 't', 'h'};
    CharArrayList list(arr, 5);
    CharArrayList list1(list);
}
//Basic Empty test
void isEmptyTest1() {
    CharArrayList list;
    assert(list.isEmpty() == true);
}

//Multifaceted empty test incorporating multiple methods
void isEmptyTest2() {
    CharArrayList list;
    list.insertAt('e', 0);
    list.pushAtBack('r');
    assert(list.first() == 'e');
    assert(list.last() == 'r');
    list.clear();
    assert(list.size() == 0);
    assert(list.isEmpty() == true);
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        list.first();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    // out here, we make our assertions
    assert(runtime_error_thrown);
    assert(error_message == "cannot get first of empty ArrayList");

}

//size test from array constructor
void sizeTest1() {
    char arr[5] = {'e', 'e', 'r', 't', 'h'};
    CharArrayList list(arr, 5);
    assert(list.size() == 5);
}

//size test for single char constructor
void sizeTest2() {
    CharArrayList list('e');
    assert(list.size() == 1);
}

//basic clear test
void clearTest1() {
    char arr[5] = {'e', 'e', 'r', 't', 'h'};
    CharArrayList list(arr, 5);
    list.clear();
    assert(list.isEmpty() == true);
}

//more complex double clear test
void clearTest2() {
    char arr[5] = {'e', 'e', 'r', 't', 'h'};
    CharArrayList list(arr, 5);
    list.clear();
    assert(list.isEmpty() == true);
    list.clear();
    assert(list.isEmpty() == true);
}

//basic first test
void firstTest1() {
    char arr[5] = {'e', 'e', 'r', 't', 'h'};
    CharArrayList list(arr, 5);
    assert(list.first() == 'e');
}

//more complex first test searching for errors
void firstTest2() {
    CharArrayList list;
    list.pushAtBack('r');
    assert(list.first() == 'r');
    assert(list.last() == 'r');
    list.clear();
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        list.first();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    // out here, we make our assertions
    assert(runtime_error_thrown);
    assert(error_message == "cannot get first of empty ArrayList");
}

//basic lasr test
void lastTest1() {
    char arr[5] = {'e', 'e', 'r', 't', 'h'};
    CharArrayList list(arr, 5);
    assert(list.last() == 'h');
}

//more complex last test searchng for errors
void lastTest2() {
    CharArrayList list('e');
    list.clear();
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        list.last();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    // out here, we make our assertions
    assert(runtime_error_thrown);
    assert(error_message == "cannot get last of empty ArrayList");
}
 
//basic elementAt test
void elementAtTest1() {
    char arr[5] = {'e', 'e', 'r', 't', 'h'};
    CharArrayList list(arr, 5);
    assert(list.elementAt(2) == 'r');
}

////more complex elementAt test searchng for errors
void elementAtTest2() {
    CharArrayList list('e');
    list.clear();
    bool range_error_thrown = false;
    std::string error_message = "";
    try {
        list.elementAt(2);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }
    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (2) not in range [0..0)");
}


//basic tostring test
void toStringTest1() {
    char arr[5] = {'p', 'i', 'z', 'z', 'a'};
    CharArrayList list(arr, 5);
    assert(list.toString() == "[CharArrayList of size 5 <<pizza>>]");
}

//empty tostring test
void toStringTest2() {
    char arr[5] = {'p', 'i', 'z', 'z', 'a'};
    CharArrayList list(arr, 5);
    list.clear();
    assert(list.toString() == "[CharArrayList of size 0 <<>>]");
}

//empty tostring test using deafult constructor
void toStringTest3() {
    CharArrayList list;
    assert(list.toString() == "[CharArrayList of size 0 <<>>]");
}

//basic reversestring test
void toReverseStringTest1() {
    char arr[5] = {'p', 'i', 'z', 'z', 'a'};
    CharArrayList list(arr, 5);
    assert(list.toReverseString() == "[CharArrayList of size 5 <<azzip>>]");
}

//empty toreversestring test
void toReverseStringTest2() {
    char arr[5] = {'p', 'i', 'z', 'z', 'a'};
    CharArrayList list(arr, 5);
    list.clear();
    assert(list.toString() == "[CharArrayList of size 0 <<>>]");
}

//basic pushfrombacktest
void pushFromBackTest1() {
    char arr[5] = {'p', 'i', 'z', 'z', 'a'};
    CharArrayList list(arr, 5);
    list.pushAtBack('s');
    assert(list.toString() == "[CharArrayList of size 6 <<pizzas>>]");
}

//basic pushfromfronttest
void pushFromFrontTest1() {
    char arr[5] = {'p', 'i', 'z', 'z', 'a'};
    CharArrayList list(arr, 5);
    list.pushAtFront('s');
    assert(list.toString() == "[CharArrayList of size 6 <<spizza>>]");
}


//basic insertinorder test
void insertInOrderTest1() {
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList list(arr, 5);
    list.insertInOrder('c');
    assert(list.toString() == "[CharArrayList of size 6 <<abccde>>]");
    list.insertInOrder('g');
    assert(list.toString() == "[CharArrayList of size 7 <<abccdeg>>]");
}

//Basic Test for functionality 
void popFromFrontTest1() {
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList list(arr, 5);
    list.popFromFront();
    assert(list.toString() == "[CharArrayList of size 4 <<bcde>>]");
    list.popFromFront();
    assert(list.toString() == "[CharArrayList of size 3 <<cde>>]");
}

//More complex test to test to see if it catches an error
void popFromFrontTest2() {
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList list(arr, 5);
    list.popFromFront();
    assert(list.toString() == "[CharArrayList of size 4 <<bcde>>]");
    list.popFromFront();
    assert(list.toString() == "[CharArrayList of size 3 <<cde>>]");
    list.clear();
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        list.popFromFront();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    // out here, we make our assertions
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty ArrayList");
}

//Basic Test for functionality 
void popFromBackTest1() {
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList list(arr, 5);
    list.popFromBack();
    assert(list.toString() == "[CharArrayList of size 4 <<abcd>>]");
    list.popFromBack();
    assert(list.toString() == "[CharArrayList of size 3 <<abc>>]");
}

//More complex test to test to see if it catches an error
void popFromBackTest2() {
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList list(arr, 5);
    list.popFromBack();
    assert(list.toString() == "[CharArrayList of size 4 <<abcd>>]");
    list.popFromBack();
    assert(list.toString() == "[CharArrayList of size 3 <<abc>>]");
    list.clear();
    bool runtime_error_thrown = false;
    std::string error_message = "";
    try {
        list.popFromFront();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }
    // out here, we make our assertions
    assert(runtime_error_thrown);
    assert(error_message == "cannot pop from empty ArrayList");
}

//Testing the remove function 
//in an already created CharArrayList
void removeAtTest1() {
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    CharArrayList list(arr, 5);
    list.removeAt(1);
    assert(list.toString() == "[CharArrayList of size 4 <<acde>>]");
    list.removeAt(2);
    assert(list.toString() == "[CharArrayList of size 3 <<ace>>]");
}