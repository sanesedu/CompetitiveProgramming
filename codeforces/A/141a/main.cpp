
#include <iostream>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b, c;

    cin >> a >> b >> c;

    if(a.length() + b.length() != c.length()){
        cout << "NO\n";
    } else{

        int res = 0;

        for(int i = 0; i < a.length(); ++i){
            if(c.find(a[i]) != string::npos){
                c[c.find(a[i])] = '7';
                a[i] = '7';
                ++res;
            }    
        }

        for(int i = 0; i < b.length(); ++i){
            if(c.find(b[i]) != string::npos){
                c[c.find(b[i])] = '7';
                b[i] = '7';
                ++res;
            }    
        }

        if(res == c.length()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
