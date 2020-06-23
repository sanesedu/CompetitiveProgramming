
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, m, q;
    cin >> n >> m >> q;

    long long g = __gcd(n, m); //number of sectors

    long long ng = n / g; //number of inner elements per sector
    long long mg = m / g; //number of outer elements per sector

    long long sx, sy, ex, ey;

    for(long long i = 0; i < q; ++i) {

        cin >> sx >> sy >> ex >> ey;

        long long a, b;

        if(sx == 1) { //inner
            a = (sy + ng - 1) / ng; 
            //[1, ng] are in first sector, so if sy = ng, if we didn't have the -1 it would be in the 2ng/ng = 2 sector
        } else { //outer
            a = (sy + mg - 1) / mg;
        }
        
        if(ex == 1) { //inner
            b = (ey + ng - 1) / ng;
        } else { //outer
            b = (ey + mg - 1) / mg;
        }

        if(a == b) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
