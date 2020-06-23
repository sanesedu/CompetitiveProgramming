
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
    
    int n;
    cin >> n;

    string arr[n] = {};

    bool m = false;

    fori(i, n) {
        cin >> arr[i];
        if(!m) {
            if(arr[i][0] == 'O' && arr[i][1] == 'O') {
                arr[i][0] = '+';
                arr[i][1] = '+';
                m = true;
            }

            if(!m && arr[i][3] == 'O' && arr[i][4] == 'O') {
                arr[i][3] = '+';
                arr[i][4] = '+';
                m = true;
            }
        }
    }
    
    if(m) {
        cout << "YES\n";
        fori(i, n) {
            cout << arr[i] << "\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
