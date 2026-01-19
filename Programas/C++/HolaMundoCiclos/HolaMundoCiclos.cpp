#include <iostream>
#include <iterator>
#include <cstring>
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


int main() {
    int n=0,m=10;
    int a = NumberRandom(n,m);
    cout << "Numero aleatorio entre " << n << " y " << m << ": " << a << endl;
    //for(int i=0;i<a;i++){
    //    cout << "Hola Mundo " << i+1 << endl;
    //}
    //while(a>0){
    //    cout << "Hola Mundo " << a << endl;
    //    a--;
    //}
    do
    {
        cout << "Hola Mundo " << a << endl;
        a--;
    } while (a > 0);
    
    return 0;
}

