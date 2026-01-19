#include <iostream>
#include <iterator>
#include <cstring>

using namespace std;

int main() {

    const char* saludo = "Hola, Mundo!";
    
    int length = strlen(saludo);

    //for(int i=0; i<length; i++) {
    //    cout << "Caracter " << i << ": " << saludo[i] << endl;
    //}
    int i = 0;
    while (saludo[i]!= '\0'){
        cout << "Caracter " << i << ": " << saludo[i] << endl;
        i++;
    }
    

    return 0;
}

