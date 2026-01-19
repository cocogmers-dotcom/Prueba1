/*

Programa que calcula minimo, maximo, media 
y rango de un conjunto de datos.

Author: Sergio Romero

Date: 19/01/26

*/



#include <iostream>
#include <bits/stdc++.h>
#include <random>
#include <vector>
#include <algorithm>

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


double min(const vector<double>& v){
    double m=1000000000;
    for(int i=0;i<v.size();i++){
        if(v[i]<m){
            m=v[i];
        }
    }
    return m;
}


double max(const vector<double>& v){
    double m=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]>m){
            m=v[i];
        }
    }
    return m;
}

double promedio(const vector<double>& v){
    double m=0;
    for(int i=0;i<v.size();i++){
        m+=v[i];
    }
    return m/v.size();
}

int main(){
    int n=0,m=10000000;
    double mi,ma,ran,pro;
    std::vector<double> datos;
    for(int i=0;i<m;i++){
        datos.push_back(NumberRandom(n,m));
    }
    //for (int n : datos) {
    //    cout << n <<" ";
    //}
    mi=min(datos);
    ma=max(datos);
    pro=promedio(datos);
    ran=ma-mi;
    cout<<endl<< "minimo: "<<mi<<endl;
    cout<<"maximo: "<<ma<<endl;
    cout<<"rango: "<<ran<<endl;
    cout<<"promedio: "<<pro<<endl;
    
    int minimo = *std::min_element(datos.begin(), datos.end());
    cout<<minimo<<endl;
}