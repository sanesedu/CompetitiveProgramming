
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
    
    int n, t;

    while(cin >> n) {
        
        if(n == 0) break;
                
        vector<int> pos, neg;
        vector<bool> model(n, false);

        fori(i, n) {
            cin >> t;
            if(t > 0) {
                pos.pb(t);
                model[i] = true;
            } else {
                neg.pb(t);
            }
        }

        sort(all(pos), greater<int>());
        sort(all(neg));
        
        fori(i, n) {
            if(model[i]) {
                cout << pos.back();
                pos.pop_back();
            } else {
                cout << neg.back();
                neg.pop_back();
            }
            if(i != n-1) cout << " ";
        }
        cout << endl; 
    }

    return 0;
}
