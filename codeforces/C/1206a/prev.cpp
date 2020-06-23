
#include <iostream>

using namespace std;

long long size = 1e6;

long long dp[size][size];
bool vis[size][size];

long long goal;

long long sub(long long pos, long long sum, int arr[], int m, vector<int> v) {

    if(pos == m) {
        if(sum == goal || sum == goal + 1) {
            return 1;
        } else {
            return 0;
        }
    }

    if(vis[pos][sum]) {
        return dp[i][sum];
    }

    vis[pos][sum] = true;

    dp[pos][sum] = sub(pos+1, sum + arr, m) + sub(pos+1, sum, arr, m);

    return dp[i][sum];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    long long prev = 1;
    long long sum = 1 + 2*n;

    vector<long long> v;

    v.push_back(1);
    v.push_back(2*n);

    long long goal = (2*n)*(2*n-1) /2;

    for(long long i = 2; i < 2*n; ++i) {
        
    }

    return 0;
}
