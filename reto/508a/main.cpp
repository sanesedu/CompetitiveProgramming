
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
    
    int n, x, y;

    while(cin >> n) {
        if(n == 0) break;
        
        map<int,int> m;
        
        fori(i, n) {
            cin >> x >> y;
           
            if(x - y < 0) m[0]++;
            else m[x-y]++;
            
            m[x+y+1]--;
        }
        
        int res = 0;
        int sum = 0;

        map<int, int>::iterator it;

        for(it = m.begin(); it != m.end(); ++it) {
            sum += it->second;      
            res = max(res, sum);
        } 
        
        cout << res << endl;

    }

    return 0;
}
