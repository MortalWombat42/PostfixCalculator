/* 
 * File:   PostfixCalculator.cpp
 * Author: Alex Grech IV
 * 
 * Created on February 8, 2016, 7:33 PM
 */

#include <iostream>
#include "PostfixCalculator.h"
#include "Token.h"
#include "Stack.h"

using namespace std;

/**
 * Standard constructor that initializes the stack_ with a buffer size of 15 
 * and pushes -1 on the stack twice to prevent errors from stack.
 */
PostfixCalculator::PostfixCalculator() : stack_(15) {
    //Lets the calculator tell if the stack is empty or not without getting 
    //errors from Stack
    stack_.push(-1);
    stack_.push(-1);
}

/**
 * Turns the calculator on.
 */
void PostfixCalculator::turnOn() {
    try {
        cout << "Enter your postfix expression (enter # to end your expression):" << endl;
        //while loop condition
        bool isOn = true;
        while (isOn) {
            Token token;
            token.read();
            //if the token is a number, push it on the stack
            if (token.isNumber()) {
                stack_.push(token.getNumber());
                // if the token is a symbol, does the symbols action
            } else if (token.isSymbol()) {
                //stops the expression if the symbol is a '#'
                if (token.getSymbol() == '#') {
                    cout << "This is your final result: " << stack_.pop() << endl;
                    //checks if there are any extra numbers on the stack
                    if (stack_.peek() != -1) throw missingOperatorException;
                    //checks to see if the user wants to continue using the calc
                    isOn = ifContinue();
                    //evaluates with the symbol if the symbol isn't a '#'
                } else {
                    stack_.push(operate(token.getSymbol()));
                }
            }
        }
        //catches if there are extra numbers on the stack
    } catch (Exceptions missingOperatorException) {
        cerr << "Missing operator. Displaying only partial result." << endl;
        //takes off any extra numbers on the stack
        while (stack_.peek() != -1) stack_.pop();
    }
}

/**
 * Turns the calculator on, but reads from the input. Otherwise identical to the
 * other turnOn function.
 * @param in Where the function reads from.
 */
void PostfixCalculator::turnOn(istream& in) {
    try {
        cout << "Enter your postfix expression (# ends the expression):" << endl;
        bool isOn = true;
        while (isOn) {
            Token token;
            //reads from the input
            token.read(in);
            if (token.isNumber()) {
                stack_.push(token.getNumber());
            } else if (token.isSymbol()) {
                if (token.getSymbol() == '#') {
                    cout << "This is your final result: " << stack_.pop() << endl;
                    if (stack_.peek() != -1) throw missingOperatorException;
                    //reads from the input instead
                    isOn = ifContinue(in);
                } else {
                    stack_.push(operate(token.getSymbol()));
                }
            }
        }
    } catch (Exceptions missingOperatorException) {
        cerr << "Missing operator. Displaying only partial result." << endl;
        while (stack_.peek() != -1) stack_.pop();
    }
}

/**
 * Uses the given symbol to operate on the top two numbers in the stack.  If the
 * symbol is not valid, it is treated as a '+'.  If there are missing operands,
 * they are assumed to be 0.
 * @param sym Symbol used to choose operation.
 * @return Result of operation.
 */
double PostfixCalculator::operate(char sym) {
    //get the top operands from the stack
    double oper2 = stack_.pop();
    double oper1 = stack_.pop();
    try {
        //if the top operand is -1, then it is missing
        if (oper2 == -1) throw missingOperandException;
        //if there is a missing operand, it is treated as a 0
    } catch (Exceptions missingOperandException) {
        cerr << "An operand is missing. Operand assumed to be 0." << endl;
        //replaces the missing operand with a 0 and replaces any '-1's popped 
        //off the bottom of the stack
        if (oper1 == -1) oper1 = 0;
        stack_.push(-1);
        if (oper2 == -1) oper2 = 0;
        stack_.push(-1);
    }
    try {
        //matches the symbol with its operation
        //displays each operation performed
        //then returns the result of the operation
        switch (sym) {
            case '+':
                cout << oper1 << "+" << oper2 << "=" << (oper1 + oper2) << endl;
                return (oper1 + oper2);
                break;
            case '-':
                cout << oper1 << "-" << oper2 << "=" << (oper1 - oper2) << endl;
                return (oper1 - oper2);
                break;
            case '*':
                cout << oper1 << "*" << oper2 << "=" << (oper1 * oper2) << endl;
                return (oper1 * oper2);
                break;
            case '/':
                cout << oper1 << "/" << oper2 << "=" << (oper1 / oper2) << endl;
                return (oper1 / oper2);
                break;
                //if the symbol is invalid
            default:
                throw invalidOperatorException;
                break;
        }
        //invalid symbols are treated as '+'
    } catch (Exceptions invalidOperatorException) {
        cerr << "Invalid operator encountered.  It will be treated as a '+'." << endl;
        cout << oper1 << "+" << oper2 << "=" << (oper1 + oper2) << endl;
        return (oper1 + oper2);
    }
}

/**
 * Checks to see if the user wants to continue.
 * @return Boolean, whether or not to continue.
 */
bool PostfixCalculator::ifContinue() {
    //asks user whether to continue
    cout << "Do you want to continue? (y or n)" << endl;
    //receives answer from user
    char c;
    cin >> c;
    //checks answer and returns result
    if (c == 'y' || c == 'Y') {
        cout << "Enter your postfix expression (# ends the expression):" << endl;
        return true;
    } else return false;
}

/**
 * Checks to see if the user wants to continue. Reads from the input.
 * @param in Where the function reads from.
 * @return Boolean, whether or not to continue.
 */
bool PostfixCalculator::ifContinue(istream& in) {
    cout << "Do you want to continue? (y or n)" << endl;
    char c;
    //reads from input
    in >> c;
    if (c == 'y' || c == 'Y') {
        cout << "Enter your postfix expression (# ends the expression):" << endl;
        return true;
    } else return false;
}