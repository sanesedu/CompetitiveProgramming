
#include <iostream>

using namespace std;

int main() {

    int n;
    string s;

    cin >> n >> s;

    int arr[26] = {};

    int pos;

    for(int i = 0; i < n; ++i){
        s[i] = tolower(s[i]);
        pos = (int)s[i] - (int)'a';
        ++arr[pos];
    }

    bool b = true;

    for(int i = 0; i < 26 && b; ++i){
        if(arr[i] == 0) b = false;
    }

    if(b) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
