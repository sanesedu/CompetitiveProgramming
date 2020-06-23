
#include <iostream>

using namespace std;

int main() {
    
    int n, a, d;
    string s;

    cin >> n >> s;

    a = d = 0;

    for(int i = 0; i < n; ++i){
        if(s[i] == 'A') ++a;
        else ++d;
    }

    if(a > d){
        cout << "Anton" << endl;
    } else if(d > a){
        cout << "Danik" << endl;
    } else {
        cout << "Friendship" << endl;
    }

    return 0;
}
