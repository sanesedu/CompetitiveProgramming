
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

tuple<bool, bool, bool, bool> lr[10] = {{1, 1, 1, 1}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}, {1, 0, 0, 1}, {1, 0, 1, 1}, {0, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 0, 1}};
tuple<bool, bool, bool> umd[10] = {{1, 0, 1}, {0, 0, 0}, {1, 1, 1}, {1, 1, 1}, {0, 1, 0}, {1, 1, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 1, 1}};

void solve(int s, string n) {
  
    bool lu, ru, ld, rd, u, m, d;

    bool t1, t2, t3;

    int len = n.length();

    for(int i = 0; i < 2*s + 3; ++i) {
        for(int j = 0; j < len; ++j) {
            tie(lu, ru, ld, rd) = lr[n[j] - '0'];
            tie(u, m, d) = umd[n[j] - '0'];
            
            if(i == 0 || i % (s+1) == 0) {
                if(i == 0) t1 = u;
                else if(i == s + 1) t1 = m;
                else t1 = d;
                
                cout << " "; 
                
                fori(k, s) {
                    if(t1) cout << "-";
                    else cout << " ";
                }

                cout << " ";

            } else {
                if(i > s+1) {
                    t2 = ld;
                    t3 = rd;
                } else {
                    t2 = lu;
                    t3 = ru;
                }
                
                if(t2) cout << "|";
                else cout << " ";
                
                fori(k, s) cout << " ";
                
                if(t3) cout << "|";
                else cout << " ";
               
            }
            if(j != len-1) cout << " ";
        } 
        cout << "\n";
    }
    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int s;
    string n;

    while(cin >> s >> n) {
        if(s == 0 && n == "0") break;
        solve(s, n);
    }

    return 0;
}
