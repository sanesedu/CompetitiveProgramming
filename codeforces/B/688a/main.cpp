
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //there is a lovely palindrome for each natural number, itself and then its reverse

    string s;

    cin >> s;
    cout << s; 

    reverse(s.begin(), s.end());
    cout << s << "\n";

    return 0;
}
