
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

    map<char, int> m;
    m['('] = 0;
    m[')'] = 1;
    m['['] = 2;
    m[']'] = 3;
    m['{'] = 4;
    m['}'] = 5;

    string line;
    int n;
    bool flag;

    while(getline(cin, line)) {
        
        stack<int> s;

        flag = true;
        
        n = line.length();

        for(int i = 0; i < n && flag; ++i) {
            if(m.find(line[i]) != m.end()) {
                if(s.empty()) {
                    if(m[line[i]] % 2 == 0) s.push(m[line[i]]);
                    else flag = false;
                } else {
                    if(m[line[i]] % 2 == 0) s.push(m[line[i]]);
                    else {
                        if(m[line[i]] - s.top() == 1) s.pop();
                        else flag = false;
                    }
                }
            }
        }
        
        if(!flag || !s.empty()) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
