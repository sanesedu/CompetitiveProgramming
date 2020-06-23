
#include <iostream>

using namespace std;

int main() {
    
    string s;

    cin >> s;

    int l = s.length();
    int arr[26] = {0};
    int res = 0;

    for(int i = 0; i < l; ++i){
        arr[s[i] - 97]++;
    }

    for(int j = 0; j < 26; ++j){
        if(arr[j] > 0) res++;
    }

    if(res % 2 == 0){
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }

    return 0;
}
