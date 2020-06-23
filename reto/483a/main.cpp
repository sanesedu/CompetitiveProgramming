
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

    int cases;
    cin >> cases;

    while(cases--) {
        
        int h1, m1, s1, h2, m2, s2, total, curr;

        scanf("%2d:%2d:%2d %2d:%2d:%2d", &h1, &m1, &s1, &h2, &m2, &s2);
        scanf("%d %d", &total, &curr);

        int first = h1*3600 + m1*60 + s1;
        int second = h2*3600 + m2*60 + s2;

        if(first > second) {
            second += 24*3600;
        }

        int diff = (second - first)/(total - 1);

        --curr;

        diff *= curr; 
        
        diff += first;
        
        s2 = diff % 60;
        m2 = (diff/60) % 60;
        h2 = (diff/3600) % 24;

        printf("%02d:%02d:%02d\n", h2, m2, s2);

    }

    return 0;
}
