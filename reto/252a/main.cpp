
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

    string line;

    while(getline(cin, line)) {
        if(line == "XXX") break;
        
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        
        char x, y;

        bool flag = false;

        for(int i = 0; i < (int)line.length()/2; ++i) {
            x = tolower(line[i]);
            y = tolower(line[line.length() - 1 -i]);
            if(x != y) {
                flag = true;
                break;
            }
        }
        
        if(flag) cout << "NO\n";
        else cout << "SI\n";

    }

    return 0;
}
