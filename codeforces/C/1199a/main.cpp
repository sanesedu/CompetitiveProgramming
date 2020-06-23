
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long I, temp;

    cin >> n >> I;
    
    map<long long, long long> m;

    vector<long long> v, values;

    for(int i = 0; i < n; ++i){
        cin >> temp;
        ++m[temp];
    }

    long long k = (8*I) / n;

    long long K = pow(2, min((long long) 20, k));

    map<long long, long long>::iterator it;

    for(it = m.begin(); it != m.end(); ++it){
        v.push_back(it->first);
        values.push_back(it->second);
    }
    
    //after inserting elements in the map, and then pushing firsts to v, now v contains all different elements in input

    if(K > v.size()) {
        cout << 0 << "\n";
    } else {
        
        long long sum = 0;

        for(long long i = 0; i < K; ++i) sum += values[i]; //base prefix sum for comparison with rest
        
        long long val = n - sum; //number of values to be changed

        long long res = val;

        long long first, last;

        first = 0;
        last = K - 1;

        while(last < v.size() - 1){ //rest of prefix sums
            ++last;
            ++first;

            val = val - values[last] + values[first-1]; //remove new value from sum of values to be changed and then add new value to be changed
            if(val < res) res = val; //we take the smallest number of values to be modified
        }

        cout << res << "\n";

    }

    return 0;
}
