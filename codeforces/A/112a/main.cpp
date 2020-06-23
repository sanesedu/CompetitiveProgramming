
#include <iostream>

using namespace std;

int main() {
    
    string s, t;

    cin >> s >> t;
    
    int res = 0;

    int l = s.length();

    for(int i = 0; i < l; ++i){
        s[i] = tolower(s[i]);
        t[i] = tolower(t[i]);
    }

    if(s < t){
        res = -1;
    } else if(s > t){
        res = 1;
    } else {
        res = 0;
    }

    cout << res << endl;

    return 0;
}
