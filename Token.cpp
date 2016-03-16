/* 
 * File:   Token.cpp
 * Author: Alex Grech IV
 * 
 * Created on February 1, 2016, 9:14 PM
 */

#include "Token.h"
using namespace std;

Token::Token() {
}

/**
 * Reads a char in from cin to be set to the token. If the character 
 * is a digit, it puts the char back and reads it in as a number, else it would 
 * be a symbol.
 */
void Token::read() {
    try {
        char input;
        cin >> input;
        if (isdigit(input)) {
            cin.putback(input);
            double number;
            cin >> number;
            setNumber(number);
        } else {
            setSymbol(input);
        }
    } catch (...) {
        cerr << "Something went wrong" << endl;
    }
}

/**
 * Reads a char in from the input to be set to the token. If the character 
 * is a digit, it puts the char back and reads it in as a number, else it would 
 * be a symbol.
 * @param in passes in the istream so that the function reads from the same input
 */
void Token::read(istream& in) {
    try {
        char input;
        in >> input;
        if (isdigit(input)) {
            in.putback(input);
            double number;
            in >> number;
            setNumber(number);
        } else {
            setSymbol(input);
        }
    } catch (...) {
        cerr << "Something went wrong." << endl;
    }
}

/**
 * Checks the type of the token and returns true if it is a number.
 * @return boolean
 */
bool Token::isNumber() const {
    return (type_ == 0);
}

/**
 * Checks the type of the token and returns true if it is a symbol.
 * @return boolean
 */
bool Token::isSymbol() const {
    return (type_ == 1);
}

/**
 * Returns the number value stored in the token. If there is no number, throws
 * the numberAccessException
 * @return 
 */
double Token::getNumber() const {
    try {
        if (!isNumber()) throw numberAccessException;
        return number_;
    } catch (Exceptions numberAccessException) {
        cerr << "Token does not contain a number." << endl;
    }
}

/**
 * Returns the symbol value stored in the token. If there is no symbol, throws
 * the symbolAccessException
 * @return 
 */
char Token::getSymbol() const {
    try {
        if (!isSymbol()) throw symbolAccessException;
        return symbol_;
    } catch (Exceptions symbolAccessException) {
        cerr << "Token does not contain a symbol." << endl;
    }
}

/**
 * Sets the number value of token with the input and sets the type of the token
 * to number
 * @param num number value for the token
 */
void Token::setNumber(double num) {
    number_ = num;
    type_ = number;
}

/**
 * Sets the symbol value of token with the input and sets the type of the token
 * to symbol
 * @param sym symbol value for the token
 */
void Token::setSymbol(char sym) {
    symbol_ = sym;
    type_ = symbol;
}