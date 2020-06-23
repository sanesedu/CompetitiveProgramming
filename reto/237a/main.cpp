
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

bool polidiv(long long n, int l) {
    
    if(l == 1) return true; //digit always divisible by 1
    else return polidiv(n/10, l-1) && (n % l == 0); //recurse + divisible by its position
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    long long n;

    while(cin >> n) {
        if(polidiv(n, to_string(n).length())) cout << "POLIDIVISIBLE\n";
        else cout << "NO POLIDIVISIBLE\n"; 
    }

    return 0;
}
