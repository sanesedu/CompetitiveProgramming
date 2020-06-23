
#include <iostream>

using namespace std;

string up(string s){
    for(int i = 0; i < s.length(); ++i){
        s[i] = toupper(s[i]);
    }
    return s;
}

string mod(string s){
    char t;
    for(int i = 0; i < s.length(); ++i){
        t = tolower(s[i]);
        if(t == s[i]) s[i] = toupper(s[i]);
        else s[i] = t;
    }
    return s;
}

int main() {

    string word, check;

    cin >> word;

    check = up(word);
    
    if(check == word){
        word = mod(word);
    } else {
        check[0] = tolower(check[0]);
        if(check == word){
            word = mod(word);
        } 
    }

    cout << word << endl;

    return 0;
}
