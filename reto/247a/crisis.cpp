
#include <iostream>

using namespace std;

int main(){
    
    bool b = true;
    int a;

    while(b){
        cin >> a;

        if(a == 0){
            b = false;
            break;
        } else {

            int curr, prev = 0;
            bool found = true;

            for(int i = 0; i < a; i++){
                cin >> curr;
                if(curr <= prev){
                    found = false;
                }
                prev = curr;
            }

            if(found){
                cout << "SI" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

    }
}
