
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int solve(vector<pair<int, int>> arr, int index, int cost, int goal) {
    
    if(goal == 0) return cost;
    
    if(index >= (int) arr.size()) return INT_MAX;

    int res = INT_MAX;

    if(arr[index].second > goal) { //ignore it
        if(goal & arr[index].second) return min(cost + arr[index].first, solve(arr, index+1, cost, goal));
        else res = solve(arr, index + 1, cost, goal); 
    } else {
        res = min(solve(arr, index+1, cost + arr[index].first, goal - arr[index].second), solve(arr, index+1, cost, goal));
    }
    
    return res;
}

int calc_vits(string s) {
    
    int res = 0;

    fori(i, s.length()) {
        res += (s[i] - 'A' + 1); //'A'=1, 'B'=2, 'C'=4 -> goal sequence "ABC"=7
        if(s[i] == 'C') ++res;
    }
    
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int n, cost;
    cin >> n;

    string vits;

    vector<pair<int, int>> arr(n);

    fori(i, n) {
        cin >> cost >> vits;
        arr[i] = {cost, calc_vits(vits)};
    }

    int res = solve(arr, 0, 0, 7);

    if(res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}
