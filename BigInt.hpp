#pragma once
#include<string>
#include<vector>
#include <iostream>
#ifndef BigInt_hpp
#define BigInt_hpp

using namespace std;
// Jimmy Truong
// CECS 282-05
// Prog 5- Standard Template Library(STL)
// 11/21/19
class BigInt
{
private:
    vector<char> v;
    vector<char>::iterator ptr;
public:
    BigInt();
    BigInt(string);
    BigInt(int);
    vector<char> getVector();
    void setVector(vector<char>);
    BigInt operator-(int);
    BigInt operator+(BigInt);
    friend bool operator<(const BigInt&,const BigInt&);
    string toString();
    bool operator<=(int);
    bool operator==(int);
    void print();
    friend ostream& operator<<(ostream&, BigInt);
    bool operator==(BigInt);
    BigInt operator++(int);
};
#endif /* BigInt_h */
