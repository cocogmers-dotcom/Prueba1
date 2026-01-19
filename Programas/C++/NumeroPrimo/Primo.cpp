/*

Programa para calcular si un numero es primo.

Author: Sergio Romero

Date: 19/01/26

*/



#include <iostream>
#include <bits/stdc++.h>
#include <random>
#include <vector>
#include <algorithm>
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

int primo(const vector<int>& primos, int p)
{
    int max=int(sqrt(p));
    return 1;
}

int main(){
    int n=0,m=1000,a,p;
    a=NumberRandom(n,m);
    std::vector<int> primos;
    p=primo(primos,a);
    cout<<a<<" "<<p<<" "<<sqrt(a)<<" "<<int(sqrt(a))<<endl;
}