
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long i, temp;

    cin >> n >> i;

    map<long long, long long> m;

    int diffs = 0;

    for(int i = 0; i < n; ++i){
        cin >> temp;
        if(m.find(temp) == m.end()){
            ++diffs;
            m[temp] = 1;
        } else {
            ++m[temp];
        }
    }

    long long bits_needed = 0;

    long long count = 1;

    while(diffs > count){
        ++bits_needed;
        count *= 2;
    }
    
    bits_needed *= n;

    long long bits_avail = i * 8;
    
    int mod = diffs;

    while(bits_avail < bits_needed){

        --diffs;

        bits_needed = 0;

        count = 1;

        while(diffs > count){
            ++bits_needed;
            count *= 2;
        }

        bits_needed *= n;
    }

    mod -= diffs;

    int res = 0;

    map<long long, long long>::iterator l, r;

    long long minim;

    for(int i = 0; i < mod; ++i){
        l = m.begin();
        r = m.end();
        --r;
        minim = min(l->second, r->second);
        res += minim;
        if(minim == l->second) m.erase(l);
        else m.erase(r);
    }

    cout << res << "\n";

    return 0;
}
