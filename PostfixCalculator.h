/* 
 * File:   PostfixCalculator.h
 * Author: Alex Grech IV
 *
 * Created on February 8, 2016, 7:33 PM
 */

#ifndef POSTFIXCALCULATOR_H
#define	POSTFIXCALCULATOR_H

#include <iostream>
#include "Stack.h"
#include "Token.h"

class PostfixCalculator {
public:
    PostfixCalculator();
    void turnOn();
    void turnOn(std::istream&);
    double operate(char);
    bool ifContinue();
    bool ifContinue(std::istream&);
private:
    Stack stack_;

    enum Exceptions {
        invalidOperatorException, missingOperandException, missingOperatorException
    };
};

#endif	/* POSTFIXCALCULATOR_H */

