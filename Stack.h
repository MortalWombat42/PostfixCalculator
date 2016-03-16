/* 
 * File:   Stack.h
 * Author: Alex Grech IV
 *
 * Created on February 6, 2016, 12:34 PM
 */

#ifndef STACK_H
#define	STACK_H

class Stack {
public:
    Stack();
    Stack(int buffer);
    Stack(const Stack&);
    Stack& operator=(const Stack&);
    ~Stack();
    void push(double number);
    double pop();
    double peek() const;
    void display() const;
private:
    void dump();
    const int BUFFERSIZE_;
    int top_;
    int size_;
    int *array_;

    enum Exceptions {
        emptyStackException
    };
};

#endif	/* STACK_H */

