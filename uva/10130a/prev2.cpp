
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forid(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(long long i = (long long)(a); i <= (long long)(b); ++i)

using namespace std;

long long t, n, p, w, g, h;

long long memo[1010][40];

long long price[1010];
long long weight[1010];

long long kps(long long kind, long long w) {

    if(w == 0) return 0;

    if(kind >= n) return 0;

    if(memo[kind][w] != -1) return memo[kind][w];

    if(weight[kind] > w) {
        return (memo[kind][w] = kps(kind + 1, w));
    } else {
        return (memo[kind][w] = max(kps(kind + 1, w), price[kind] + kps(kind + 1, w - weight[kind]))); 
    }
}

int main() {

    scanf("%d", &t);

    while(t--) {
        
        scanf("%d", &n);
        
        fori(i, n) {
            scanf("%d %d", &price[i], &weight[i]);
        }

        memset(memo, -1, sizeof(memo));

        scanf("%d", &g);

        long long res = 0;
        
        while(g--) {
            scanf("%d", &h);
            res += kps(0, h);;
        }
       
        printf("%d\n", res);
    }

    return 0;
}
