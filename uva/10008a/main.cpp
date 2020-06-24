
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);
    
    int n, len;
    cin >> n;
    cin.ignore();

    map<char, int> freq;

    string line;

    while(n--) {
        getline(cin, line);
        
        len = line.length();
    
        fori(i, len) {
            if(isalpha(line[i])) {
                ++freq[toupper(line[i])];
            }
        }
    }
   
    vector<pair<char, int>> res;

    map<char, int>::iterator it;

    for(it = freq.begin(); it != freq.end(); ++it) {
        res.pb({it->first, it->second});
    }

    sort(all(res), cmp);
    
    vector<pair<char, int>>::iterator jit;

    for(jit = res.begin(); jit != res.end(); ++jit) {
        cout << jit->first << " " << jit->second << endl;
    }

    return 0;
}
