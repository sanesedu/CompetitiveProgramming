
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

#define NUM 210
#define SUM 30 

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

ll memo[NUM][NUM][SUM];
ll arr[NUM];
    
int n, q, d, m;

ll solve(int index, int sum, int left) {
    if(sum == 0 && left == 0) return 1; 
    if(sum != 0 && left == 0) return 0;

    if(index == n) return 0;
    if(memo[index][sum][left] != -1) return memo[index][sum][left];

    memo[index][sum][left] = solve(index+1, (sum + arr[index]) % d, left-1) + solve(index+1, sum, left);
    
    return memo[index][sum][left];
}

int main() {

    int is = 0;

    while(cin >> n >> q) {
        if(n == 0 && q == 0) break;
        
        fori(i, n) {
            cin >> arr[i];
        }
        
        printf("SET %d:\n", ++is);
    
        fori(j, q) {
            cin >> d >> m;
            memset(memo, -1, sizeof(memo));
            printf("QUERY %d: %lld\n", j+1, solve(0, 0, m));
        }
    } 

    return 0;
}
