
#include <iostream>

using namespace std;

int main() {
    
    string s;
    int res = 0;

    int l;
    
    cin >> l;

    cin >> s;

    char temp = s[0];

    for(int i = 1; i < l; ++i){
        if(s[i] == temp){
            res++;
        } else {
            temp = s[i];
        }
    }

    cout << res << endl;

    return 0;
}
