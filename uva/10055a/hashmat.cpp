#include <iostream>

using namespace std;

int main(){

    long a, b;
    string s;

    while(getline(cin, s)){
        
        a = stol(s.substr(0, s.find(" ")));
        b = stol(s.substr(s.find(" ") + 1, s.length()));

        cout << abs(b - a) << endl;
    }

    return 0;
}
