
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x; 
    cin >> x;

    int rem = x % 4;

    switch(rem) {
        case 0:
            cout << "1 A\n";
            break;
        case 1: 
            cout << "0 A\n";
            break;
        case 2:
            cout << "1 B\n";
            break;
        case 3: 
            cout << "2 A\n";
            break;
    }

    return 0;
}
