
#include <bits/stdc++.h>

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fori(i, n) for(int i = 0; i < (int)(n); ++i)
#define forid(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define forl(i, n) for(long long i = 0; i < (long long)(n); ++i)
#define forld(i, n) for(long long i = (long long)(n) - 1; i >= 0; --i)
#define forb(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

int z, i, m, l;

int f(int s) {
    
    return (s * z + i) % m;
}

pair<int, int> floydCycleFinding(int s) {
   
    int tortoise = f(s);
    int hare = f(f(s)); 

    //finding k * mu    
    while(tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    
    int mu = 0;
    hare = s;
    
    //finding mu
    while(tortoise != hare) {
        tortoise = f(tortoise);
        hare = f(hare);
        ++mu;
    }

    //finding lambda

    int lambda = 1;
    hare = f(tortoise);

    while(tortoise != hare) {
        hare = f(hare);
        ++lambda;
    }

    return make_pair(mu, lambda);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(10);

    int index = 1;

    while(cin >> z >> i >> m >> l) {
        if(z == 0 && i == 0 && m == 0 && l == 0) break; 
   
        pair<int, int> res = floydCycleFinding(l);

        cout << "Case " << index << ": " << res.second << endl;
        ++index;
    }

    return 0;
}
