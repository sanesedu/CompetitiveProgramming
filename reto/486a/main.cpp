
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int gcd(int a, int b) {

    if(b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int lcm(int a, int b) {

    return (a/gcd(a, b)) * b;
}

int main() {

    int n, a, b;

    while(1) {

        scanf("%d", &n);

        if(n == 0) {
            break;
        }

        int num[n];
        int den[n];

        int lc = 1;

        fori(i, n) {
            scanf("%d/%d", &a, &b);
            num[i] = a;
            den[i] = b;

            lc = lcm(b, lc);
        }

        int total = 0;

        fori(i, n) {
            total += (lc/den[i]) * num[i];
        }

        int res = lc - total;

        printf("%d\n", res);

    }

    return 0;
}
