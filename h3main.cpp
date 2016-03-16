/* 
 * File:   h3main.cpp
 * Author: Alex Grech IV
 *
 * Created on February 8, 2016, 6:35 PM
 */

#include "PostfixCalculator.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    PostfixCalculator calc; // create a calculator
    calc.turnOn(); // test calc
    cout << "Enter file name to read from:" << endl; // get input file name
    //in_file.txt is included for input file
    string file;
    cin >> file;
    ifstream infile(file.c_str()); // open input file to read from
    cout << "Enter file name to write to:" << endl; // get output file name
    //out_fie.txt is included for output file
    cin >> file;
    ofstream outfile(file.c_str()); // open output file to read from
    streambuf *oldcoutbuf = cout.rdbuf(outfile.rdbuf()); // redirect cout
    streambuf *oldcerrbuf = cerr.rdbuf(outfile.rdbuf()); // redirect cerr
    calc.turnOn(infile); // TEST A CALCULATOR THAT USES FILE I/O
    cout.rdbuf(oldcoutbuf); // restore cout to the screen
    cerr.rdbuf(oldcerrbuf); // restore cerr to the screen
    infile.close();
    outfile.close();
}
