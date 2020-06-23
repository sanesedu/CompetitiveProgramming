
#include <iostream>

using namespace std;

int main(){
    
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;

        cin >> a >> b;

        if(a == 25 && b == 12){
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
