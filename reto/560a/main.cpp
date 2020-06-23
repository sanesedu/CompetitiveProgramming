
#include <bits/stdc++.h>

using namespace std;

long long solve(vector<int> arr, int n) {
 
    stack<pair<int, int>> st;
    st.push({arr[0], 0});
    
    long long res = 0;

    pair<int, int> t;

    for(int i = 1; i < n; ++i) {
        t = st.top();
        while(!st.empty() && t.first < arr[i]) {
            res += (i - t.second);
            st.pop();
            if(!st.empty()) t = st.top();
        }
        st.push({arr[i], i});
    } 

    while(!st.empty()) {
        t = st.top();
        res += (n - t.second);
        st.pop();
    }

    return res; 
} 

int main() {

    int n;

    long long res;

    while(cin >> n) {
        if(n == 0) break;

        vector<int> arr(n);

        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        
        res = solve(arr, n);    
    
        cout << res << "\n";
    }

    return 0;
}
