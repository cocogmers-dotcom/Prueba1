/*

This C++ Program which gets a number from input and displays the sum of the digits in the given number.

From:https: https://www.sanfoundry.com/cpp-program-display-sum-of-digits/

Author: Sergio Romero

Date: 25/12/25

*/



#include <iostream>
#include <bits/stdc++.h>
#include <random>
#include <cmath>

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


int sumaNum(int a){
    int n=1,l=0,num=1,sumat=0;
    while(a>=n){
        n=n*10;
        l=l+1;
    }
    int d=pow(10,l-1);
    for(int i=0;i<l;i++){
        num=1;
        while(num<10){
            if(a-num==d){
                sumat=sumat+num;
                num=10;
                d=d/10;
                if(d==1){
                    d=0;
                }
            }
            else{
                num=num+1;
            }
        }
    }
    return sumat;
}

int main()
{
    int n=0,m=10000;
    int a = NumberRandom(n,m);
    int sumN=sumaNum(a);
    cout << a << " " << sumN << endl;

    return 0;
}
