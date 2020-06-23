
#include <iostream>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q, n;
    cin >> q;

    map<long long, int> m;

    long long p;

    for(int i = 0; i < q; ++i) {
        cin >> n;

        for(int j = 0; j < 4*n; ++j) {
            cin >> p;
            ++m[p];
        }

        long long area = -1;
        long long temp;

        map<long long, int>::iterator bit, eit;
        
        bool b = true;

        while(m.size() >= 2 && b) {
            bit = m.begin();
            eit = m.end();
            --eit;

            if(bit->second != eit->second) b = false;
            else if(bit->second % 2 != 0) b = false;
            else {
                if(area == -1) {
                    area = bit->first * eit->first; 
                } else {
                    temp = bit->first * eit->first;
                    if(temp != area) b = false;
                }
                m.erase(bit->first);
                m.erase(eit->first);
            }
        }

        if(m.size() > 0) {
            bit = m.begin();

            if(bit->second % 4 == 0) {
                if(area != -1 && bit->first * bit->first != area) b = false;
            } else {
                b = false;
            }
        }

        if(b) cout << "YES\n";
        else cout << "NO\n";
        
        m.clear();
    }

    return 0;
}
