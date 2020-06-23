
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    string s;

    cin >> s;

    vector<int> v;

    int l = s.length();

    for(int i = 0; i < l; i+=2){
        v.push_back(stoi(string(1, s[i])));
    }

    sort(v.begin(), v.end());

    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); it++){
        if(it == v.begin()){
            cout << *it;
        } else {
            cout << "+" << *it;
        }
    } 

    cout << endl;

    return 0;
}
