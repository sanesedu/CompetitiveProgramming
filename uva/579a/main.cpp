
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {

    double h, m, res;

    while(scanf("%lf:%lf", &h, &m)) {
       
        if(h == 0 && m == 0) break;

        h = h * 30 + (m/60) * 30;
        m *= 6;
        
        res = h - m;

        if(res < 0) res *= -1;
        
        if(res > 180) res = 360 - res;

        printf("%.3f\n", res);
    }

    return 0;
}
