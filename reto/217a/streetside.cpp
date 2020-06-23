
#include <iostream>

using namespace std;

int main(){

    int a;

    bool b = true;

    while(b){
        cin >> a;
        if(a == 0){
            b = false;
            break;
        } else {
            if(a%2 == 0){
                cout << "DERECHA" << endl;
            } else {
                cout <<  "IZQUIERDA" << endl;
            }
        }
    }
}
