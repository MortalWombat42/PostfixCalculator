/* 
 * File:   Token.h
 * Author: Alex Grech IV
 *
 * Created on February 1, 2016, 9:14 PM
 */

#ifndef TOKEN_H
#define	TOKEN_H

#include <iostream>

class Token {
public:
    Token();
    void read();
    void read(std::istream&);
    bool isNumber() const;
    bool isSymbol() const;
    double getNumber() const;
    char getSymbol() const;
private:
    void setNumber(double);
    void setSymbol(char);

    enum Type {
        number, symbol
    };
    Type type_;

    union {
        double number_;
        char symbol_;
    };

    enum Exceptions {
        symbolAccessException, numberAccessException
    };
};

#endif	/* TOKEN_H */

