
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

    while(cin >> n) {
        if(n == 0) break;
    
        vector<int> arr;

        arr.pb(n);

        while(cin >> n) {
            if(n == 0) break;
            arr.pb(n);
        }
        
        sort(all(arr));

        int s = arr.size();

        vector<int> res(s);

        int index = 0;

        bool flag = (s % 2) == 1;

        for(int i = 0; i < s && flag; i += 2) {
            if(i == s - 1) {
                res[index] = arr[i];
            } else if(arr[i] == arr[i+1]) {
                res[index] = arr[i];
                res[s-1-index] = arr[i+1];
                ++index;
            } else {
                flag = false;
            }
        }
       
        if(flag) {
            fori(i, s) {
                if(i) cout << " ";
                cout << res[i];
            }
            cout << endl;
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}
