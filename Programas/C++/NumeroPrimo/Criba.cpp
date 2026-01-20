/*

Programa para calcular los n primos que soporta el
tipo int en mi computadora.

Author: Sergio Romero

Date: 19/01/26

*/



#include <iostream>
#include <bits/stdc++.h>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <fstream>
#include <iomanip>


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


void buscar(vector<unsigned int>& primos,unsigned int multiplo){
    for(int i=0;i<primos.size();i++){
        if(primos[i]==multiplo){
            primos[i]=0;
            break;
        }
    }
}


void criba(vector<unsigned int>& primos,unsigned int t)
{
    int i=0,j=0,n,multiplo=0;
    do{
        if(primos[i]!=0){
            multiplo=0;
            n=primos[i];
            multiplo+=n+i;
            //cout<<n<<endl;
            while(multiplo<t){
                primos[multiplo]=0;
                multiplo+=n;    
            }
            i++;
        }
        else
            i++;
    }while(i<t);
}


int main(){
    ofstream Nprimos;
    Nprimos.open("Nprimos.txt");
    //unsigned int maxi=1294967295;
    unsigned int maxi=1000000;
    vector<unsigned int> primos(maxi-1);
    iota(primos.begin(),primos.end(),2);
    //cout<<primos[5]<<endl;
    criba(primos,primos.size());
    //cout<<"N= "<<maxi<<" primos: ";
    //for(int i=0;i<primos.size();i++){
    //    if(primos[i]!=0)
    //        cout<<primos[i]<<" ";
    //}
    //cout<<endl;
    int contador=1;
    if (Nprimos.is_open()){
        for(int i=0;i<primos.size();i++){
            if(primos[i]!=0){
                Nprimos<<setw(10)<<primos[i]<<" ";
                contador++;
            }
            if(contador % 10==0){
                Nprimos<<endl;
                contador=1;
            }
        }
    }
    Nprimos.close();
}
