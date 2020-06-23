
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    string s;
    int arr[3] = {};

    fori(i, 3) {
        cin >> s;
        
        if(s[1] == '>') {
            ++arr[s[0] - 'A'];
        } else {
            ++arr[s[2] - 'A'];
        }

    }

    string res = "";

    if(arr[0] == 0) {
        res += 'A';
    } else if(arr[1] == 0) {
        res += 'B';
    } else if(arr[2] == 0) {
        res += 'C';
    }
    
    if(arr[0] == 1) {
        res += 'A';
    } else if(arr[1] == 1) {
        res += 'B';
    } else if(arr[2] == 1){
        res += 'C';
    }

    if(arr[0] == 2) {
        res += 'A';
    } else if(arr[1] == 2) {
        res += 'B';
    } else if(arr[2] == 2) {
        res += 'C';
    }
    
    if(arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) {
        cout << "Impossible\n";
    } else {
        cout << res << endl;    
    }
    return 0;
}
