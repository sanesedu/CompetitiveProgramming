
#include <iostream>

using namespace std;

int main(){

    int n, a, t;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        c= 0;

        for(int j = 0; j < a; j++){
            cin >> t;
            if(t % 2 == 0) c++;
        }

        cout << c << endl;
    }

    return 0;
}
