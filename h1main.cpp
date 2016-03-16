///* 
// * File:   h1main.cpp
// * Author: Alex Grech IV
// *
// * Created on February 1, 2016, 8:02 PM
// */
//
//#include <iostream>
//#include <fstream>
//#include "Token.h"
//
//using namespace std;
//
///**
// * tests the functionality of the token class
// */
//int main(int argc, char** argv) {
//    cout << "Enter 2 tokens" << endl;
//    Token t1,t2;
//    t1.read(cin);
//    t2.read(cin);
//    cout << "Enter file name to read from" << endl;
//    string file;
//    cin >> file;
//    ifstream inf(file.c_str(), ifstream::in);
//    Token t3;
//    t3.read(inf);
//    inf.close();
//    cout << "Token 1:" << endl;
//    if (t1.isNumber()) {
//        cout << t1.getNumber() << endl;
//    } else {
//        cout << t1.getSymbol() << endl;
//    }
//    cout << "Token 2: (should catch exception)" << endl;
//    if (t2.isSymbol()) {
//        cout << t2.getNumber() << endl;
//    } else {
//        cout << t2.getSymbol() << endl;
//    }
//    cout << "Token 3:" << endl;
//    if (t3.isNumber()) {
//        cout << t3.getNumber() << endl;
//    } else {
//        cout << t3.getSymbol() << endl;
//    }
//}
//
