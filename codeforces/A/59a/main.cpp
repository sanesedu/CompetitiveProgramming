
#include <iostream>

using namespace std;

int main() {

    string s;

    cin >> s;

    int l, u;
    
    l = u = 0;

    char temp;

    for(int i = 0; i < s.length(); ++i){
        temp = tolower(s[i]);
        if(temp == s[i]) ++l;
        else ++u;
    }

    if(l >= u){
        for(int j = 0; j < s.length(); ++j){
            s[j] = tolower(s[j]);
        }
    } else {
        for(int k = 0; k < s.length(); ++k){
            s[k] = toupper(s[k]);
        }
    }

    cout << s << endl;

    return 0;
}
