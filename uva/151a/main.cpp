
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int solve(int n, int m) {
    
    queue<int> q;

    for(int i = 1; i <= n; ++i) q.push(i);

    while(q.size() > 1) {
        q.pop();

        fori(i, m-1) {
            q.push(q.front());
            q.pop();
        }
    }

    return q.front();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, m;

    while(cin >> n) {
        
        if(n == 0) break;

        m = 1;

        while(true) {
            if(solve(n, m) == 13) break;
            ++m;
        }

        cout << m << endl;
    }

    return 0;
}
