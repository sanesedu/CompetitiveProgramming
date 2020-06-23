
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

set<long long> fact(long long x) {

    set<long long> v;
    
    long long count = 1;

    v.insert(x);

    while(x % 2 == 0) {
        x /= 2;
        v.insert(x);
        v.insert(pow(2, count));
        ++count;
    }

    for(long long i = 3; i <= sqrt(x) && i < x && x > 1; i += 2) {
        count = 1;
        while(x % i == 0) {
            x /= i;
            v.insert(x);
            v.insert(pow(i, count));
            ++count;
        }
    }

    set<long long>::iterator it;

    for(it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;

    return v;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, temp;
    cin >> n;

    vector<long long> numbers;

    for(long long i = 0; i < n; ++i) cin >> temp, numbers.push_back(temp);

    sort(numbers.begin(), numbers.end());

    set<long long> factors = fact(numbers[0]);

    set<long long>::iterator it;
    vector<long long>::iterator fit;

    bool common = false;

    long long res = 1;

    for(it = factors.begin(); it != factors.end(); ++it) {

        common = true;
        
        for(fit = numbers.begin(); fit != numbers.end() && common; ++fit) {
            common = (*fit % *it == 0);
        }

        if(common) ++res;
    }

    cout << res << endl;

    return 0;
}
