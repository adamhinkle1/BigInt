#include "BigInt.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
// Jimmy Truong
// CECS 282-05
// Prog 5- Standard Template Library(STL)
// 11/21/19
vector<char> v;

BigInt::BigInt() {
    v.push_back(0);
}

BigInt::BigInt(string number) {
    for (int i = number.length() - 1; i >= 0; i--) {
        v.push_back(number[i] - '0');
    }
}

BigInt::BigInt(int number) {
    while (number > 9) {
        int temp = number % 10;
        v.push_back(temp);
        number /= 10;
    }
    v.push_back(number);
}

vector<char> BigInt::getVector() {
    return v;
}

void BigInt::setVector(vector<char> in) {
    v = in;
}

BigInt BigInt::operator+(BigInt b) {
    int pad = 0;
    int carry = 0;
    BigInt temp(*this);
    vector<char> temp1 = temp.getVector();
    vector<char> vb = b.getVector();
    vector<char> sum;
    if (temp1.size() > vb.size()) {
        pad = temp1.size() - vb.size();
        while (pad > 0) {
            vb.push_back(0);
            pad--;
        }
    }
    else if(vb.size() > temp1.size()){
        pad = vb.size() - temp1.size();
        while (pad > 0) {
            temp1.push_back(0);
            pad--;
        }
    }
    for (int i = 0; i < temp1.size()-1; i++) {
        int a = temp1[i];
        int b = vb[i];
        int c = a + b;
        if (c >= 10) {
            temp1[i+1]++;
            c -= 10;
        }
        sum.push_back(c);
        
    }
    int end = temp1[temp1.size() - 1];
    int end2 = vb[vb.size() - 1];
    int end3 = end + end2;
    if (end3 >= 10) {
        end3 -= 10;
        sum.push_back(end3);
        sum.push_back(1);
    }
    else {
        sum.push_back(end3);
    }
    
    BigInt result;
    result.v = sum;
    return result;
    
}

BigInt BigInt::operator-(int b) {
    vector<char> temp = v;
    vector<char>::iterator c = temp.begin();
    vector<char>::iterator c2 = temp.end();
    if (temp.size() > 1) {
        if (*c < b) {
            if (*++c == 0) {
                int inc = 1;
                while (*c == 0) {
                    inc++;
                    c++;
                }
                while (inc != 0) {
                    *c -= 1;
                    *--c += 10;
                    inc--;
                }
            }
            else {
                *c -= 1;
                *--c += 10;
            }
        }
        *c -= b;
        if (*--c2 == 0) {
            temp.erase(c2);
        }
    }
    else {
        *c -= b;
    }
    BigInt last;
    last.setVector(temp);
    return last;
}

bool operator<(const BigInt& b, const BigInt& c) {
    if (b.v.size() == c.v.size()) {
        for (int i = b.v.size() - 1; i >= 0; i--) {
            if (b.v[i] < c.v[i]) {
                return true;
            }else if(b.v[i] > c.v[i]){
                return false;
            }
        }
    }
    else if(b.v.size() > c.v.size()){
        return false;
    }
    else if(b.v.size() < c.v.size()){
        return true;
    }
    return false;
}

string BigInt::toString() {
    vector<char>::reverse_iterator rit = v.rbegin();
    string number;
    while (rit != v.rend()) {
        number += *rit;
    }
    return number;
}

bool BigInt::operator<=(int i) {
    BigInt num(i);
    if (*this < num || v == num.v) {
        return true;
    }
    else {
        return false;
    }
}

bool BigInt::operator==(int i) {
    BigInt temp(i);
    if (v == temp.v) {
        return true;
    }
    else {
        return false;
    }
}

bool BigInt::operator==(BigInt i) {
    bool eq;
    vector<char> v2 = i.getVector();
    vector<char>::reverse_iterator c = v.rbegin();
    vector<char>::reverse_iterator c2 = v2.rbegin();
    if (v.size() == v2.size()) {
        while (*c == *c2) {
            if (c == v.rend()) {
                if (*c == *c2) {
                    eq = true;
                    break;
                }
                else {
                    eq = false;
                    break;
                }
            }
        }
    }
    else {
        eq = false;
    }
    return eq;
}

void BigInt::print() {
    vector<char>::reverse_iterator rit;
    rit = v.rbegin();
    while (rit != v.rend()) {
        cout << (int)*rit;
        rit++;
    }
}

ostream& operator<<(ostream& out, BigInt b) {
    vector<char>::reverse_iterator rit;
    rit = b.v.rbegin();
    if (b.v.size() > 12) {
        out << (int)*rit << ".";
        rit++;
        for (int i = 0; i < 10; i++) {
            out << (int)*rit;
            rit++;
        }
        out << "e" << b.v.size();
    }
    else {
        while (rit != b.v.rend()) {
            out << (int)*rit;
            rit++;
        }
    }	 return out;
}

BigInt BigInt::operator++(int i) {
    BigInt temp(*this);
    BigInt one(1);
    *this = *this + one;
    return temp;
}
