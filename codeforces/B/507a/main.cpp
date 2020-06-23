
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
    
    long long r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >>y2;

    long double dx = (x2-x1) * (x2-x1);
    long double dy = (y2-y1) * (y2-y1);
    long double res = sqrt(dx + dy);

    cout << ceil(res/(2.*r)) << endl;

    return 0;
}
