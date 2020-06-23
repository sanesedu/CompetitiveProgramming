
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

const int mod = 1e9 + 7;
 
int dp[100][2]; //[total weight][edge >= d] = number of ways
 
void add(int &a, int b) { //addition % mod
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}
 
int main() {
    
    int n, k, d;
    cin >> n >> k >> d;

    dp[0][0] = 1; 
    dp[0][1] = 0;
    
    forb(i, 1, n) { //for each value until n
        
        dp[i][0] = dp[i][1] = 0; //initialize number of ways to 0
        
        forb(j, 1, k) { //for each edge weight
            
            if(i-j < 0) break; //not a valid value for a total weight
            
            if(j < d) { //edge < d -> currently not valid way
                add(dp[i][0], dp[i-j][0]); //add to d not found
                add(dp[i][1], dp[i-j][1]); //add to d found 
            } else {
                add(dp[i][1], dp[i-j][0]); //add d not found, to now found
                add(dp[i][1], dp[i-j][1]); //add d found, to now found
            }
        }
    }
    
    cout << dp[n][1] << endl; //number of ways of obtaining total weight n with edge >= d
    
    return 0;
}
