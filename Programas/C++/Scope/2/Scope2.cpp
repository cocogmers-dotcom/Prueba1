#include <iostream>

using namespace std;

int main(){
    int arg1;
    arg1 = -1;
    {
        char arg1 = 'A';
        cout << "Valor de arg1 en el ambito interno: " << arg1 << endl;
    }
    cout << "Valor de arg1 en el ambito externo: " << arg1 << endl;
    return 0;
}
