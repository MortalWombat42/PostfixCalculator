/* 
 * File:   Stack.cpp
 * Author: Alex Grech IV
 * 
 * Created on February 6, 2016, 12:34 PM
 */


#include <iostream>
#include <string.h>
#include "Stack.h"

using namespace std;

/**
 * Standard constructor that initializes the constants and creates a new array
 * of size size_ for array_ to point to.
 */
Stack::Stack() : BUFFERSIZE_(10), top_(-1), size_(10) {
    array_ = new int[size_];
}

/**
 * Sets BUFFERSIZE_ and size_ to the parameter buffer.
 * @param buffer The buffer size.
 */
Stack::Stack(int buffer) : BUFFERSIZE_(buffer), top_(-1), size_(buffer) {
    array_ = new int[size_];
}

/**
 * The copy constructor.
 * @param orig The stack that is being copied.
 */
Stack::Stack(const Stack &orig) : BUFFERSIZE_(orig.BUFFERSIZE_), top_(orig.top_),
size_(orig.size_) {
    array_ = new int[size_];
    memcpy(array_, orig.array_, (top_ + 1) * sizeof (*orig.array_));
}

/**
 * The assignment operator.
 * @param rhs The right hand side of the operator.
 * @return 
 */
Stack& Stack::operator=(const Stack &rhs) {
    if (this != &rhs) {
        int *newArray = new int[rhs.size_];
        memcpy(newArray, rhs.array_, (rhs.top_ + 1) * sizeof (rhs.array_));
        delete [] array_;
        array_ = newArray;
        size_ = rhs.size_;
        top_ = rhs.top_;
    }
    return *this;
}

/**
 * Destructor, deletes the array that array_ points to.
 */
Stack::~Stack() {
    delete[] array_;
}

/**
 * "Pushes" the input number on top of the stack.
 * @param number The number that is to be put on top of the stack.
 */
void Stack::push(double number) {
    if (top_ + 1 == size_) dump();
    array_[++top_] = number;
}

/**
 * "Pops" the top number off of the top of the stack. If the stack is empty, 
 * returns -1.
 * @return The number formerly at the top of the stack.
 */
double Stack::pop() {
    try {
        if (top_ == -1) throw emptyStackException;
        return array_[top_--];
    } catch (Exceptions emptyStackException) {
        cerr << "The stack is empty." << endl;
        return -1;
    }
}

/**
 * "Peeks" at the top element of the stack without removing from the stack.  
 * If the stack is empty, returns -1.
 * @return The number currently at the top of the stack.
 */
double Stack::peek() const {
    try {
        if (top_ == -1) throw emptyStackException;
        return array_[top_];
    } catch (Exceptions emptyStackException) {
        cerr << "The stack is empty." << endl;
        return -1;
    }
}

/**
 * Displays all of the items currently in the stack, as well as the values of
 * top_ and size_.  For debugging purposes only.
 */
void Stack::display() const {
    cout << "[";
    for (int i = 0; i <= top_; i++) {
        cout << array_[i] << ",";
    }
    cout << "]" << endl;
    cout << "Top: " << top_ << endl;
    cout << "Size: " << size_ << endl;
}

/**
 * Creates a new array that is BUFFERSIZE_ larger than the previous array, then 
 * dumps the old data into the new array.
 */
void Stack::dump() {
    size_ += BUFFERSIZE_;
    int *newArray = new int[size_];
    memcpy(newArray, array_, (top_ + 1) * sizeof (*array_));
    delete[] array_;
    array_ = newArray;
}