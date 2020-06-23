
#include <iostream>

using namespace std;

int main() {
    
    int n = 0;

    cin >> n;

    string s;

    int l;

    for(int i = 0; i < n; ++i){
        
        cin >> s;

        l = s.length();

        if(l <= 10){
            cout << s << endl;
        } else {
            cout << s.at(0) << l-2 << s.at(l-1) << endl;
        }
    }

    return 0;
}
