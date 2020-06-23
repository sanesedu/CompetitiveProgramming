
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

map<string, int> mp;

int getcount(string a, string b) {
    if(!mp.count(a) || !mp.count(b)) return INT_MAX;
    return mp[a] + mp[b];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, cost;
    cin >> n;

    string vits;

    fori(i, n) {
        cin >> cost >> vits;
        sort(all(vits));

        if(mp.count(vits) == 0) mp[vits] = cost;
        else mp[vits] = min(mp[vits], cost);    
    }
    
    int res = INT_MAX;

    if(mp.count("A") && mp.count("B") && mp.count("C")) {
        res = mp["A"] + mp["B"] + mp["C"];
    }

    if(mp.count("ABC")) res = min(res, mp["ABC"]);

    res = min(res, getcount("AB", "C"));
    res = min(res, getcount("A", "BC"));
    res = min(res, getcount("AC", "B"));
    res = min(res, getcount("AB", "BC"));
    res = min(res, getcount("AC", "BC"));
    res = min(res, getcount("AC", "AB"));
    
    if(res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}
