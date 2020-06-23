
#include <iostream>

using namespace std;

int main() {

    string word;

    cin >> word;

    if(word.find('H') != string::npos || word.find('Q') != string::npos || word.find('9') != string::npos){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
