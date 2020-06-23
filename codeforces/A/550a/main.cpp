
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;

    cin >> s;

    size_t i = s.find("AB");
    size_t j = s.find("BA");

    while(i != string::npos && j != string::npos) {
        if(j + 1 < i) {
            cout << "YES\n";
            return 0;
        } else if(j > i + 1) {
            cout << "YES\n";
            return 0;
        } 

        j = s.find("BA", j + 1);
    } 
    
    j = s.find("BA");

    while(i != string::npos && j != string::npos) {
        if(j + 1 < i) {
            cout << "YES\n";
            return 0;
        } else if(j > i + 1) {
            cout << "YES\n";
            return 0;
        } 

        i = s.find("AB", i + 1);
    }

    cout << "NO\n";

    return 0;
}
