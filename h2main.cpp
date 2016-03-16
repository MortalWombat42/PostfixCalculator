///* 
// * File:   h2main.cpp
// * Author: Alex Grech IV
// *
// * Created on February 6, 2016, 1:35 PM
// */
//
//#include "Stack.h"
//#include <iostream>
//
//using namespace std;
//
//int main(int argc, char** argv) {
//    //tests push(), dump(), peek(), and pop()
//    Stack stack1;
//    cout << "Stack 1" << endl;
//    stack1.display();
//    cout << "Fill the stack" << endl;
//    for (int i = 1; i <= 10; i++) {
//        stack1.push(i);
//    }
//    stack1.display();
//    cout << "Push 11 on top" << endl;
//    stack1.push(11);
//    stack1.display();
//    cout << "Peek at top: " << stack1.peek() << endl;
//    cout << "Pop off top: " << stack1.pop() << endl;
//    cout << "Peek at top: " << stack1.peek() << endl;
//    stack1.display();
//    //tests the constructor that sets the buffer size
//    Stack stack2(5);
//    cout << "Stack 2" << endl;
//    stack2.display();
//    cout << "Fill the stack" << endl;
//    for (int i = 1; i <= 5; i++) {
//        stack2.push(i);
//    }
//    stack2.display();
//    cout << "Push 6 on top" << endl;
//    stack2.push(6);
//    stack2.display();
//    //tests the copy constructor and the assignment operator
//    Stack stack3(stack1);
//    cout << "Stack 3, copy of stack 1" << endl;
//    stack3.display();
//    stack3 = stack2;
//    cout << "Stack 3, copy of stack 2" << endl;
//    stack3.display();
//    //tests error throwing from pop() and peek()
//    Stack stack4;
//    cout << "Stack 4" << endl;
//    stack4.display();
//    cout << "Popping and peeking from stack 4 (should throw errors)" << endl;
//    stack4.pop();
//    stack4.peek();
//}