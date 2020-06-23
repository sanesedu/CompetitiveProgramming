
#include <iostream>
#include <string>

using namespace std;

bool isVowel(string c){

    return c == "a" || c == "o" || c == "e" || c == "y" || c == "u" || c == "i";
}

int main() {
    
    string st, res;
    char c;

    res = "";

    cin >> st;

    int l = st.length();

    for(int i = 0; i < l; ++i){

        c = tolower(st.at(i));
  
        if(!isVowel(string(1, c))){
            res += ".";
            res += c;
        }
    }

    cout << res << endl;

    return 0;
}
