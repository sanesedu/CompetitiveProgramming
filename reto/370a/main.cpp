
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

    int q, a, b;
    scanf("%d", &q);

    while(q--) {
        scanf("%d-%d", &a, &b); 
        
        if((abs(a - b) == 1) && (min(a, b) % 2 == 0)) printf("SI\n");
        else printf("NO\n");
    }

    return 0;
}
