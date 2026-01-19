/*

This is a C++ Program to Check if a Number is Even.

The program checks if an entered number is even or not.

From:https: https://www.sanfoundry.com/cpp-program-check-number-even/

Author: Sergio Romero

Date: 25/12/25

*/



#include <iostream>
#include <bits/stdc++.h>
#include <random>

using namespace std;

int NumberRandom(int min,int max){
    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);

    // Generate random number in the range [min, max]
    int randomValue = distrib(gen);
    return randomValue;
}

int IsEvenM(int n){
    if(n%2==0){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEvenWM(int n){
    int m=n/2;
    if(m*2==n){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int n=0,m=10000;
    int a = NumberRandom(n,m);
    int bolM=IsEvenM(a);
    int bolWM=IsEvenWM(a);
    cout << "Number: " << a << " IsEvenM: " << bolM << " IsEvenWM: " << bolWM << endl;
    //cout << a << endl;

    return 0;
}
