
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(int i = 0; i < (int)(n); ++i)
#define forld(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int main() {

    int n;

    while(cin >> n) {

        vector<pair<int, int>> res;

        for(int k = n + 1; k <= 2*n; ++k) {
            if((n * k) % (k - n) == 0) {
                res.pb({(n*k) / (k - n), k});
            } 
        }

        cout << res.size() << endl; 

        vector<pair<int, int>>::iterator it;
       
        for(it = res.begin(); it != res.end(); ++it) {
            printf("1/%d = 1/%d + 1/%d\n", n, it->first, it->second);
        } 
    }

    return 0;
}
