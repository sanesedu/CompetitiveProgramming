
#include <bits/stdc++.h>

using namespace std;

long long diff(vector<long long> &prev, vector<long long> &curr) {
    
    vector<long long>::iterator pit, cit;

    sort(curr.begin(), curr.end());

    long long res;

    for(pit = prev.begin(), cit = curr.begin(); pit != prev.end() && cit != curr.end(); ++pit, ++cit) {
        if(*pit != *cit) {
            res = *pit;
            prev.erase(pit);
            curr.clear();
            return res;
        }
    }

    res = *pit;
    prev.erase(pit);
    curr.clear();

    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long temp;

    cin >> n;

    vector<long long> prev, curr;

    for(int i = 0; i < n; ++i) {
        cin >> temp;
        prev.push_back(temp);
    }
   
    sort(prev.begin(), prev.end());

    for(int j = 1; j <= 2; ++j){
        for(int i = 0; i < n - j; ++i) {
            cin >> temp;
            curr.push_back(temp);
        }

        cout << diff(prev, curr) << "\n";
    }

    return 0;
}
