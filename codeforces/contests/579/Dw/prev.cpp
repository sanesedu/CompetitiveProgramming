
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void kmp_array(string pat, int l1, int* arr) {

    int i = 0;

    arr[0] = 0;

    int j = 1;

    while(i < l1) {
        if(pat[i] == pat[j]) {
            ++i;
            arr[j] = i;
            ++j;
        } else {
            if(i != 0) {
                i = arr[i - 1];
            } else {
                arr[j] = 0;
                ++j;
            }
        }
    }
}

int kmp_search(string pat, string txt) {

    int l1 = pat.length();
    int l2 = txt.length();

    int arr[l1] = {};
    
    kmp_array(pat, l1, arr);

    int t, p;
    t = p = 0;

    while(t < l2) {
        if(txt[t] == pat[p]) {
            ++p;
            ++t;
        } 

        if(p == l1) { //pattern completely found
            return t - p;
        } else if(t < l2 && pat[p] != txt[t]) {
            if(p != 0) {
                p = arr[p-1];
            } else {
                ++t;
            }
        }

    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    int i = kmp_search(t, s);

    int j = s.length() - (i + t.length());

    int res = max(i, j);

    cout << res << endl;

    return 0;
}
