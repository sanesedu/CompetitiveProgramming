
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t, n, m, k;
    cin >> t;

    for(long long i = 0; i < t; ++i) {
        cin >> n >> m >> k;
    
        long long temp, prev;

        bool res = true;

        cin >> prev;

        for(long long j = 1; j < n; ++j) {
            cin >> temp;
            if(prev >= temp) {
                m += (prev - temp); //we add max number blocks
                prev = temp;

                if(prev >= k) m += k;
                else m += prev;

            } else {
                if((temp - prev) > k) {
                    m -= ((temp - prev) - k); //we remove min number blocks
                    if(m < 0) res = false;
                } else { 
                    if(prev - (prev - (temp - k)) >= 0) {
                        m += (prev - (temp - k)); 
                    } else {
                        m += prev;
                    }
                } 
            }
            prev = temp;
        }

        if(res) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
