
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

    int q, a, b, f;

    char c, d, e;

    cin >> q;
    cin.ignore();

    while(q--) {
        scanf("%c=%d %c=%d\n", &c, &a, &d, &b);    
   
        if(c == 'D') {
            if(d == 'T') {
                e = 'V';
            } else {
                e = 'T';
            } 
            f = a / b;
        } else if(c == 'T') {
            if(d == 'D') {
                e = 'V';
                f = b / a; 
            } else {
                e = 'D'; 
                f = a * b;
            } 
        } else {
            if(d == 'D') {
                e = 'T';
                f = b / a;
            } else {
                e = 'D';
                f = a * b;
            } 
        }

        printf("%c=%d\n", e, f);
    }

    return 0;
}
