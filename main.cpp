//
//  main.cpp
//  STL
//
//  Created by Adam Hinkle on 11/19/19.
//  Copyright © 2019 Adam Hinkle. All rights reserved.
//

/*
 Adam Hinkle
 12/5/19
 Project: Gold Rabiits
 CECS 282-05
 */

#include <iostream>
#include "BigInt.hpp"
#include <map>
#include <vector>
using namespace std;

BigInt goldRabbits(BigInt n){
    static map<BigInt, BigInt> values;
    BigInt one(1);
    if (n <= 1) {
        return one;
    }
    else if (values.count(n) > 0){
        return values[n];
    }
    else{
        BigInt temp = goldRabbits(n-1) + goldRabbits(n-2);
        values[n] = temp;
        return temp;
    }
}
void pause(){
    cout<<"\nPress Enter to continue...";
    getchar();
}

int main() {

    cout <<"The fibonacci sequence value of 3000 is...";

    pause();
    for(BigInt i = 0; i <= 3000; i++){
        cout<<"\ngoldRabbits("<<i<<") = "<<goldRabbits(i);
    }
    cout<<endl;
    pause();
    
    cout<<"\nThis is the value of fibonacci(3000)\n\n";
    BigInt gR3000 = goldRabbits(BigInt(3000));
    gR3000.print();
    cout<<endl;
    return 0;
}
