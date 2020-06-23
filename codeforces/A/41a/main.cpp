
#include <iostream>

using namespace std;

int main() {

    string s, t;

    cin >> s >> t;

    if(s.length() != t.length()) {
        cout << "NO" << endl;
    } else {

        bool b = true;

        for(int i = 0; i < s.length() && b; ++i){
            if(s[i] != t[t.length() - 1 - i]) b = false;
        }

        if(b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
