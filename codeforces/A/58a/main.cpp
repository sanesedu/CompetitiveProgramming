
#include <iostream>

using namespace std;

int main() {
 
    string s;

    cin >> s;

    int c = 0;

    char arr[5] = {'h', 'e', 'l', 'l', 'o'};

    int l = s.length();

    for(int i = 0; i < l && c < 5; ++i){
        if(s.at(i) == arr[c]) c++;
    }

    if(c == 5) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;   
}
