
#include <iostream>

using namespace std;

int main() {
    
    string s;

    cin >> s;

    char prev = s[0];

    int count = 1;

    int l = s.length();

    for(int i = 1; i < l && count < 7; ++i){
        if(s[i] == prev){
            count++;
        } else {
            count = 1;
        }
        prev = s[i];
    }

    if(count == 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
